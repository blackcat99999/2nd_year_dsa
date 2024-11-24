#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a cycle using Floyd's Cycle Detection algorithm
int detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Move fast pointer twice as fast as slow pointer
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1; // Cycle detected
        }
    }
    return 0; // No cycle
}

// Function to find the start of the cycle
struct Node* findCycleStart(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Move fast pointer twice as fast as slow pointer
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Find the start of the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Start of the cycle
        }
    }
    return NULL; // No cycle
}

// Function to remove the cycle in the linked list
void removeCycle(struct Node* head) {
    struct Node* cycleStart = findCycleStart(head);
    if (cycleStart == NULL) {
        printf("No cycle detected. Nothing to remove.\n");
        return;
    }

    struct Node* temp = cycleStart;
    while (temp->next != cycleStart) {
        temp = temp->next;
    }
    temp->next = NULL; // Remove the cycle
    printf("Cycle removed.\n");
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    struct Node* visited[1000];
    int visitedCount = 0;
    
    // Ensure the visited array is initialized
    for (int i = 0; i < 1000; i++) {
        visited[i] = NULL;
    }

    while (temp != NULL) {
        // Check if the current node has been visited
        for (int i = 0; i < visitedCount; i++) {
            if (visited[i] == temp) {
                printf("Cycle detected, stopping print...\n");
                return;
            }
        }
        visited[visitedCount++] = temp;

        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the program
int main() {
    // Create a linked list with a cycle
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Create a cycle for testing
    head->next->next->next->next->next = head->next->next;

    printf("Original List:\n");
    printList(head);

    // Detect and remove the cycle
    if (detectCycle(head)) {
        printf("Cycle detected.\n");
        removeCycle(head);
    } else {
        printf("No cycle detected.\n");
    }

    printf("List after removing cycle:\n");
    printList(head);

    return 0;
}
