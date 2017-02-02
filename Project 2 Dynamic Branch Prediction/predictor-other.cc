#include "predictor.h"
#include <bitset>
#include <iostream>

#define TwelveBitMask 4095
#define ElevenBitMask 2047
#define op_bimodal_table_entries 2048

#define NumTagTable 4
#define PCbitmask 1023
#define Entrypertable 2048
#define HistoryLength 11

static unsigned int bimodal_prediction_table[4096];
static unsigned int BHT[512];
static unsigned int PHT[8][64];

// Open-ended predictor
struct last_pred{
	bool flag;
	int table;
	int entry;
	bool pred;
};

struct Tage_entry{
	unsigned int pred;
	unsigned int tag;
	unsigned int u;
};

struct Compress_history{
	unsigned int L_history;
	unsigned int L_tag;
	unsigned int Comphis;
};


static unsigned int OP_BT[op_bimodal_table_entries];

static bool bi_pred;

static bitset<100> GHR;

struct Compress_history CompHist[NumTagTable];

struct Tage_entry Tage[NumTagTable][Entrypertable];

struct last_pred lp;








/////////////////////////////////////////////////////////////
// 2bitsat
/////////////////////////////////////////////////////////////


void InitPredictor_2bitsat() {

    int i;
    for(i = 0; i < 4096; i++){
      bimodal_prediction_table[i] = 1; //weakly not taken
    }
}

bool GetPrediction_2bitsat(unsigned int PC) {

	unsigned int index = PC & TwelveBitMask;

	if(bimodal_prediction_table[index] <= 1)
		return NOT_TAKEN;
	else
		return TAKEN;
}

void UpdatePredictor_2bitsat(unsigned int PC, bool resolveDir, bool predDir, unsigned int branchTarget) {

	unsigned int index = PC & TwelveBitMask;
	
	if(resolveDir == predDir){
		if(predDir == TAKEN && bimodal_prediction_table[index] < 3)
			bimodal_prediction_table[index]++;
		else if(predDir == NOT_TAKEN && bimodal_prediction_table[index] > 0)
			bimodal_prediction_table[index]--;
	}
	else{
		if(predDir == TAKEN && bimodal_prediction_table[index] > 0)
			bimodal_prediction_table[index]--;
		else if(predDir == NOT_TAKEN && bimodal_prediction_table[index] < 3)
			bimodal_prediction_table[index]++;
	}
	return;
}

/////////////////////////////////////////////////////////////
// 2level
/////////////////////////////////////////////////////////////

void InitPredictor_2level() {

	int a;
	for(a = 0; a < 512; a++){
		BHT[a] = 0;
	}
	int i,j;
	for(i = 0; i < 8; i++){
		for(j = 0; j < 64; j++){
			PHT[i][j] = 1; //weakly not taken
		}
	}
}

bool GetPrediction_2level(unsigned int PC) {

	unsigned int ThreeBitMask = 0x00000007;
	unsigned int NineBitMask = 0x00000FF8;
	unsigned int PHTindex = PC & ThreeBitMask;
	unsigned int BHTindex = (PC & NineBitMask) >> 3;

	
	if(PHT[PHTindex][BHT[BHTindex]] <= 1)
		return NOT_TAKEN;
	else
		return TAKEN;

}

void UpdatePredictor_2level(unsigned int PC, bool resolveDir, bool predDir, unsigned int branchTarget) {

	unsigned int ThreeBitMask = 0x00000007;
	unsigned int NineBitMask = 0x00000FF8;
	unsigned int PHTindex = PC & ThreeBitMask;
	unsigned int BHTindex = (PC & NineBitMask) >> 3;
	
	if(resolveDir == predDir){
		if(predDir == TAKEN && PHT[PHTindex][BHT[BHTindex]] < 3)
			PHT[PHTindex][BHT[BHTindex]]++;
		else if(predDir == NOT_TAKEN && PHT[PHTindex][BHT[BHTindex]] > 0)
			PHT[PHTindex][BHT[BHTindex]]--;
	}
	else{
		if(predDir == TAKEN && PHT[PHTindex][BHT[BHTindex]] > 0)
			PHT[PHTindex][BHT[BHTindex]]--;
		else if(predDir == NOT_TAKEN && PHT[PHTindex][BHT[BHTindex]] < 3)
			PHT[PHTindex][BHT[BHTindex]]++;
	}
	if(resolveDir)
		BHT[BHTindex] = ((BHT[BHTindex] << 1) + 1) & 0x000003F;
	else
		BHT[BHTindex] = (BHT[BHTindex] << 1) & 0x000003F;
	return;

}

/////////////////////////////////////////////////////////////
// openend
/////////////////////////////////////////////////////////////

void InitPredictor_openend() {
	
	int i;
    for(i = 0; i < op_bimodal_table_entries; i++){
      OP_BT[i] = 1; //weakly not taken
    }
	
	GHR.reset();
	
	CompHist[0].L_history = 11;
	CompHist[1].L_history = 22;
	CompHist[2].L_history = 33;
	CompHist[3].L_history = 77;



	for(int i = 0; i < NumTagTable; i++){
		CompHist[i].L_tag = HistoryLength;
		CompHist[i].Comphis = 0;
	}

}

bool GetPrediction_openend(unsigned int PC) {
	
	unsigned int BTindex = PC & ElevenBitMask;
	int i;
	
	if(OP_BT[BTindex] <= 1)
		bi_pred = NOT_TAKEN;
	else
		bi_pred = TAKEN;
	
	//check if tage match 
	
	//hashing tags
	unsigned int tag;

	tag = PC & PCbitmask;


	//hashing index
	int index[NumTagTable];


	for(i = 0; i < NumTagTable; i++){
		index[i] = CompHist[i].Comphis;
	}

	for(i = NumTagTable-1; i > -1; i--){
		if((Tage[i][index[i]].tag == tag) && (Tage[i][index[i]].u > 0)){
			lp.pred = Tage[i][index[i]].pred > 1;
			lp.table = i;
			lp.entry = index[i];
			lp.flag = true;
			return lp.pred;
		}
	}

	lp.flag = false;
	return bi_pred;

}

void UpdatePredictor_openend(unsigned int PC, bool resolveDir, bool predDir, unsigned int branchTarget) {

	//Updating biomodal predction table
	unsigned int BTindex = PC & ElevenBitMask;

	if(resolveDir == bi_pred){
		if(predDir == TAKEN && OP_BT[BTindex] < 3)
			OP_BT[BTindex]++;
		else if(predDir == NOT_TAKEN && OP_BT[BTindex] > 0)
			OP_BT[BTindex]--;
	}
	else{
		if(predDir == TAKEN && OP_BT[BTindex] > 0)
			OP_BT[BTindex]--;
		else if(predDir == NOT_TAKEN && OP_BT[BTindex] < 3)
			OP_BT[BTindex]++;
		if(lp.flag == false){//bimodal mispredict, add to T0
			int newtag = PC & PCbitmask;
			int newindex = CompHist[0].Comphis;
			Tage[0][newindex].tag = newtag;
			Tage[0][newindex].u = 3;
			if(resolveDir)
				Tage[0][newindex].pred = 2;
			else
				Tage[0][newindex].pred = 1;
		}
	}
	
	//Updating Tage Table
	
	if(lp.flag){
		//update useful bit
		if(resolveDir == predDir && Tage[lp.table][lp.entry].u < 3)
			Tage[lp.table][lp.entry].u++;
		else if(resolveDir != predDir)
			Tage[lp.table][lp.entry].u--;

		//when useful bit is 0;
		if(Tage[lp.table][lp.entry].u == 0){
			if(lp.table < NumTagTable - 1){
				int newtag = PC & PCbitmask;
				int newindex = CompHist[lp.table+1].Comphis;

				Tage[lp.table+1][newindex].tag = newtag;
				Tage[lp.table+1][newindex].u = 3;
				if(resolveDir)
					Tage[lp.table+1][newindex].pred = 2;
				else
					Tage[lp.table+1][newindex].pred = 1;
			}
		}
		else{//when tage is useful
			if(resolveDir == predDir){
				if(predDir == TAKEN && Tage[lp.table][lp.entry].pred < 3)
					Tage[lp.table][lp.entry].pred++;
				else if(predDir == NOT_TAKEN && Tage[lp.table][lp.entry].pred > 0)
					Tage[lp.table][lp.entry].pred--;
			}
			else{
				if(predDir == TAKEN && Tage[lp.table][lp.entry].pred > 0)
					Tage[lp.table][lp.entry].pred--;
				else if(predDir == NOT_TAKEN && Tage[lp.table][lp.entry].pred < 3)
					Tage[lp.table][lp.entry].pred++;

			}
		}
	}
	//update GHR
	GHR = (GHR << 1);
	if(resolveDir == TAKEN){
    	GHR.set(0,1);
  	}


	for(int i = 0; i < NumTagTable; i++){

		bitset<100> temp;
		temp = GHR;
		bitset<HistoryLength> target;

		unsigned int numFolds = CompHist[i].L_history / CompHist[i].L_tag;
		unsigned int remainder = CompHist[i].L_history % CompHist[i].L_tag;


		for(unsigned int j = 0; j < numFolds; j++){
			for(unsigned int a = 0; a < CompHist[i].L_tag; a++){
				target[a] = temp[a] ^ target[a];
			}
			temp = temp >> CompHist[i].L_tag;
		}

		for(unsigned int a = 0; a < remainder; a++){
			target[a] = temp[a] ^ target[a];
		}

		CompHist[i].Comphis = target.to_ulong();

	}

}






