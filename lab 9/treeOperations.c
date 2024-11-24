#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the largest element in the binary search tree
Node* findLargest(Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return findLargest(root->right);
}

// Function to find the smallest element in the binary search tree
Node* findSmallest(Node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return findSmallest(root->left);
}

// Function to calculate the height of a node in the binary search tree
int calculateHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to count the number of leaf nodes in the binary search tree
int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Node* root = NULL;
    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    
    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Insert\n");
        printf("2. Largest\n");
        printf("3. Smallest\n");
        printf("4. Height\n");
        printf("5. Count leaf nodes\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1: {
                printf("Enter element to insert in BST: ");
                int data;
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            }
            case 2: {
                Node* largest = findLargest(root);
                if (largest) {
                    printf("Largest element in BST = %d\n", largest->data);
                } else {
                    printf("BST is empty.\n");
                }
                break;
            }
            case 3: {
                Node* smallest = findSmallest(root);
                if (smallest) {
                    printf("Smallest element in BST = %d\n", smallest->data);
                } else {
                    printf("BST is empty.\n");
                }
                break;
            }
            case 4: {
                printf("Enter node to find height: ");
                int node;
                scanf("%d", &node);
                Node* temp = root;
                while (temp != NULL) {
                    if (temp->data == node) {
                        int height = calculateHeight(temp);
                        printf("Height of %d = %d\n", node, height);
                        break;
                    } else if (temp->data < node) {
                        temp = temp->right;
                    } else {
                        temp = temp->left;
                    }
                }
                if (temp == NULL) {
                    printf("%d not found in BST\n", node);
                }
                break;
            }
            case 5: {
                int leafCount = countLeafNodes(root);
                printf("Number of leaf nodes in BST = %d\n", leafCount);
                break;
            }
            case 6:
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}
