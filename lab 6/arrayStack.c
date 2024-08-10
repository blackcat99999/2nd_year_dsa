#include <stdio.h>

#define MAX_SIZE 5

int top = -1;
int stack[MAX_SIZE];

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push %d into the stack.\n", element);
        return;
    }
    stack[++top] = element;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop from the stack.\n");
        return -1;
    }
    return stack[top--];
}

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX_SIZE - 1;
}

void traverse() {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int option, element;
    while (1) {
        printf("Main Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop();
                if (element != -1) {
                    printf("%d deleted from Stack\n", element);
                }
                break;
            case 3:
                printf("Stack empty: %s\n", is_empty() ? "True" : "False");
                break;
            case 4:
                printf("Stack full: %s\n", is_full() ? "True" : "False");
                break;
            case 5:
                traverse();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}