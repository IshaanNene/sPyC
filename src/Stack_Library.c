#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node{
    int data;
    struct Node *next;
} NODE;

typedef struct Stack{
    int size;
    int capacity;
    struct Node *top;
} STACK;

STACK* Initialize_Stack(int capacity){
    STACK* new_stack = (STACK*)malloc(sizeof(STACK));
    if (new_stack == NULL) {
        return NULL;
    }
    new_stack->size = 0;
    new_stack->capacity = capacity;
    new_stack->top = NULL;
    return new_stack;
}

void Push(STACK* user_stack, int top){
    if (user_stack->size >= user_stack->capacity) {
        return;
    }
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    if (new_node == NULL) {
        return;
    }
    new_node->data = top;
    new_node->next = user_stack->top;
    user_stack->top = new_node;
    user_stack->size++;
}

int Pop(STACK* user_stack){
    if (user_stack->top == NULL) {
        return -1;
    }
    int data = user_stack->top->data;
    NODE* temp = user_stack->top;
    user_stack->top = user_stack->top->next;
    free(temp);
    user_stack->size--;
    return data;
}