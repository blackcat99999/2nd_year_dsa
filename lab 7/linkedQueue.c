#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for a queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (!q) {
        printf("Memory error\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to add an element to the queue
void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->rear) {
        q->rear->next = newNode;
        q->rear = newNode;
    } else {
        q->front = q->rear = newNode;
    }
    printf("Element %d enqueued!\n", data);
}

// Function to remove an element from the queue
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("Element deleted!\n");
}

// Function to print the elements of the queue
void traverse(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    int choice, data;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");

        printf("\nEnter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                if (isEmpty(q)) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Queue is not empty!\n");
                }
                break;
            case 4:
                traverse(q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}