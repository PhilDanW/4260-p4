#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include "sharedMem.h"
#include "queue.h"

void startScheduling();
void ossExit(int sig);
void cleanUp();

int shmid;
int msqid;
struct PCB *controlTable;
FILE* fp;//File pointer for output log
struct sharedRes *shared;
//struct messageBuff msg; 
int toChild;
int toOSS;
const int maxTimeBetweenNewProcSec = 1; 
const int maxTimeBetweenNewProcNS = 500;
const int realTime = 15;//Chance of proccess to be a real time process
int n;//Store max number of children
int takenPids[18];
	//time data
	struct times exec = {0,0};//Holds time until next exec
	struct times totalCpuTime;
	struct times totalBlocked;
	struct times waitTime;
	struct times idleTime;
struct{
	long mtype;
	char message[100];
}msg;


int main(int argc, char *argv[]){
	//Setting up signals
	signal(SIGALRM, ossExit);
	alarm(3);
	signal(SIGINT, ossExit);
	//Get command line arguments	
	int c;	
	while((c=getopt(argc, argv, "n:s:h"))!= EOF){
		switch(c){
			case 'h':
				printf("\n-n: Total number of processes in system at any given time(Maximum of 18)");
				exit(0);
				break;
			case 'n':
				n = atoi(optarg);
				if(n > 18){
					n = 18;//Set n to 18 to 18 if n exceeds that amount or is left at -0
				}
				break;
		}
	}
	printf("Starting to schedule!\n");
	printf("Generating osslog.txt now...\n");
