
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
static int dbb = 0;
/* FUNCTIONAL UNITS */


/* RESERVATION STATIONS */


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
	/* ECE552 Assignment 3 - BEGIN CODE */

  /* ECE552: YOUR CODE GOES HERE */

		int i; //Check pipeline is empty. loop through all queues, FU, RS.

		if(instr_queue_size  > 0){
			return false;
		}

		for(i = 0; i < INSTR_QUEUE_SIZE; i++){
			if(instr_queue[i] != NULL){ //Check queue empty
				return false;
			}	
		}
		for(i = 0; i < RESERV_INT_SIZE; i++){
			if(reservINT[i] != NULL){ //Check INT RS empty
				return false;
			}	
		}
		for(i = 0; i < FU_INT_SIZE; i++){
			if(fuINT[i] != NULL){ //Check INT FU empty
				return false;
			}	
		}
		for(i = 0; i < RESERV_FP_SIZE; i++){ //Check FP RS empty
			if(reservFP[i] != NULL){
				return false;
			}	
		}
		if(fuFP[0] != NULL){//Check FP FU empty
			return false;
		}


		return true; 
		//ECE552: you can change this as needed; we've added this so the code provided to you compiles
		/* ECE552 Assignment 3 - END CODE */
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
	/* ECE552 Assignment 3 - BEGIN CODE */

  /* ECE552: YOUR CODE GOES HERE */
	int i;
	int j;


	if(commonDataBus != NULL){
		//Clear dependencies in reservation table. Value is ready if other instructions need.
		if(commonDataBus->tom_cdb_cycle > current_cycle + 1  && commonDataBus->tom_cdb_cycle != 0){
			return;
		}

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

			for(i = 0; i < 2; i++){
				if(commonDataBus->r_out[i] != DNA && (map_table[commonDataBus->r_out[i]] == commonDataBus)){
					map_table[commonDataBus->r_out[i]] = NULL;
				}
			}

			commonDataBus = NULL;
	}
	else
		return;

	return;
	/* ECE552 Assignment 3 - END CODE */

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
	/* ECE552 Assignment 3 - BEGIN CODE */

  /* ECE552: YOUR CODE GOES HERE */
	//Check if FU unit is done
	//if done. Free up FU and RS.


	//INT OPERATIONS
	int i; //FU_index
	int j; //RS_index
	instruction_t* to_cdb = NULL;

	if(commonDataBus == NULL){ //Check if CDB is availabe.
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
					else{

						if (to_cdb != NULL){//NOT A STORE
							if(to_cdb->index > fuINT[i]->index) //CDB oldest instruction. Therefore smallest index
								to_cdb = fuINT[i];
						}
						else{
							to_cdb = fuINT[i];
						}
					}
				}
			}
		}
	

		//FP OPERATIONS
		for(i = 0; i < FU_FP_SIZE; i++){
			if(fuFP[i] != NULL){//FIND executing OP

				if(current_cycle >= fuFP[i]->tom_execute_cycle + FU_FP_LATENCY){

					if(to_cdb != NULL){

						if(to_cdb->index > fuFP[i]->index) //CDB oldest instruction. Therefore smallest index
							to_cdb = fuFP[i];
							fuFP[i] = NULL;
					}
					else{ //NULL. Just set.

						to_cdb = fuFP[i];
						fuFP[i] = NULL;
					}
				}
			}
		}
		if(to_cdb == NULL){// No instructions finished
			return;

		}
		else{ //Send to cdb. Clear RS of FP. Clear RS and FU of int.
			commonDataBus = to_cdb;
			commonDataBus->tom_cdb_cycle = current_cycle;


			if(USES_FP_FU(to_cdb->op)){//Clear RS of FP.
				for(j = 0; j < RESERV_FP_SIZE; j++){
					if(reservFP[j] == to_cdb){
						reservFP[j] = NULL;
					}
				}

			}
			else{ //Clear RS and FU of int.
				for(i = 0; i < FU_INT_SIZE; i++){
					if(fuINT[i] == to_cdb){
						fuINT[i] = NULL;
					}
				}
				for(j = 0; j < RESERV_INT_SIZE; j++){
					if(reservINT[j] == to_cdb){
						reservINT[j] = NULL;
					}
				}
			}

		}
	}


	/* ECE552 Assignment 3 - END CODE */

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
	/* ECE552 Assignment 3 - BEGIN CODE */
	//INT
	int FU_index;
	int RS_index;
	bool found = FALSE;
	instruction_t* to_execute = NULL;
	do {
		to_execute = NULL;
		found = FALSE;
		for(FU_index = 0; FU_index < FU_INT_SIZE; FU_index++){ //Check if FU is ready.
			if(fuINT[FU_index] == NULL){
				found = TRUE;
				break;
			}

		}
		if(found == TRUE){
			 //Check if OP ready.
			for(RS_index = 0; RS_index < RESERV_INT_SIZE; RS_index++){
				if(reservINT[RS_index] != NULL && (reservINT[RS_index]->Q[0] == NULL && reservINT[RS_index]->Q[1] == NULL && reservINT[RS_index]->Q[2] == NULL && reservINT[RS_index]->tom_execute_cycle == 0)){ //Check Dependency
					if(to_execute != NULL){
						if(to_execute->index > reservINT[RS_index]->index) //Execute oldest instruction. Therefore smallest index
							to_execute = reservINT[RS_index];
					}
					else{
						to_execute = reservINT[RS_index];

					}
				}
			}
		}

		if(to_execute != NULL) {
			fuINT[FU_index] = to_execute;
			// set tom_execute_cycle to current cycle
			fuINT[FU_index]->tom_execute_cycle = current_cycle;
		}
	}while(found == TRUE && to_execute != NULL);

	//FP
	FU_index = 0;
	RS_index = 0;
	found = FALSE;
	to_execute = NULL;

	
		found = FALSE;
		to_execute = NULL;
		for(FU_index = 0; FU_index < FU_FP_SIZE; FU_index++){ //Check if FU is ready.
			if(fuFP[FU_index] == NULL){
				found = TRUE;
				break;
			}

		}
		if(found == TRUE){
			 //Check if OP ready.
			for(RS_index = 0; RS_index < RESERV_FP_SIZE; RS_index++){

				if(reservFP[RS_index] != NULL && (reservFP[RS_index]->Q[0] == NULL && reservFP[RS_index]->Q[1] == NULL && reservFP[RS_index]->Q[2] == NULL && reservFP[RS_index]->tom_execute_cycle == 0)){ //Check Dependency
					if(to_execute != NULL){
						if(to_execute->index > reservFP[RS_index]->index) //Execute oldest instruction. Therefore smallest index
							to_execute = reservFP[RS_index];
					}
					else{
						to_execute = reservFP[RS_index];
					}
				}
			}
		}
		else {
			return;
		}


		if(to_execute == NULL) {
			return;
		}
		else{
			fuFP[FU_index] = to_execute;
			// set tom_execute_cycle to current cycle
			fuFP[FU_index]->tom_execute_cycle = current_cycle;
		}

	/* ECE552 Assignment 3 - END CODE */
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
	/* ECE552 Assignment 3 - BEGIN CODE */

  /* ECE552: YOUR CODE GOES HERE */
	
	//skip branches
	//determine the type and place into correct RS
	//update the map table and dependencies
	int i;
	bool full = TRUE; //Check if RS is set.
	if(instr_queue[0] == NULL){ //Queue empty. Nothing to do.
		return;
	}
	
	//check if next instruction is a branch.
	if(IS_UNCOND_CTRL(instr_queue[0]->op) || IS_COND_CTRL(instr_queue[0]->op)){
		instr_queue[0] = NULL; //If branch. Move onto next instruction
		for(i = 0; i < instr_queue_size - 1; i++){
			instr_queue[i] = instr_queue[i+1];
			instr_queue[i+1] = NULL;
		}
		instr_queue_size--;
		return;
	}
	
	if(USES_INT_FU(instr_queue[0]->op)){	//check for empty int RS
		for(i = 0; i < RESERV_INT_SIZE; i++){
			if(reservINT[i] == NULL){
				reservINT[i] = instr_queue[0];
				full = FALSE;
				break;
			}
		}
	}
	else if(USES_FP_FU(instr_queue[0]->op)){	//check for empty FP RS
		for(i = 0; i < RESERV_FP_SIZE; i++){
			if(reservFP[i] == NULL){
				reservFP[i] = instr_queue[0];
				full = FALSE;
				break;
			}
		}
	}
	
	if(full != TRUE){	//RS is set. Update map table and dependency tags.
		instr_queue[0]->tom_issue_cycle = current_cycle;
		for(i = 0; i < 3; i++){
			if(instr_queue[0]->r_in[i] != DNA){ //Check which source registers are being used.
				instr_queue[0]->Q[i] = map_table[instr_queue[0]->r_in[i]];	//Set dependency tags with source registers instruction
			}
		}
		
		for(i = 0; i < 2; i++){
			if(instr_queue[0]->r_out[i] != DNA){ //Check which target registers are being used.
				map_table[instr_queue[0]->r_out[i]] = instr_queue[0];	//Set map table with target register instruction
			}
		}
		instr_queue[0] = NULL;
		for(i = 0; i < instr_queue_size - 1; i++){
			instr_queue[i] = instr_queue[i+1];
			instr_queue[i+1] = NULL;
		}
		instr_queue_size--;
	}
	/* ECE552 Assignment 3 - END CODE */
}





/* 
 * Description: 
 * 	Grabs an instruction from the instruction trace (if possible)
 * Inputs:
 *      trace: instruction trace with all the instructions executed
 * Returns:
 * 	None
 */
void fetch(instruction_trace_t* trace) {
	/* ECE552 Assignment 3 - BEGIN CODE */

  /* ECE552: YOUR CODE GOES HERE */
	//Increment index and fetch. 
	fetch_index++;
	while(IS_TRAP(get_instr(trace, fetch_index)->op))//If trap, keep fetching until not a trap.
		fetch_index++;

	if(instr_queue_size < INSTR_QUEUE_SIZE){ //Place into queue if empty.
		if(fetch_index <= sim_num_insn){
			instr_queue[instr_queue_size] = get_instr(trace, fetch_index);
			//instr_queue[instr_queue_size]->index = fetch_index;
		}
	}

	return;
	/* ECE552 Assignment 3 - END CODE */
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
	/* ECE552 Assignment 3 - BEGIN CODE */

  /* ECE552: YOUR CODE GOES HERE */
	  
	if(instr_queue_size < INSTR_QUEUE_SIZE){
		fetch(trace);
		if(instr_queue_size < INSTR_QUEUE_SIZE){
			if(fetch_index <= sim_num_insn){ //Instruction is dispatched.
				instr_queue[instr_queue_size]->tom_dispatch_cycle = current_cycle;
				instr_queue_size++;
			}
		}
	}

	/* ECE552 Assignment 3 - END CODE */
	
}

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
  
  int cycle = 1;
  while (true) {

	  /* ECE552 Assignment 3 - BEGIN CODE */
     /* ECE552: YOUR CODE GOES HERE */
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

