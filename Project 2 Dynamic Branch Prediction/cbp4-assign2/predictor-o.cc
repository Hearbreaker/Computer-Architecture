#include "predictor.h"
#include <iostream>
#include <fstream>

typedef struct{
	unsigned int counter;
	unsigned int tar_pc;
	unsigned int pred;
	
	
}BTB_struct;

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
	//PC = PC >> 4;
	int index = PC%4096;
	//cout<<two_bit_sat[index]<<endl;
	//cout<<PC<<endl;
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
	//PC = PC >> 4;
	int index = PC%4096;
	//cout<<PC<endl;
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
	//cout <<"PC is: "<<PC<<endl;
	//cout << "BHT is: "<<BHT_index<<endl;
	//cout << "PHT is: "<<PHT_index<<endl;
	
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
		BHT[BHT_index] = ((BHT[BHT_index]*2) + 1) & 0x3F; //Shift left by 1 and add 1
	else
		BHT[BHT_index] = (BHT[BHT_index]*2) & 0x3F; //Shift left by 1 and add 0
	

}

/////////////////////////////////////////////////////////////
// openend
/////////////////////////////////////////////////////////////
unsigned int GSHARE_BHR; //16 bit history
unsigned int GSHARE_PHT[32768]; //bimodal PHT
unsigned int weight[32768];
//BTB_struct BTB[2048]; // 2k table with 4bit counter and 6bit PC and 1 bit taken/NT

bool lastoutcome;

void InitPredictor_openend() {
	int i;
	
	GSHARE_BHR = 0;
	for(i=0; i < 32768; i++){

		GSHARE_PHT[i] = 1;
	}
	for(i=0; i < 32768; i++){

		weight[i] = 3;
	}
	
//	for(i=0; i<2048; i++){
//		BTB[i].counter = 0;
//		BTB[i].pred = 0;
//		BTB[i].tar_pc = 0;
//	}
//	lastoutcome = false;


}

bool GetPrediction_openend(UINT32 PC) {
	
//	//USE LAST OUTCOME IF Branch heavily biased
//	int BTB_index = PC & 0xFF;
//
//	//if(BTB[BTB_index].counter >= 32){
//		//lastoutcome = true;
//		if(BTB[BTB_index].pred == 1)
//			return TAKEN;
//		else
//			return NOT_TAKEN;
//	//}
	
	//ELSE USE GSHARE
	int index = (PC & 0x7FFF) ^ (GSHARE_BHR & 0x7FFF);

	if(GSHARE_PHT[index] >= 2){
		if(weight[index]>= 2)
			return TAKEN;
		else
			return NOT_TAKEN;
	}
	else{
		if(weight[index]>= 2)
			return NOT_TAKEN;
		else
			return TAKEN;
	}
	
}


void UpdatePredictor_openend(UINT32 PC, bool resolveDir, bool predDir, UINT32 branchTarget) {
	
	//int BTB_index = PC & 0xFF;
	int index = (PC & 0x7FFF) ^ (GSHARE_BHR & 0x7FFF);


	//if(lastoutcome == true){//lastoutcome was used
		
		//if(predDir != resolveDir){ //check if last outcome was correct
			//lastoutcome = false;
		//}	
	//}
//	if(lastoutcome == false){
		//GSHARE STUFF
		//update weights
		if((resolveDir == predDir) && (weight[index] < 3))
			weight[index]++;
		else if ((resolveDir != predDir) && (weight[index] > 0)) 
			weight[index]--;
		//Update the PHT
		if((resolveDir == TAKEN) && (GSHARE_PHT[index] < 3))
			GSHARE_PHT[index]++;
		else if((resolveDir == NOT_TAKEN) && (GSHARE_PHT[index] > 0))
			GSHARE_PHT[index]--;
		//record pattern
		if(resolveDir == TAKEN)
			GSHARE_BHR = (GSHARE_BHR*2 + 1) & 0x7FFF;
		else
			GSHARE_BHR = (GSHARE_BHR*2) & 0x7FFF;
		
			
//		//Lastoutcome STUFF
//		//update prediction
//		if(resolveDir == TAKEN){
//			BTB[BTB_index].pred = 1;
//		}
//		else
//			BTB[BTB_index].pred = 0;
//		
//		//update counter & pc;
//		unsigned int pc_new = predDir & 0x7F;
//		if(pc_new == BTB[BTB_index].tar_pc){
//			if(BTB[BTB_index].counter < 16)
//				BTB[BTB_index].counter++;
//			BTB[BTB_index].tar_pc = pc_new;
//		}
//		else{
//			BTB[BTB_index].counter=0;
//			BTB[BTB_index].tar_pc = pc_new;
//		}		
//	}
//	else
//		//Lastoutcome STUFF
//		//update prediction
//		if(resolveDir == TAKEN){
//			BTB[BTB_index].pred = 1;
//		}
//		else
//			BTB[BTB_index].pred = 0;
//		
//		//update counter & pc;
//		unsigned int pc_new = predDir & 0x7F;
//		if(pc_new == BTB[BTB_index].tar_pc){
//			//if(BTB[BTB_index].counter < 16)
//				BTB[BTB_index].counter++;
//			BTB[BTB_index].tar_pc = pc_new;
//		}
//		else{
//			BTB[BTB_index].counter=0;
//			BTB[BTB_index].tar_pc = pc_new;
//		}
}

