//Author: Philip Wright
//Project 4 - Process Scheduling - CMPSCI4760
//queue.c contains functions necessary for creating and keeping tracks of the processes in the queues

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

//creates a new queue and initializes its values
struct Queue* createQueue(int capacity){
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));	
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(queue->capacity*sizeof(int));
	return queue;
}

//accessory function to check if a given queue is full
int isFull(struct Queue* queue){
	if(queue->size == queue->capacity){
		return 1;
	}else{
		return 0;
	}
}

//an accessory funciton to check if a given queue is empty
int isEmpty(struct Queue* queue){
	return(queue->size == 0);
}
