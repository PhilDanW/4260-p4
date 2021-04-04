//Author: Philip Wright
//Project 4 - Process Scheduling - CMPSCI4760
//sharedMem.h contains the structure for the shared memory clock and the 
//structure of the Process control block

#ifndef SHAREDMEM_H_
#define SHAREDMEM_H_

//clock stored in two shared integers
struct times{
	int nanoseconds;
	int seconds;
};

//Process Control Block
struct PCB{
	struct times totalCpuTime;
	struct times  totalTimeInSystem;
	struct times timeLastBurst;
	struct times blockedTime;
	int processClass; //realtime or user class
	int pid;//actual pid of process
	int lpid;//simulate:wq
	int priority;
};

struct sharedRes{
	struct PCB controlTable[18];
	struct times time;
};
#endif
