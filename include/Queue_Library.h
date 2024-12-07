#ifndef QUEUE_LIBRARY_H
#define QUEUE_LIBRARY_H

#include <stdbool.h>

typedef struct Node NODE;
typedef struct Queue QUEUE;

/**
 * Initializes a new queue with the specified capacity
 * @param capacity Maximum number of elements the queue can hold
 * @return Pointer to the newly created queue, or NULL if allocation fails
 */
QUEUE* Initialize_Queue(int capacity);

/**
 * Adds an element to the rear of the queue
 * @param user_queue Pointer to the queue
 * @param data The integer value to be added
 */
void Enqueue(QUEUE* user_queue, int data);

/**
 * Removes and returns the element from the front of the queue
 * @param user_queue Pointer to the queue
 * @return The removed element, or -1 if queue is empty
 */
int Dequeue(QUEUE* user_queue);

/**
 * Checks if the queue is empty
 * @param user_queue Pointer to the queue
 * @return true if queue is empty, false otherwise
 */
bool Is_Empty(QUEUE* user_queue);

/**
 * Checks if the queue is full
 * @param user_queue Pointer to the queue
 * @return true if queue is full, false otherwise
 */
bool Is_Full(QUEUE* user_queue);

/**
 * Returns the current number of elements in the queue
 * @param user_queue Pointer to the queue
 * @return Number of elements in the queue
 */
int Queue_Size(QUEUE* user_queue);

#endif