#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node *next;
};

bool isEmpty(struct Node *top) {
    return top == NULL;
}

void push(struct Node **top, char val) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Stack is full.\n");
    } else {
        node->data = val;
        node->next = *top;
        *top = node;
    }
}

void pop(struct Node **top) {
    if (isEmpty(*top)) {
        printf("Stack is empty.\n");
    } else {
        struct Node *temp = *top;
        *top = (*top)->next;

        free(temp);
    }
}

void clearStack(struct Node **top) {
    struct Node *temp = *top;

    while (temp != NULL) {
        *top = temp;
        temp = temp->next;
        free(*top);
    }

    *top = NULL;
}

bool checkMatch(const char str[]) {
    struct Node *top = NULL;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(') {
            push(&top, '(');
        } else if (str[i] == ')') {
            if (isEmpty(top)) {
                clearStack(&top);
                return false;
            } else {
                pop(&top);
            }
        }
    }

    bool empty = isEmpty(top);
    clearStack(&top);
    return empty;
}

int main() {
    char str[] = "4+ (8 + 9)";

    checkMatch(str);
    return 0;
}



