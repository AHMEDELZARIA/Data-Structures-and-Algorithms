// Array based implementation of queues data structure (FIFO), circular array implemented
#include <stdio.h>
#include <limits.h>

#define QUEUESIZE 6
#define EMPTY 0
#define QUEUE_EMPTY INT_MIN

// Tracks the index of used spots of array when circuling around
int circularIndex = 0;

// Queue structure
typedef struct
{
    int array[QUEUESIZE];
    int front;
    int size;
}
queue;

// Function that adds to the queue 
void enqueue(queue* q, int number)
{
    // Resets the fornt of the queue when necessary
    if (q->front > QUEUESIZE - 1 && q->size < QUEUESIZE)
    {
        q->front = 0;
    }
    
    // Checks for unused spots in array
    if ((q->front + q->size) > (QUEUESIZE - 1))
    {
        // If there are, place them there, update size of array, and the index tracker of the unused spots
        if (q->front != 0 && circularIndex < q->front)
        {
            q->array[circularIndex] = number;
            circularIndex++;
            q->size++;
            return;
        }
        // If not, queue is full, return message
        else
        {
            printf("QUEUE OVERFLOW\n");
            return;
        }
    }
    
    // If queue is full, return message
    if (q->size > QUEUESIZE)
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    // If not place number in correct spot and update the size of array
    else
    {
    q->array[q->front + q->size] = number;
    q->size++;
    return;
    }
}

// Function that removes from the queue
int dequeue(queue* q)
{
    // If queue is empty, return message
    if (q->size <= EMPTY)
    {
        printf("QUEUE UNDERFLOW\n");
        return INT_MIN;
    }
    
    // Else dequeue the front number and return it
    int dequeued = q->array[q->front];
    q->front++;
    // If the front index is greater than the array size, set it back to zero to represent the new beginning of queue
    if (q->front > QUEUESIZE - 1)
    {
        q->front = 0;
    }
    q->size--;
    return dequeued;
}

int main(void)
{
    // Declare and initialize properties of a queue
    queue line;
    line.front = 0;
    line.size = 0;
    
    // Enqueue and dequeue as needed
    enqueue(&line, 10);
    dequeue(&line);
}
