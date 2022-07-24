// Linked list implementation of queue data structure (FIFO)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUEEMPTY INT_MIN

// Structure of node
typedef struct node
{
    int value;
    struct node* next;
    struct node* prev;
}
node;

// Struture of each queue, contains the pointer to the head and tail of queue
typedef struct queue
{
    node* head;
    node* tail;
}
queue;

// Function that initializes the head and tail pointers of queue to NULL
void initialize(queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

// Function that enqueues numbers to queue
void enqueue(queue* q, int number)
{
    // Dynamically allocate a new node and check if there is enough memory
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("OUT OF MEMORY");
        return;
    }
    // Set the nodes value equal to the number and since it goes at the end, its next pointer points to NULL
    newNode->value = number;
    newNode->next = NULL;
    
    // Check for tail, if tail is present, set the tail's next pointer to point at new node and set the new node's prev pointer to the tail
    if (q->tail != NULL)
    {
        q->tail->next = newNode;
        newNode->prev = q->tail;
    }
    // If tail is not present, set newNode prev pointer to NULL since it's the only node in queue
    else
    {
        newNode->prev = NULL;
    }
    // move tail pointer to the end
    q->tail = newNode;
    
    // Point the head at the correct node initially
    if (q->head == NULL)
    {
        q->head = newNode;
    }
    return;
}

// Function that dequeues numbers form queue
int dequeue(queue* q)
{
    // If the queue is empty, return
    if (q->head == NULL)
    {
        printf("QUEUE EMPTY\n");
        return QUEUEEMPTY;
    }
    
    // dequeued number is the value that is held by the head node
    int dequeued = q->head->value;
    
    // If more than one node is left after dequeue
    if (q->head->next != NULL)
    {
        node* trav = q->head->next;
        free(q->head);
        q->head = trav;
        q->head->prev = NULL;
    }
    // If this is last node, reset head and tail pointers back to NULL
    else
    {
        free(q->head);
        q->head = NULL;
        q->tail = NULL;
    }
    return dequeued;
}

// Function that destroys the linked list to free memory
void destroy(queue* q)
{
    while (q->head != NULL)
    {
        node* tmp = q->head->next;
        free(q->head);
        q->head = tmp;
    }
}

int main(void)
{
    // initialize queues as needed
    queue q1, q2, q3;
    
    initialize(&q1);
    initialize(&q2);
    initialize(&q3);
    
    // enqueue as needed
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    
    enqueue(&q2, 4);
    enqueue(&q2, 5);
    enqueue(&q2, 6);
    
    enqueue(&q3, 7);
    enqueue(&q3, 8);
    enqueue(&q3, 9);
    
    // dequeue as needed
    int x;
    while((x = dequeue(&q1)) != QUEUEEMPTY)
    {
        printf("Dequeued from q1: %i\n", x);
    }
    printf("\n");
    
    while((x = dequeue(&q2)) != QUEUEEMPTY)
    {
        printf("Dequeued from q2: %i\n", x);
    }
    printf("\n");
    
    while((x = dequeue(&q3)) != QUEUEEMPTY)
    {
        printf("Dequeued from q3: %i\n", x);
    }
    
    // destroy at end incase queues weren't fully dequeued previously
    destroy(&q1);
    destroy(&q2);
    destroy(&q3);
}
