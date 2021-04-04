
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

struct Queue* createQueue(int capacity){
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));	
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(queue->capacity*sizeof(int));
	return queue;
}

int isFull(struct Queue* queue){
	if(queue->size == queue->capacity){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(struct Queue* queue){
	return(queue->size == 0);
}
