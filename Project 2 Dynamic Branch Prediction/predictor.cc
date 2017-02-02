#include "predictor.h"
#include <iostream>


/////////////////////////////////////////////////////////////
// 2bitsat
/////////////////////////////////////////////////////////////
char two_bit_sat[4096];

void increment (int index){
	if (two_bit_sat[index] == '0')
		two_bit_sat[index] = '1';
	else if(two_bit_sat[index] == '1')
		two_bit_sat[index] = '2';
	else
		two_bit_sat[index] = '3';
	
}

void decrement (int index) {
	if (two_bit_sat[index] == '2')
		two_bit_sat[index] = '1';
	else if (two_bit_sat[index] == '3')
		two_bit_sat[index] = '2';
	else
		two_bit_sat[index] = '0';
	
}

void InitPredictor_2bitsat() {
	int i;
	for(i=0; i<4096; i++){
		two_bit_sat[i] = '1';	
	}
}

bool GetPrediction_2bitsat(UINT32 PC) {

	int index = PC%4096;

	if (two_bit_sat[index] == '0')
		return NOT_TAKEN;
	else if(two_bit_sat[index] == '1')
		return NOT_TAKEN;
	else if(two_bit_sat[index] == '2')
		return TAKEN;
	else 
		return TAKEN;
	
}

void UpdatePredictor_2bitsat(UINT32 PC, bool resolveDir, bool predDir, UINT32 branchTarget) {

	int index = PC%4096;

	if (resolveDir == TAKEN)
		increment(index);
	else 
		decrement(index);
	
			
}

/////////////////////////////////////////////////////////////
// 2level
/////////////////////////////////////////////////////////////
unsigned int BHT[512];
unsigned int PHT[8][64];

void InitPredictor_2level() {
	int i; 
	for(i = 0; i < 512; i++){
		BHT[i] = 0;	
	}
	
	for(i =0; i< 8; i++){
		int j = 0;
		for(j=0;j<64;j++){
			PHT[i][j]=1;
		}
	}
}

bool GetPrediction_2level(UINT32 PC) {
	int BHT_index = PC & 0xFF8;
	BHT_index/=8;
	int PHT_index = PC & 7;

	
	int pt = BHT[BHT_index];
	int result = PHT[PHT_index][pt];
	if (result >= 2)
		return TAKEN;
	else
		return NOT_TAKEN;


}

void UpdatePredictor_2level(UINT32 PC, bool resolveDir, bool predDir, UINT32 branchTarget) {
	int BHT_index = PC & 0xFF8;
	BHT_index/=8;
	int PHT_index = PC & 7;
	int pt = BHT[BHT_index];
	int result = PHT[PHT_index][pt];
	
	//update the PHT with the result
	if(resolveDir == TAKEN && result<3) 
		PHT[PHT_index][pt] ++;
	else if(resolveDir == NOT_TAKEN && result>0)
		PHT[PHT_index][pt]--;
	
	//record the history/pattern
	if(resolveDir == TAKEN)
		BHT[BHT_index] = ((BHT[BHT_index]*2) + 1) & 0x3F; //Shift left by 1 and add 1. Only 6bit history
	else
		BHT[BHT_index] = (BHT[BHT_index]*2) & 0x3F; //Shift left by 1 and add 0. Only 6bit history
	

}

/////////////////////////////////////////////////////////////
// openend
/////////////////////////////////////////////////////////////
unsigned int GSHARE_BHR; //16 bit history
// unsigned int GSELECT_PHT[16384]; //bimodal PHT
// unsigned int CONTOUR_PHT[16384];
// unsigned int HASH_PHT[16384];
// unsigned int Bimodal_PHT[8192];
// unsigned int last_PHT[8192];
unsigned int GSELECT_PHT[21330]; //bimodal PHT
unsigned int CONTOUR_PHT[21330];
unsigned int HASH_PHT[21330];


void InitPredictor_openend() {
	int i;
	
	GSHARE_BHR = 0;
	for(i=0; i < 21330; i++){
		// if(i < 8192){
			// Bimodal_PHT[i] = 1;
			// last_PHT[i] = 0;
		// }
		GSELECT_PHT[i] = 1;
		CONTOUR_PHT[i] = 1;
		HASH_PHT[i] = 1;
	}
}

bool GetPrediction_openend(UINT32 PC) {
	
	int a = PC;
	int b = GSHARE_BHR;
	
	int index_select = (((PC & 0x7F) << 7) | (GSHARE_BHR & 0xFF));  //concate 7 bit adress and 8 bit history
	int index_contour = ((a+b)*(a+b+1)*(0.5)+ b); //contour pairing formula
	int index_hash = index_select ^ index_contour ^ (PC & 0x7FFF); //xor them
	
	int share_result = GSELECT_PHT[index_select%21330];
	int select_result = CONTOUR_PHT[index_contour%21330];
	int hash_result = HASH_PHT[index_hash%21330];

	int prediction = 0;
	
	//GSelect
	if(share_result >= 2){
		prediction += 1;
	}
	else
		prediction -=1;
	
	//CONTOUR
	if(select_result >= 2){
		prediction += 1;
	}
	else
		prediction -=1;
	
	//hash
	if(hash_result >= 2){
		prediction += 1;
	}
	else
		prediction -=1;
	
	
	if(prediction > 0)
		return TAKEN;
	else
		return NOT_TAKEN;
}


void UpdatePredictor_openend(UINT32 PC, bool resolveDir, bool predDir, UINT32 branchTarget) {

	int a = PC;
	int b = GSHARE_BHR;
	
	
	int index_select = (((PC & 0x7F) << 7) | (GSHARE_BHR & 0xFF));  //concate 7 bit adress and 8 bit history
	int index_contour = ((a+b)*(a+b+1)*(0.5)+ b); //contour pairing formula
	int index_hash = index_select ^ index_contour ^ (PC & 0x7FFF); //xor them
	
	//Update the PHT
	//GSELECT
	if((resolveDir == TAKEN) && (GSELECT_PHT[index_select%21330] < 3))
		GSELECT_PHT[index_select%21330]++;
	else if((resolveDir == NOT_TAKEN) && (GSELECT_PHT[index_select%21330] > 0))
		GSELECT_PHT[index_select%21330]--;
	
	//CONTOUR
	if((resolveDir == TAKEN) && (CONTOUR_PHT[index_contour%21330] < 3))
		CONTOUR_PHT[index_contour%21330]++;
	else if((resolveDir == NOT_TAKEN) && (CONTOUR_PHT[index_contour%21330] > 0))
		CONTOUR_PHT[index_contour%21330]--;
	
	//HASH
	if((resolveDir == TAKEN) && (HASH_PHT[index_hash%21330] < 3))
		HASH_PHT[index_hash%21330]++;
	else if((resolveDir == NOT_TAKEN) && (HASH_PHT[index_hash%21330] > 0))
		HASH_PHT[index_hash%21330]--;
	
	//record pattern
	if(resolveDir == TAKEN)
		GSHARE_BHR = (GSHARE_BHR*2 + 1) & 0x7FFF;
	else
		GSHARE_BHR = (GSHARE_BHR*2) & 0x7FFF;
		
	
}

