#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Structure to represent the priority queue
typedef struct PriorityQueue {
    Node* front;
} PriorityQueue;

// Function to create a new node
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the priority queue
void initPriorityQueue(PriorityQueue* pq) {
    pq->front = NULL;
}

// Function to enqueue an element into the priority queue
void enqueue(PriorityQueue* pq, int data, int priority) {
    Node* newNode = createNode(data, priority);
    if (pq->front == NULL || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node* temp = pq->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d enqueued with priority %d\n", data, priority);
}

// Function to dequeue an element from the priority queue
void dequeue(PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority queue is empty!\n");
        return;
    }
    Node* temp = pq->front;
    pq->front = pq->front->next;
    printf("%d dequeued with priority %d\n", temp->data, temp->priority);
    free(temp);
}

// Function to display the elements of the priority queue
void display(PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority queue is empty!\n");
        return;
    }
    Node* temp = pq->front;
    printf("Priority Queue:\n");
    printf("Priority   Item\n");
    while (temp != NULL) {
        printf("%-10d%-10d\n", temp->priority, temp->data);
        temp = temp->next;
    }
}

int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq);
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter element: ");
                int data;
                scanf("%d", &data);
                printf("Enter priority: ");
                int priority;
                scanf("%d", &priority);
                enqueue(&pq, data, priority);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}