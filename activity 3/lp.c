#include <stdio.h>

#define SIZE 7

// Function to insert a key into hash table using linear probing
void insert(int hashTable[], int size, int key) {
    int index = key % size; // Hash function h(k) = k % size

    // Linear probing if collision occurs
    while (hashTable[index] != -1) {
        index = (index + 1) % size; // Move to the next slot
    }
    hashTable[index] = key;
}

// Function to display the hash table
void display(int hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: NULL\n", i);
    }
}

int main() {
    int hashTable[SIZE];
    int keys[] = {19, 26, 13, 48, 31, 8};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Initialize hash table with -1 (indicating empty slots)
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    // Insert keys into the hash table
    for (int i = 0; i < n; i++) {
        insert(hashTable, SIZE, keys[i]);
    }

    // Display the hash table
    display(hashTable, SIZE);

    return 0;
}
