#include <stdio.h>

#define MAX 100

void enqueue(int[], int*, int*, int);
void dequeue(int[], int*, int*);
void traverse(int[], int, int);
int isEmpty(int, int);
int isFull(int, int, int);

int main() {
    int queue[MAX];
    int front = 0, rear = 0, size;

    printf("Enter Queue size: ");
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
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (!isFull(front, rear, size)) {
                    int element;
                    printf("Enter element: ");
                    scanf("%d", &element);
                    enqueue(queue, &front, &rear, element);
                } else {
                    printf("Queue is Full!\n");
                }
                break;
            case 2:
                if (!isEmpty(front, rear)) {
                    dequeue(queue, &front, &rear);
                } else {
                    printf("Queue is Empty!\n");
                }
                break;
            case 3:
                if (isEmpty(front, rear)) {
                    printf("Queue Empty: True\n");
                } else {
                    printf("Queue Empty: False\n");
                }
                break;
            case 4:
                if (isFull(front, rear, size)) {
                    printf("Queue is Full!\n");
                } else {
                    printf("Queue is not Full!\n");
                }
                break;
            case 5:
                traverse(queue, front, rear);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}

void enqueue(int queue[], int* front, int* rear, int element) {
    if ((*rear + 1) % MAX == *front) {
        printf("Queue is Full!\n");
        return;
    }

    queue[(*rear)++ % MAX] = element;
    printf("Element %d enqueued!\n", element);
}

void dequeue(int queue[], int* front, int* rear) {
    if (*front == *rear) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Element deleted!\n");
    (*front) = (*front + 1) % MAX;
}

void traverse(int queue[], int front, int rear) {
    if (front == rear) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("CQueue: ");
    if (rear > front) {
        for (int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i < rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int isEmpty(int front, int rear) {
    return (front == rear);
}

int isFull(int front, int rear, int size) {
    return ((rear + 1) % size == front);
}