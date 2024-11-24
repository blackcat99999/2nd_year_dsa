#include <stdio.h>
#include <stdlib.h>

// Node structure for separate chaining
struct Node {
    int key;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Insert key into hash table using separate chaining
void insert(struct Node* hashTable[], int size, int key) {
    int index = key % size; // Hash function h(k) = k % size
    struct Node* newNode = createNode(key);
    
    // Insert at the beginning of the list (can also be inserted at the end)
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Display the hash table with separate chaining
void display(struct Node* hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int size = 7; // Hash table size
    int keys[] = {19, 26, 13, 48, 31, 8}; // Keys to insert
    int n = sizeof(keys) / sizeof(keys[0]);

    // Initialize hash table with NULL
    struct Node* hashTable[7] = {NULL};

    // Insert keys into the hash table
    for (int i = 0; i < n; i++) {
        insert(hashTable, size, keys[i]);
    }

    // Display the hash table
    display(hashTable, size);

    return 0;
}
