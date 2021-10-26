#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int *arr;
    int top;
    int size;
};

struct Stack *createStack(int size) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int *) malloc(stack->size * sizeof(int));

    return stack;
}

bool isEmpty(struct Stack *stack) {
    return stack->top < 0;
}

bool isFull(struct Stack *stack) {
    return stack->size <= stack->top + 1;
}

void push(struct Stack *stack, int val) {
    if (isFull(stack)) {
        printf("The stack is already full.\n");
    } else {
        stack->arr[++stack->top] = val;
        printf("%d is pushed successfully.\n", val);
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty.\n");
        return -1;
    } else {
        int val = stack->arr[stack->top--];
        return val;
    }
}

void clearStack(struct Stack *stack) {
    free(stack->arr);
    free(stack);
}

int main() {
    int size;
    scanf("%d", &size);
    struct Stack *stack = createStack(size);

    for (int i = 0; i < 2; ++i) {
        printf("%d is popped.\n", pop(stack));
    }

    for (int i = 1; i < 12; ++i) {
        push(stack, i);
    }

    for (int i = 0; i < 4; ++i) {
        printf("%d is popped.\n", pop(stack));
    }

    clearStack(stack);
    return 0;
}