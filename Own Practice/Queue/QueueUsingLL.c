#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void enqueue(Node **front, Node **rear, int num)
{
    Node *node = (Node *) malloc(sizeof(Node));

    if (node == NULL)
    {
        printf("Queue is full.\n");
    }
    else
    {
        node->data = num;
        node->next = NULL;

        if (*front == NULL)
        {
            *front = *rear = node;
        }
        else
        {
            (*rear)->next = node;
            *rear = node;
        }
    }
}

int dequeue(Node **front, Node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        Node *temp = *front;
        *front = (*front)->next;
        int num = temp->data;
        free(temp);
        return num;
    }
}

void clearQueue(Node *front)
{
    Node *temp = front;
    while (temp != NULL)
    {
        front = temp;
        temp = temp->next;
        free(front);
    }
}

int main()
{
    Node *front = NULL;
    Node *rear = NULL;

    printf("%d is popped.\n", dequeue(&front, &rear));
    enqueue(&front, &rear, 8);
    enqueue(&front, &rear, 4);
    enqueue(&front, &rear, 13);

    printf("%d is popped.\n", dequeue(&front, &rear));
    printf("%d is popped.\n", dequeue(&front, &rear));
    printf("%d is popped.\n", dequeue(&front, &rear));
    printf("%d is popped.\n", dequeue(&front, &rear));

    clearQueue(front);
    return 0;
}