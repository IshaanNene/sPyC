
#ifndef STACK_LIBRARY_H
#define STACK_LIBRARY_H

#include <stdbool.h>

typedef struct Node NODE;
typedef struct Stack STACK;

/**
 * Initializes a new stack with the specified capacity
 * @param capacity Maximum number of elements the stack can hold
 * @return Pointer to the newly created stack, or NULL if allocation fails
 */
STACK* Initialize_Stack(int capacity);

/**
 * Pushes an element onto the top of the stack
 * @param user_stack Pointer to the stack
 * @param top The integer value to be pushed
 */
void Push(STACK* user_stack, int top);

/**
 * Removes and returns the element from the top of the stack
 * @param user_stack Pointer to the stack
 * @return The popped element, or -1 if stack is empty
 */
int Pop(STACK* user_stack);

#endif // STACK_LIBRARY_H