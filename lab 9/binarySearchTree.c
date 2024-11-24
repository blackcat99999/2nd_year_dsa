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

// Function to perform preorder traversal
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform postorder traversal
void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to perform inorder traversal
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to search an element in the binary search tree
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
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
    printf("BST Created.\n");
    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Preorder\n");
        printf("2. Postorder\n");
        printf("3. Inorder\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Preorder: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("Postorder: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Enter element to search: ");
                int data;
                scanf("%d", &data);
                Node* found = searchNode(root, data);
                if (found != NULL) {
                    printf("%d found in the BST\n", data);
                } else {
                    printf("%d not found in the BST\n", data);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}