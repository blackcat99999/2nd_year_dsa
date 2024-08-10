#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a stack node
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Define the structure for the stack
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new stack node
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new stack
Stack* createStack() {
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    if (!newStack) {
        printf("Memory error\n");
        return NULL;
    }
    newStack->top = NULL;
    return newStack;
}

// Function to push an element onto the stack
void push(Stack* stack, char data) {
    Node* newNode = createNode(data);
    if (stack->top) {
        newNode->next = stack->top;
    }
    stack->top = newNode;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    char data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = createStack();
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (infix[i] == ' ') {
            i++;
            continue;
        }

        if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->top->data != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && stack->top->data == '(') {
                pop(stack);
            }
            i++;
        } else {
            while (!isEmpty(stack) && getPrecedence(stack->top->data) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i++]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; // remove the newline character

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;
}