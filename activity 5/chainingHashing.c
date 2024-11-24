#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the hash table
#define SIZE1842 7

// Node structure for linked list (chaining)
struct Node1842 {
    int key1842;
    struct Node1842* next1842;
};

// Hash Table
struct HashTable1842 {
    struct Node1842* table1842[SIZE1842];
};

// Initialize the hash table
void init_table1842(struct HashTable1842* ht1842) {
    for (int i1842 = 0; i1842 < SIZE1842; i1842++) {
        ht1842->table1842[i1842] = NULL;
    }
}

// Hash function to map values to keys
int hash1842(int key1842) {
    return key1842 % SIZE1842;
}

// Insert a key into the hash table
void insert1842(struct HashTable1842* ht1842, int key1842) {
    int index1842 = hash1842(key1842);
    struct Node1842* new_node1842 = (struct Node1842*)malloc(sizeof(struct Node1842));
    new_node1842->key1842 = key1842;
    new_node1842->next1842 = ht1842->table1842[index1842];
    ht1842->table1842[index1842] = new_node1842;
}

// Display the hash table
void display1842(struct HashTable1842* ht1842) {
    for (int i1842 = 0; i1842 < SIZE1842; i1842++) {
        printf("Index %d: ", i1842);
        struct Node1842* temp1842 = ht1842->table1842[i1842];
        while (temp1842 != NULL) {
            printf("%d -> ", temp1842->key1842);
            temp1842 = temp1842->next1842;
        }
        printf("NULL\n");
    }
}

// Find the maximum chain length
int max_chain_length1842(struct HashTable1842* ht1842) {
    int max1842 = 0;
    for (int i1842 = 0; i1842 < SIZE1842; i1842++) {
        int length1842 = 0;
        struct Node1842* temp1842 = ht1842->table1842[i1842];
        while (temp1842 != NULL) {
            length1842++;
            temp1842 = temp1842->next1842;
        }
        if (length1842 > max1842) {
            max1842 = length1842;
        }
    }
    return max1842;
}

// Find the minimum chain length
int min_chain_length1842(struct HashTable1842* ht1842) {
    int min1842 = SIZE1842;  // Initialize with the maximum possible number of chains
    for (int i1842 = 0; i1842 < SIZE1842; i1842++) {
        int length1842 = 0;
        struct Node1842* temp1842 = ht1842->table1842[i1842];
        while (temp1842 != NULL) {
            length1842++;
            temp1842 = temp1842->next1842;
        }
        if (length1842 > 0 && length1842 < min1842) {
            min1842 = length1842;
        }
    }
    return min1842;
}

// Calculate the average chain length
float average_chain_length1842(struct HashTable1842* ht1842) {
    int totalLength1842 = 0;
    int nonEmptyChains1842 = 0;
    
    for (int i1842 = 0; i1842 < SIZE1842; i1842++) {
        int length1842 = 0;
        struct Node1842* temp1842 = ht1842->table1842[i1842];
        while (temp1842 != NULL) {
            length1842++;
            temp1842 = temp1842->next1842;
        }
        if (length1842 > 0) {
            totalLength1842 += length1842;
            nonEmptyChains1842++;
        }
    }
    
    return nonEmptyChains1842 == 0 ? 0 : (float)totalLength1842 / nonEmptyChains1842;
}

int main() {
    struct HashTable1842 ht1842;
    init_table1842(&ht1842);
    
    int keys1842[] = {5, 28, 19, 15, 20, 33, 12, 17, 10};
    int n1842 = sizeof(keys1842) / sizeof(keys1842[0]);
    
    // Insert keys into the hash table
    for (int i1842 = 0; i1842 < n1842; i1842++) {
        insert1842(&ht1842, keys1842[i1842]);
    }
    
    // Display hash table
    display1842(&ht1842);
    
    // Calculate max, min, and average chain lengths
    printf("Max chain length: %d\n", max_chain_length1842(&ht1842));
    printf("Min chain length: %d\n", min_chain_length1842(&ht1842));
    printf("Average chain length: %.2f\n", average_chain_length1842(&ht1842));
    
    return 0;
}
