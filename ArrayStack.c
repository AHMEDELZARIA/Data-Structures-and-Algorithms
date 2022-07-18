// Array based implementation of stack data structure, LIFO
#include <stdio.h>
#include <limits.h>

#define STACKSIZE 10
#define EMPTY 0
#define STACK_EMPTY INT_MIN

// Structure of stack
typedef struct 
{
    int array[STACKSIZE];
    int top;
}
stack;

// Function that effectively pushes on new values following a LIFO procedure
void push(stack* s, int number)
{
    // Check if stack is full, if full, return
    if (s->top > (STACKSIZE - 1))
    {
        return;
    }
    
    // If stack not full, place the value into onto the top index of the stack
    s->array[s->top] = number;
    // Increment top counter by one, this will be the index of the next placed value
    s->top++;
    return;
}

// Function that effectively pops values from stack, returning the value that was taken out
int pop(stack* s)
{
    // Decrement the top counter by one, this ensures we take out the value that is on the top of the stack
    s->top--;
    // If stack is empty, return 
    if (s->top < EMPTY)
    {
        return INT_MIN;
    }
    
    // If stack not empty, return the value that is on top of the stack that will be taken out 
    int popped = s->array[s->top];
    return popped;
}

int main(void)
{
    // Create a stack
    stack n;
    // Initialize the top counter to 0 to represent the first index of the empty array
    n.top = 0;
    
    // Effectively push values onto stack
    push(&n, 45);
    push(&n, 30);
    push(&n, 20);
    
    // Effectively pop values off of stack and return the value popped
    while (n.top > EMPTY)
    {
        int x = pop(&n);
        
        printf("Popped = %i\n", x);
    }
}
