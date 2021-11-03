#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int rear;
    int front;
    int size;
} Queue;

Queue *createQueue(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = size;
    queue->rear = -1;
    queue->front = -1;
    queue->arr = (int *)malloc(size * sizeof(int));
    return queue;
}

bool isEmpty(Queue *queue)
{
    return queue->front == queue->rear;
}

bool isFull(Queue *queue)
{
    return queue->rear == queue->size - 1;
}

void enqueue(Queue *queue, int n)
{
    if (isFull(queue))
    {
        printf("Queue is full.\n");
    }
    else
    {
        queue->arr[++queue->rear] = n;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        int temp = queue->arr[queue->front++];
        return temp;
    }
}

void clearQueue(Queue *queue)
{
    free(queue->arr);
    free(queue);
}

int main()
{
    int size;
    scanf("%d", &size);

    Queue *queue = createQueue(size);
    printf("Popped %d\n", dequeue(queue));

    enqueue(queue, 3);
    enqueue(queue, 12);
    enqueue(queue, 14);
    enqueue(queue, 5);
    enqueue(queue, 23);

    printf("Popped %d\n", dequeue(queue));
    printf("Popped %d\n", dequeue(queue));
    printf("Popped %d\n", dequeue(queue));
    printf("Popped %d\n", dequeue(queue));
    printf("Popped %d\n", dequeue(queue));
    printf("Popped %d\n", dequeue(queue));

    clearQueue(queue);
}