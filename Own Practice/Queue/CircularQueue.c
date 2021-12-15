#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define queue structure
typedef struct Queue
{
    int *data;
    int size;
    int front;
    int rear;
} Queue;

// Create a new queue
Queue *createQueue(int size)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->data = malloc(size * sizeof(int));
    queue->size = size;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

// Check if queue is empty
bool isEmpty(Queue *queue)
{
    return queue->front == queue->rear;
}

// Check if queue is full
int isFull(Queue *queue)
{
    return (queue->rear + 1) % queue->size == queue->front;
}

// Add an element to the queue
void enqueue(Queue *queue, int element)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->data[queue->rear] = element;
    }
}

// Remove an element from the queue
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int element = queue->data[queue->front];
        queue->front = (queue->front + 1) % queue->size;
        return element;
    }
}

// Print the queue
void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear)
    {
        printf("%d ", queue->data[i]);
        i = (i + 1) % queue->size;
    }
    printf("%d\n", queue->data[i]);
}

// Free the queue
void freeQueue(Queue *queue)
{
    free(queue->data);
    free(queue);
}

// Main function
int main()
{
    Queue *queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    freeQueue(queue);
    return 0;
}