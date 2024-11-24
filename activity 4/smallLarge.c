
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_nikita_pandit_1842 {
    int data_nikita_pandit_1842;
    struct Node_nikita_pandit_1842 *left_nikita_pandit_1842, *right_nikita_pandit_1842;
    int leftCount_nikita_pandit_1842;  // Number of nodes in the left subtree
} Node_nikita_pandit_1842;

// Function prototypes
Node_nikita_pandit_1842* insert_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int data_nikita_pandit_1842);
int findKthSmallest_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int k_nikita_pandit_1842);
int findKthLargest_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int k_nikita_pandit_1842);
void inorderTraversal_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842);
void menu_nikita_pandit_1842();

int main() {
    Node_nikita_pandit_1842* root_nikita_pandit_1842 = NULL;
    int choice_nikita_pandit_1842, value_nikita_pandit_1842, k_nikita_pandit_1842;

    while (1) {
        menu_nikita_pandit_1842();
        printf("\nEnter your choice: ");
        scanf("%d", &choice_nikita_pandit_1842);
        switch (choice_nikita_pandit_1842) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value_nikita_pandit_1842);
                root_nikita_pandit_1842 = insert_nikita_pandit_1842(root_nikita_pandit_1842, value_nikita_pandit_1842);
                printf("Inserted %d\n", value_nikita_pandit_1842);
                break;
            case 2:
                printf("Enter k for k-th smallest element: ");
                scanf("%d", &k_nikita_pandit_1842);
                value_nikita_pandit_1842 = findKthSmallest_nikita_pandit_1842(root_nikita_pandit_1842, k_nikita_pandit_1842);
                if (value_nikita_pandit_1842 == -1)
                    printf("k is out of bounds\n");
                else
                    printf("The %d-th smallest element is %d\n", k_nikita_pandit_1842, value_nikita_pandit_1842);
                break;
            case 3:
                printf("Enter k for k-th largest element: ");
                scanf("%d", &k_nikita_pandit_1842);
                value_nikita_pandit_1842 = findKthLargest_nikita_pandit_1842(root_nikita_pandit_1842, k_nikita_pandit_1842);
                if (value_nikita_pandit_1842 == -1)
                    printf("k is out of bounds\n");
                else
                    printf("The %d-th largest element is %d\n", k_nikita_pandit_1842, value_nikita_pandit_1842);
                break;
            case 4:
                printf("Inorder traversal of the BST: ");
                inorderTraversal_nikita_pandit_1842(root_nikita_pandit_1842);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Menu display function
void menu_nikita_pandit_1842() {
    printf("\nBST Menu:\n");
    printf("1. Insert Element\n");
    printf("2. Find k-th Smallest Element\n");
    printf("3. Find k-th Largest Element\n");
    printf("4. Display Inorder Traversal\n");
    printf("5. Exit\n");
}

// Create a new BST node
Node_nikita_pandit_1842* createNode_nikita_pandit_1842(int data_nikita_pandit_1842) {
    Node_nikita_pandit_1842* newNode_nikita_pandit_1842 = (Node_nikita_pandit_1842*)malloc(sizeof(Node_nikita_pandit_1842));
    newNode_nikita_pandit_1842->data_nikita_pandit_1842 = data_nikita_pandit_1842;
    newNode_nikita_pandit_1842->left_nikita_pandit_1842 = newNode_nikita_pandit_1842->right_nikita_pandit_1842 = NULL;
    newNode_nikita_pandit_1842->leftCount_nikita_pandit_1842 = 0;
    return newNode_nikita_pandit_1842;
}

// Insert a new node into the BST
Node_nikita_pandit_1842* insert_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int data_nikita_pandit_1842) {
    if (root_nikita_pandit_1842 == NULL)
        return createNode_nikita_pandit_1842(data_nikita_pandit_1842);

    if (data_nikita_pandit_1842 < root_nikita_pandit_1842->data_nikita_pandit_1842) {
        root_nikita_pandit_1842->left_nikita_pandit_1842 = insert_nikita_pandit_1842(root_nikita_pandit_1842->left_nikita_pandit_1842, data_nikita_pandit_1842);
        root_nikita_pandit_1842->leftCount_nikita_pandit_1842++;  // Increment left count when adding to left subtree
    } else {
        root_nikita_pandit_1842->right_nikita_pandit_1842 = insert_nikita_pandit_1842(root_nikita_pandit_1842->right_nikita_pandit_1842, data_nikita_pandit_1842);
    }
    return root_nikita_pandit_1842;
}

// Find the k-th smallest element in the BST
int findKthSmallest_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int k_nikita_pandit_1842) {
    if (root_nikita_pandit_1842 == NULL)
        return -1;

    int count_nikita_pandit_1842 = root_nikita_pandit_1842->leftCount_nikita_pandit_1842 + 1;

    if (k_nikita_pandit_1842 == count_nikita_pandit_1842)
        return root_nikita_pandit_1842->data_nikita_pandit_1842;
    else if (k_nikita_pandit_1842 < count_nikita_pandit_1842)
        return findKthSmallest_nikita_pandit_1842(root_nikita_pandit_1842->left_nikita_pandit_1842, k_nikita_pandit_1842);
    else
        return findKthSmallest_nikita_pandit_1842(root_nikita_pandit_1842->right_nikita_pandit_1842, k_nikita_pandit_1842 - count_nikita_pandit_1842);
}

// Find the k-th largest element in the BST
int findKthLargest_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int k_nikita_pandit_1842) {
    if (root_nikita_pandit_1842 == NULL)
        return -1;

    int rightSubtreeCount_nikita_pandit_1842 = (root_nikita_pandit_1842->right_nikita_pandit_1842) ? root_nikita_pandit_1842->right_nikita_pandit_1842->leftCount_nikita_pandit_1842 + 1 : 0;
    int totalRightCount_nikita_pandit_1842 = rightSubtreeCount_nikita_pandit_1842 + 1;

    if (k_nikita_pandit_1842 == totalRightCount_nikita_pandit_1842)
        return root_nikita_pandit_1842->data_nikita_pandit_1842;
    else if (k_nikita_pandit_1842 < totalRightCount_nikita_pandit_1842)
        return findKthLargest_nikita_pandit_1842(root_nikita_pandit_1842->right_nikita_pandit_1842, k_nikita_pandit_1842);
    else
        return findKthLargest_nikita_pandit_1842(root_nikita_pandit_1842->left_nikita_pandit_1842, k_nikita_pandit_1842 - totalRightCount_nikita_pandit_1842);
}

// Inorder traversal of the BST
void inorderTraversal_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842) {
    if (root_nikita_pandit_1842 == NULL)
        return;
    inorderTraversal_nikita_pandit_1842(root_nikita_pandit_1842->left_nikita_pandit_1842);
    printf("%d ", root_nikita_pandit_1842->data_nikita_pandit_1842);
    inorderTraversal_nikita_pandit_1842(root_nikita_pandit_1842->right_nikita_pandit_1842);
}
