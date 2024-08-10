#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int);
void dequeue();
void traverse();
int isEmpty();
int isFull();

int main() {
    int size, choice;

    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");

        printf("\nEnter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isFull()) {
                    int element;
                    printf("Enter element: ");
                    scanf("%d", &element);
                    enqueue(element);
                } else {
                    printf("Queue is Full!\n");
                }
                break;
            case 2:
                if (!isEmpty()) {
                    dequeue();
                } else {
                    printf("Queue is Empty!\n");
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is Empty!\n");
                } else {
                    printf("Queue is not Empty!\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Queue is Full!\n");
                } else {
                    printf("Queue is not Full!\n");
                }
                break;
            case 5:
                traverse();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is Full!\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    queue[++rear] = value;
    printf("Element %d enqueued!\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Element deleted!\n");
    front++;
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

int isFull() {
    if (rear == MAX - 1) {
        return 1;
    }
    return 0;
}