#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

bool isEmpty(struct Node* top) {
    return top == NULL;
}

void push(struct Node **top, int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Stack is full.\n");
    } else {
        node->data = val;
        node->next = *top;
        *top = node;
    }
}

int pop(struct Node **top) {
    if (isEmpty(*top)) {
        printf("Stack is empty.\n");
        return INT_MIN;
    } else {
        int num = (*top)->data;
        struct Node* temp = *top;
        *top = (*top)->next;

        free(temp);
        return num;
    }
}

void clearStack(struct Node **top) {
    struct Node* temp = *top;

    while (temp != NULL) {
        *top = temp;
        temp = temp->next;
        free(*top);
    }

    *top = NULL;
}

void traverse(struct Node* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }

    printf("\n");
}

int main() {
    struct Node* top = NULL;

    printf("%d is popped\n", pop(&top));

    for (int i = 0; i < 8; ++i) {
        push(&top, i *i);
    }

    for (int i = 0; i < 3; ++i) {
        printf("%d is popped\n", pop(&top));
    }

    traverse(top);

    clearStack(&top);

    printf("%d is popped\n", pop(&top));

    return 0;
}

