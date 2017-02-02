
#include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "host.h"
#include "misc.h"
#include "machine.h"
#include "regs.h"
#include "memory.h"
#include "loader.h"
#include "syscall.h"
#include "dlite.h"
#include "options.h"
#include "stats.h"
#include "sim.h"
#include "decode.def"

#include "instr.h"

/* PARAMETERS OF THE TOMASULO'S ALGORITHM */

#define INSTR_QUEUE_SIZE         10

#define RESERV_INT_SIZE    4
#define RESERV_FP_SIZE     2
#define FU_INT_SIZE        2
#define FU_FP_SIZE         1

#define FU_INT_LATENCY     4
#define FU_FP_LATENCY      9

/* IDENTIFYING INSTRUCTIONS */

//unconditional branch, jump or call
#define IS_UNCOND_CTRL(op) (MD_OP_FLAGS(op) & F_CALL || \
                         MD_OP_FLAGS(op) & F_UNCOND)

//conditional branch instruction
#define IS_COND_CTRL(op) (MD_OP_FLAGS(op) & F_COND)

//floating-point computation
#define IS_FCOMP(op) (MD_OP_FLAGS(op) & F_FCOMP)

//integer computation
#define IS_ICOMP(op) (MD_OP_FLAGS(op) & F_ICOMP)

//load instruction
#define IS_LOAD(op)  (MD_OP_FLAGS(op) & F_LOAD)

//store instruction
#define IS_STORE(op) (MD_OP_FLAGS(op) & F_STORE)

//trap instruction
#define IS_TRAP(op) (MD_OP_FLAGS(op) & F_TRAP) 

#define USES_INT_FU(op) (IS_ICOMP(op) || IS_LOAD(op) || IS_STORE(op))
#define USES_FP_FU(op) (IS_FCOMP(op))

#define WRITES_CDB(op) (IS_ICOMP(op) || IS_LOAD(op) || IS_FCOMP(op))

/* FOR DEBUGGING */

//prints info about an instruction
#define PRINT_INST(out,instr,str,cycle)	\
  myfprintf(out, "%d: %s", cycle, str);		\
  md_print_insn(instr->inst, instr->pc, out); \
  myfprintf(stdout, "(%d)\n",instr->index);

#define PRINT_REG(out,reg,str,instr) \
  myfprintf(out, "reg#%d %s ", reg, str);	\
  md_print_insn(instr->inst, instr->pc, out); \
  myfprintf(stdout, "(%d)\n",instr->index);

/* VARIABLES */

//instruction queue for tomasulo
static instruction_t* instr_queue[INSTR_QUEUE_SIZE];
//number of instructions in the instruction queue
static int instr_queue_size = 0;

//reservation stations (each reservation station entry contains a pointer to an instruction)
static instruction_t* reservINT[RESERV_INT_SIZE];
static instruction_t* reservFP[RESERV_FP_SIZE];

//functional units
static instruction_t* fuINT[FU_INT_SIZE];
static instruction_t* fuFP[FU_FP_SIZE];

//common data bus
static instruction_t* commonDataBus = NULL;

//The map table keeps track of which instruction produces the value for each register
static instruction_t* map_table[MD_TOTAL_REGS];

//the index of the last instruction fetched
static int fetch_index = 0;

/* FUNCTIONAL UNITS */


/* RESERVATION STATIONS */

/* ECE552 Assignment 3 - BEGIN CODE */

/* 
 * Description: 
 * 	Checks if simulation is done by finishing the very last instruction
 *      Remember that simulation is done only if the entire pipeline is empty
 * Inputs:
 * 	sim_insn: the total number of instructions simulated
 * Returns:
 * 	True: if simulation is finished
 */
static bool is_simulation_done(counter_t sim_insn) {

  /* ECE552: YOUR CODE GOES HERE */

	int i;
	for(i = 0; i < INSTR_QUEUE_SIZE; i++){
		if(instr_queue[i] != NULL)
			return false;
	}
	
	for(i = 0; i < RESERV_INT_SIZE; i++){
		if(reservINT[i] != NULL)
			return false;
	}
	
	for(i = 0; i < RESERV_FP_SIZE; i++){
		if(reservFP[i] != NULL)
			return false;
	}

	for(i = 0; i <  FU_FP_SIZE; i++){
		if(fuFP[i] != NULL)
			return false;
	}
	
	for (i = 0; i < FU_INT_SIZE; i++){
		if(fuINT[i] != NULL)
			return false;
	}

	return true; //ECE552: you can change this as needed; we've added this so the code provided to you compiles
}

/* 
 * Description: 
 * 	Retires the instruction from writing to the Common Data Bus
 * Inputs:
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void CDB_To_retire(int current_cycle) {

  /* ECE552: YOUR CODE GOES HERE */

	//For CDB to retire, clear the tags of instructions who are waiting for CDB value
	//Clear map table and CDB itself

	int i,j;
	if(commonDataBus != NULL){
		// clear tags
		for(i = 0; i < RESERV_INT_SIZE; i++){
			if(reservINT[i] != NULL){
				for(j = 0; j < 3; j++){
					if(reservINT[i]->Q[j] == commonDataBus){
						reservINT[i]->Q[j] = NULL;
					}
				}
			}
		}

		for(i = 0; i < RESERV_FP_SIZE; i++){
			if(reservFP[i] != NULL){
				for(j = 0; j < 3; j++){
					if(reservFP[i]->Q[j] == commonDataBus){
						reservFP[i]->Q[j] = NULL;
					}
				}
			}
		}

		//clear map table
		for(i = 0; i < 2; i++){
			if(commonDataBus->r_out[i] != DNA){
				if(map_table[commonDataBus->r_out[i]] == commonDataBus){
					map_table[commonDataBus->r_out[i]] = NULL;	//clear map table
				}
			}
		}

		commonDataBus = NULL;
	}

	return;
}


/* 
 * Description: 
 * 	Moves an instruction from the execution stage to common data bus (if possible)
 * Inputs:
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void execute_To_CDB(int current_cycle) {

  /* ECE552: YOUR CODE GOES HERE */

	instruction_t** CDBinst = NULL;	//double pointer holds the instruction that has the priority to write to the CDB

	int i,j;
	for(i = 0; i < FU_INT_SIZE; i++){
		if(fuINT[i] != NULL){
			if(current_cycle >= fuINT[i]->tom_execute_cycle + FU_INT_LATENCY){
				if(IS_STORE(fuINT[i]->op)){	//	store do not write to CDB, just free the RS & FU
					for(j = 0; j < RESERV_INT_SIZE; j++){
						if(reservINT[j] == fuINT[i]){
							reservINT[j] = NULL;
							fuINT[i] = NULL;
							break;
						}
					}
				}
				else if(CDBinst == NULL || (CDBinst != NULL && (*CDBinst)->index > fuINT[i]->index)){	//if an older instruction has been found
					CDBinst = &fuINT[i];	// the older instruction has the priority to write to CDB
					assert(WRITES_CDB((*CDBinst)->op));
				}
			}
		}
	}
	
	for(i = 0; i < FU_FP_SIZE; i++){
		if(fuFP[i] != NULL){
			if(current_cycle >= fuFP[i]->tom_execute_cycle + FU_FP_LATENCY){
				if (CDBinst == NULL || (CDBinst != NULL && (*CDBinst)->index > fuFP[i]->index)){
					CDBinst = &fuFP[i];
					assert(WRITES_CDB((*CDBinst)->op));
				}
			}
		}
	}
	
	if(CDBinst != NULL){
		
		commonDataBus = *CDBinst;
		commonDataBus->tom_cdb_cycle = current_cycle;
		
		//clear RS
		if(USES_INT_FU(commonDataBus->op)){
			for(i = 0 ; i < RESERV_INT_SIZE; i++){
				if(reservINT[i] == commonDataBus){
					reservINT[i] = NULL;
					update_RS(i, 1);
					break;
				}
			}
		}
		else{
			for(i = 0 ; i < RESERV_FP_SIZE; i++){
				if(reservFP[i] == commonDataBus){
					reservFP[i] = NULL;
					update_RS(i, 0);
					break;
				}
			}
		}

		//clear FU
		*CDBinst = NULL;
	}
}

/*
 * Helper function for execute_To_CDB
 * Update the RS when some RS entry has been cleared
 */
void update_RS(int i, int is_int){// i is the index of empty spot that has been cleared
	int j;
	if(is_int){//int RS case
		for(j = i; j < RESERV_INT_SIZE - 1; j++){
			reservINT[j] = reservINT[j+1];
			reservINT[j+1] = NULL;
		}	
	}
	else{//FP RS case
		if(i == 0 && reservFP[1] != NULL){
			reservFP[i] = reservFP[1];
			reservFP[1] = NULL;
		}
	}
}

/* 
 * Description: 
 * 	Moves instruction(s) from the issue to the execute stage (if possible). We prioritize old instructions
 *      (in program order) over new ones, if they both contend for the same functional unit.
 *      All RAW dependences need to have been resolved with stalls before an instruction enters execute.
 * Inputs:
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void issue_To_execute(int current_cycle) {

  /* ECE552: YOUR CODE GOES HERE */

	int i = 0;
	int j = 0;
L1:	while(i < FU_INT_SIZE){
		if(fuINT[i] == NULL){	// check if functional unit is available
			while(j < RESERV_INT_SIZE){
				if(reservINT[j] != NULL){
					if(reservINT[j]->Q[0] == NULL && reservINT[j]->Q[1] == NULL && reservINT[j]->Q[2] == NULL && reservINT[j]->tom_execute_cycle == 0){//check dependency tags
						   // put instruction into the functional unit
						   fuINT[i] = reservINT[j];
						   // set tom_execute_cycle to current cycle
						   fuINT[i]->tom_execute_cycle = current_cycle;
						   i++;
						   j++;
						   goto L1;
					}
				}
				j++;
			}
		}
		i++;
	}
	
	j = 0;
	i = 0;
L2:	while(i < FU_FP_SIZE){
		if(fuFP[i] == NULL){
			while(j < RESERV_FP_SIZE){
				if(reservFP[j] != NULL){
					if(reservFP[j]->Q[0] == NULL && reservFP[j]->Q[1] == NULL && reservFP[j]->Q[2] == NULL && reservFP[j]->tom_execute_cycle == 0){
						   // put instruction into the functional unit
						   fuFP[i] = reservFP[j];
						   // set tom_execute_cycle to current cycle
						   fuFP[i]->tom_execute_cycle = current_cycle;
						   i++;
						   j++;
						   goto L2;
					}
				}
				j++;
			}
		}
		i++;
	}

}

/* 
 * Description: 
 * 	Moves instruction(s) from the dispatch stage to the issue stage
 * Inputs:
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void dispatch_To_issue(int current_cycle) {

  /* ECE552: YOUR CODE GOES HERE */
	
	//check if IFQ empty
	if(instr_queue[0] == NULL){
		return;
	}
	
	//check if next instruction is a branch
	if(IS_UNCOND_CTRL(instr_queue[0]->op) || IS_COND_CTRL(instr_queue[0]->op)){
		update_IFQ();	//pop out the branch instruction from the IFQ head
		return;
	}
	
	instruction_t* temp = NULL;
	int i;
	if(USES_INT_FU(instr_queue[0]->op)){	//check for empty int RS
		for(i = 0; i < RESERV_INT_SIZE; i++){
			if(reservINT[i] == NULL){
				reservINT[i] = instr_queue[0];
				temp = instr_queue[0];
				break;
			}
		}
	}
	else if(USES_FP_FU(instr_queue[0]->op)){	//check for empty FP RS
		for(i = 0; i < RESERV_FP_SIZE; i++){
			if(reservFP[i] == NULL){
				reservFP[i] = instr_queue[0];
				temp = instr_queue[0];
				break;
			}
		}
	}
	
	if(temp == NULL){	//RS is full, then stall the IFQ
		return;
	}
	else{
		update_IFQ();
		temp->tom_issue_cycle = current_cycle;
		
		for(i = 0; i < 3; i++){
			if(temp->r_in[i] != DNA){
				temp->Q[i] = map_table[temp->r_in[i]];	//set the dependency tags
			}
		}
		
		for(i = 0; i < 2; i++){
			if(temp->r_out[i] != DNA){
				map_table[temp->r_out[i]] = temp;	//update the map_table
			}
		}
	}
}

/* ECE552 Assignment 3 - BEGIN CODE */

/*
 * Helper function for dispatch_To_issue
 * Pop out the first instruction in the IFQ and shifting the rest instructions to the head
 */
void update_IFQ(){
	int i;
	instr_queue[0] = NULL;
	for(i = 0; i < instr_queue_size - 1; i++){
		instr_queue[i] = instr_queue[i+1];
		instr_queue[i+1] = NULL;
	}
	instr_queue_size--;
}

/* ECE552 Assignment 3 - END CODE */

/* 
 * Description: 
 * 	Grabs an instruction from the instruction trace (if possible)
 * Inputs:
 *      trace: instruction trace with all the instructions executed
 * Returns:
 * 	None
 */
void fetch(instruction_trace_t* trace) {

  /* ECE552: YOUR CODE GOES HERE */
  
	//use do while loop for consecutive trap instructions, if not a trap, then just increase fetch_index by 1

	do{
		fetch_index++;
	}
	while(IS_TRAP(get_instr(trace, fetch_index)->op));

}

/* 
 * Description: 
 * 	Calls fetch and dispatches an instruction at the same cycle (if possible)
 * Inputs:
 *      trace: instruction trace with all the instructions executed
 * 	current_cycle: the cycle we are at
 * Returns:
 * 	None
 */
void fetch_To_dispatch(instruction_trace_t* trace, int current_cycle) {

  /* ECE552: YOUR CODE GOES HERE */
  
	if(instr_queue_size < INSTR_QUEUE_SIZE){
		fetch(trace);	//IFQ is not full
		if(fetch_index <= sim_num_insn){
			instr_queue[instr_queue_size] = get_instr(trace, fetch_index);
			instr_queue[instr_queue_size]->tom_dispatch_cycle = current_cycle;
			instr_queue_size++;
		}
	}
	else{
		// IFQ is full, just don't fetch
	}
}

/* ECE552 Assignment 3 - END CODE */

/* 
 * Description: 
 * 	Performs a cycle-by-cycle simulation of the 4-stage pipeline
 * Inputs:
 *      trace: instruction trace with all the instructions executed
 * Returns:
 * 	The total number of cycles it takes to execute the instructions.
 * Extra Notes:
 * 	sim_num_insn: the number of instructions in the trace
 */
counter_t runTomasulo(instruction_trace_t* trace)
{
  //initialize instruction queue
  int i;
  for (i = 0; i < INSTR_QUEUE_SIZE; i++) {
    instr_queue[i] = NULL;
  }

  //initialize reservation stations
  for (i = 0; i < RESERV_INT_SIZE; i++) {
      reservINT[i] = NULL;
  }

  for(i = 0; i < RESERV_FP_SIZE; i++) {
      reservFP[i] = NULL;
  }

  //initialize functional units
  for (i = 0; i < FU_INT_SIZE; i++) {
    fuINT[i] = NULL;
  }

  for (i = 0; i < FU_FP_SIZE; i++) {
    fuFP[i] = NULL;
  }

  //initialize map_table to no producers
  int reg;
  for (reg = 0; reg < MD_TOTAL_REGS; reg++) {
    map_table[reg] = NULL;
  }
  /* ECE552 Assignment 3 - BEGIN CODE */

  //	print_all_instr(trace, sim_num_insn);	// for debugging

  /* ECE552 Assignment 3 - END CODE */

  int cycle = 1;
  while (true) {

	  /* ECE552: YOUR CODE GOES HERE */

	  /* ECE552 Assignment 3 - BEGIN CODE */

	//	We run the functions in reverse order to avoid instructions go through all stages in one cycle
	//	Also, in this case, it's easier to assign tom_cycles for each instruction
	CDB_To_retire(cycle);
	execute_To_CDB(cycle);
	issue_To_execute(cycle);
	dispatch_To_issue(cycle);
	fetch_To_dispatch(trace, cycle);
	
	  /* ECE552 Assignment 3 - END CODE */
	cycle++;

	if (is_simulation_done(sim_num_insn))
		break;
	}

	return cycle;
}
