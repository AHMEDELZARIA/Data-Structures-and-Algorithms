// Linked list based implentation of stack data structure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STACK_EMPTY INT_MIN

// Structure of each node in linked list
typedef struct node
{
    int value;
    struct node* next;
}
node;

// stack, is the same a pointer to a node, which is the head of the linked lists
typedef node* stack;

// Function that accepts the pointer to the head of a stack and a value to push onto a stack
void push(stack* mystack, int number)
{
    // Dynamically allocate a new node
    node* newNode = malloc(sizeof(node));
    // check to see if computer has enough memory
    if (newNode == NULL)
    {
        printf("Stack Overflow.\n");
        return;
    }
    // If all is good, set the nodes value to equal the number and connect the node to the head of the list, then set the head of the list equal to the new node created
    newNode->value = number;
    newNode->next = *mystack;
    *mystack = newNode;
    return;
}

// Function that accepts a pointer to the head of the stack and effectively pops off values from stack and returns the popped value
int pop(stack* mystack)
{
    // If the list is empty, then return STACK_EMPTY
    if (*mystack == NULL)
    {
        //printf("Stack Underflow.\n");
        return STACK_EMPTY;
    }
    // If list isn't empty, declare and initialize a node pointer equal to current head of list, change the head of the list to the next node, free the old head, return popped value
    int popped = (*mystack)->value;
    node* trav = (*mystack);
    *mystack = (*mystack)->next;
    free(trav);
    trav = NULL;
    return popped;
}

int main (void)
{
    // Declare and initialize three head pointers to NULL, each pointing to a different stack
    stack s1 = NULL, s2 = NULL, s3 = NULL;
    // Effectively push values onto stack
    push(&s1, 25);
    push(&s1, 35);
    push(&s2, 50);
    push(&s2, 20);
    push(&s3, 10);
    push(&s3, 60);
    push(&s3, 70);
    
    // effectively pop values off of stacks and return popped values
    int x;
    while ((x = pop(&s1)) != STACK_EMPTY)
    {
        printf("Popped: %i\n", x);
    }
    
    while ((x = pop(&s2)) != STACK_EMPTY)
    {
        printf("Popped: %i\n", x);
    }
    
    while ((x = pop(&s3)) != STACK_EMPTY)
    {
        printf("Popped: %i\n", x);
    }
}
