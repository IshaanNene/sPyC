#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
} NODE;

typedef struct Queue{
    int size;
    int capacity;
    NODE *front;
    NODE *rear;
} QUEUE;

QUEUE* Initialize_Queue(int capacity){
    QUEUE* new_queue = (QUEUE*)malloc(sizeof(QUEUE));
    if (new_queue == NULL) {
        return NULL;
    }
    new_queue->size = 0;
    new_queue->capacity = capacity;
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

void Enqueue(QUEUE* user_queue, int data){
    if (user_queue->size >= user_queue->capacity) {
        return;
    }
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = user_queue->rear;
    if (user_queue->rear != NULL) {
        user_queue->rear->next = new_node;
    }
    user_queue->rear = new_node;
    if (user_queue->front == NULL) {
        user_queue->front = new_node;
    }
    user_queue->size++;
}

int Dequeue(QUEUE* user_queue){
    if (user_queue->front == NULL) {
        return -1;
    }
    int data = user_queue->front->data;
    NODE* temp = user_queue->front;
    user_queue->front = user_queue->front->next;
    if (user_queue->front != NULL) {
        user_queue->front->prev = NULL;
    } else {
        user_queue->rear = NULL;
    }
    free(temp);
    user_queue->size--;
    return data;
}

bool Is_Empty(QUEUE* user_queue){
    return user_queue->size == 0;
}

bool Is_Full(QUEUE* user_queue){
    return user_queue->size >= user_queue->capacity;
}

int Queue_Size(QUEUE* user_queue){
    return user_queue->size;
}