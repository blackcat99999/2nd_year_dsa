#include <stdio.h>

#define MAX 100

// Structure to represent a Deque
typedef struct Deque {
    int data[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Function to initialize a Deque
void initDeque(Deque* d) {
    d->front = d->rear = -1;
    d->size = 0;
}

// Function to check if the Deque is empty
int isEmpty(Deque* d) {
    return (d->size == 0);
}

// Function to check if the Deque is full
int isFull(Deque* d) {
    return (d->size == MAX);
}

// Function to insert an element at the right of the Deque
void insertRight(Deque* d, int element) {
    if (isFull(d)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(d)) {
        d->front = d->rear = 0;
    } else {
        d->rear = (d->rear + 1) % MAX;
    }
    d->data[d->rear] = element;
    d->size++;
    printf("%d inserted at right!\n", element);
}

// Function to delete an element from the left of the Deque
void deleteLeft(Deque* d) {
    if (isEmpty(d)) {
        printf("Deque is empty!\n");
        return;
    }
    int element = d->data[d->front];
    if (d->front == d->rear) {
        d->front = d->rear = -1;
    } else {
        d->front = (d->front + 1) % MAX;
    }
    d->size--;
    printf("%d deleted from left!\n", element);
}

// Function to delete an element from the right of the Deque
void deleteRight(Deque* d) {
    if (isEmpty(d)) {
        printf("Deque is empty!\n");
        return;
    }
    int element = d->data[d->rear];
    if (d->front == d->rear) {
        d->front = d->rear = -1;
    } else {
        d->rear = (d->rear - 1 + MAX) % MAX;
    }
    d->size--;
    printf("%d deleted from right!\n", element);
}

// Function to insert an element at the left of the Deque
void insertLeft(Deque* d, int element) {
    if (isFull(d)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(d)) {
        d->front = d->rear = 0;
    } else {
        d->front = (d->front - 1 + MAX) % MAX;
    }
    d->data[d->front] = element;
    d->size++;
    printf("%d inserted at left!\n", element);
}

// Function to display the elements of the Deque
void display(Deque* d) {
    if (isEmpty(d)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque: ");
    int i = d->front;
    while (i != d->rear) {
        printf("%d ", d->data[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", d->data[d->rear]);
}

// Function to implement Input-restricted Dequeue
void inputRestrictedDeque() {
    Deque d;
    initDeque(&d);
    while (1) {
        printf("\nInput restricted Dequeue Menu\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                int element;
                scanf("%d", &element);
                insertRight(&d, element);
                break;
            case 2:
                deleteLeft(&d);
                break;
            case 3:
                deleteRight(&d);
                break;
            case 4:
                display(&d);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}


        // Function to implement Output-restricted Dequeue
void outputRestrictedDeque() {
    Deque d;
    initDeque(&d);
    while (1) {
        printf("\nOutput restricted Dequeue Menu\n");
        printf("1. Insert at left\n");
        printf("2. Insert at right\n");
        printf("3. Delete from left\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                int element;
                scanf("%d", &element);
                insertLeft(&d, element);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &element);
                insertRight(&d, element);
                break;
            case 3:
                deleteLeft(&d);
                break;
            case 4:
                display(&d);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    printf("1. Input restricted Dequeue\n");
    printf("2. Output restricted Dequeue\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            inputRestrictedDeque();
            break;
        case 2:
            outputRestrictedDeque();
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}