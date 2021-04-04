#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <time.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include "sharedMem.h"
int shmid;

struct{
	long mtype;
	char message[100];
}msg;

void addTime(struct times* time, int sec, int ns){
	time->seconds += sec;
	time->nanoseconds += ns;
	while(time->nanoseconds >= 1000000000){
		time->nanoseconds -=1000000000;
		time->seconds++;
	}
}
int main(int argc, char *argv[]){
	const int chanceToDie = 30;
	const int chanceToTakeFullTime = 75;//25% chance to get preempted
	int toChild, toOSS;
	int id = getpid();
	struct times blockingTime;
	struct sharedRes *shared;

	int lpid = atoi(argv[0]);

	time_t t;
	time(&t);	
	srand((int)time(&t) % id);
