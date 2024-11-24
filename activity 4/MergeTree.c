#include <stdio.h>
#include <stdlib.h>

// Definition of a BST node
typedef struct Node_nikita_pandit_1842 {
    int data_nikita_pandit_1842;
    struct Node_nikita_pandit_1842 *left_nikita_pandit_1842, *right_nikita_pandit_1842;
} Node_nikita_pandit_1842;

// Function prototypes
Node_nikita_pandit_1842* insert_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int data_nikita_pandit_1842);
void storeInorder_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int* arr_nikita_pandit_1842, int* index_nikita_pandit_1842);
int* mergeArrays_nikita_pandit_1842(int* arr1_nikita_pandit_1842, int n1_nikita_pandit_1842, int* arr2_nikita_pandit_1842, int n2_nikita_pandit_1842, int* n3_nikita_pandit_1842);
Node_nikita_pandit_1842* sortedArrayToBST_nikita_pandit_1842(int* arr_nikita_pandit_1842, int start_nikita_pandit_1842, int end_nikita_pandit_1842);
Node_nikita_pandit_1842* mergeBSTs_nikita_pandit_1842(Node_nikita_pandit_1842* root1_nikita_pandit_1842, Node_nikita_pandit_1842* root2_nikita_pandit_1842);
void inorderTraversal_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842);
void menu_nikita_pandit_1842();

int main() {
    Node_nikita_pandit_1842* root1_nikita_pandit_1842 = NULL;
    Node_nikita_pandit_1842* root2_nikita_pandit_1842 = NULL;
    Node_nikita_pandit_1842* mergedRoot_nikita_pandit_1842 = NULL;
    int choice_nikita_pandit_1842, value_nikita_pandit_1842;

    while (1) {
        menu_nikita_pandit_1842();
        printf("\nEnter your choice: ");
        scanf("%d", &choice_nikita_pandit_1842);
        switch (choice_nikita_pandit_1842) {
            case 1:
                printf("Enter value to insert into first BST: ");
                scanf("%d", &value_nikita_pandit_1842);
                root1_nikita_pandit_1842 = insert_nikita_pandit_1842(root1_nikita_pandit_1842, value_nikita_pandit_1842);
                printf("Inserted %d into first BST\n", value_nikita_pandit_1842);
                break;
            case 2:
                printf("Enter value to insert into second BST: ");
                scanf("%d", &value_nikita_pandit_1842);
                root2_nikita_pandit_1842 = insert_nikita_pandit_1842(root2_nikita_pandit_1842, value_nikita_pandit_1842);
                printf("Inserted %d into second BST\n", value_nikita_pandit_1842);
                break;
            case 3:
                mergedRoot_nikita_pandit_1842 = mergeBSTs_nikita_pandit_1842(root1_nikita_pandit_1842, root2_nikita_pandit_1842);
                printf("Merged BST (Inorder Traversal): ");
                inorderTraversal_nikita_pandit_1842(mergedRoot_nikita_pandit_1842);
                printf("\n");
                break;
            case 4:
                printf("Inorder traversal of the first BST: ");
                inorderTraversal_nikita_pandit_1842(root1_nikita_pandit_1842);
                printf("\n");
                printf("Inorder traversal of the second BST: ");
                inorderTraversal_nikita_pandit_1842(root2_nikita_pandit_1842);
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
    printf("\nBST Merge Menu:\n");
    printf("1. Insert into first BST\n");
    printf("2. Insert into second BST\n");
    printf("3. Merge BSTs and display merged BST\n");
    printf("4. Display inorder traversal of both BSTs\n");
    printf("5. Exit\n");
}

// Create a new BST node
Node_nikita_pandit_1842* createNode_nikita_pandit_1842(int data_nikita_pandit_1842) {
    Node_nikita_pandit_1842* newNode_nikita_pandit_1842 = (Node_nikita_pandit_1842*)malloc(sizeof(Node_nikita_pandit_1842));
    newNode_nikita_pandit_1842->data_nikita_pandit_1842 = data_nikita_pandit_1842;
    newNode_nikita_pandit_1842->left_nikita_pandit_1842 = newNode_nikita_pandit_1842->right_nikita_pandit_1842 = NULL;
    return newNode_nikita_pandit_1842;
}

// Insert a new node into the BST
Node_nikita_pandit_1842* insert_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int data_nikita_pandit_1842) {
    if (root_nikita_pandit_1842 == NULL)
        return createNode_nikita_pandit_1842(data_nikita_pandit_1842);
    if (data_nikita_pandit_1842 < root_nikita_pandit_1842->data_nikita_pandit_1842)
        root_nikita_pandit_1842->left_nikita_pandit_1842 = insert_nikita_pandit_1842(root_nikita_pandit_1842->left_nikita_pandit_1842, data_nikita_pandit_1842);
    else
        root_nikita_pandit_1842->right_nikita_pandit_1842 = insert_nikita_pandit_1842(root_nikita_pandit_1842->right_nikita_pandit_1842, data_nikita_pandit_1842);
    return root_nikita_pandit_1842;
}

// Store inorder traversal of BST in an array
void storeInorder_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842, int* arr_nikita_pandit_1842, int* index_nikita_pandit_1842) {
    if (root_nikita_pandit_1842 == NULL)
        return;
    storeInorder_nikita_pandit_1842(root_nikita_pandit_1842->left_nikita_pandit_1842, arr_nikita_pandit_1842, index_nikita_pandit_1842);
    arr_nikita_pandit_1842[(*index_nikita_pandit_1842)++] = root_nikita_pandit_1842->data_nikita_pandit_1842;
    storeInorder_nikita_pandit_1842(root_nikita_pandit_1842->right_nikita_pandit_1842, arr_nikita_pandit_1842, index_nikita_pandit_1842);
}

// Merge two sorted arrays into one
int* mergeArrays_nikita_pandit_1842(int* arr1_nikita_pandit_1842, int n1_nikita_pandit_1842, int* arr2_nikita_pandit_1842, int n2_nikita_pandit_1842, int* n3_nikita_pandit_1842) {
    *n3_nikita_pandit_1842 = n1_nikita_pandit_1842 + n2_nikita_pandit_1842;
    int* mergedArr_nikita_pandit_1842 = (int*)malloc((*n3_nikita_pandit_1842) * sizeof(int));
    int i_nikita_pandit_1842 = 0, j_nikita_pandit_1842 = 0, k_nikita_pandit_1842 = 0;

    while (i_nikita_pandit_1842 < n1_nikita_pandit_1842 && j_nikita_pandit_1842 < n2_nikita_pandit_1842) {
        if (arr1_nikita_pandit_1842[i_nikita_pandit_1842] < arr2_nikita_pandit_1842[j_nikita_pandit_1842])
            mergedArr_nikita_pandit_1842[k_nikita_pandit_1842++] = arr1_nikita_pandit_1842[i_nikita_pandit_1842++];
        else
            mergedArr_nikita_pandit_1842[k_nikita_pandit_1842++] = arr2_nikita_pandit_1842[j_nikita_pandit_1842++];
    }

    while (i_nikita_pandit_1842 < n1_nikita_pandit_1842)
        mergedArr_nikita_pandit_1842[k_nikita_pandit_1842++] = arr1_nikita_pandit_1842[i_nikita_pandit_1842++];

    while (j_nikita_pandit_1842 < n2_nikita_pandit_1842)
        mergedArr_nikita_pandit_1842[k_nikita_pandit_1842++] = arr2_nikita_pandit_1842[j_nikita_pandit_1842++];

    return mergedArr_nikita_pandit_1842;
}

// Convert sorted array to a balanced BST
Node_nikita_pandit_1842* sortedArrayToBST_nikita_pandit_1842(int* arr_nikita_pandit_1842, int start_nikita_pandit_1842, int end_nikita_pandit_1842) {
    if (start_nikita_pandit_1842 > end_nikita_pandit_1842)
        return NULL;

    int mid_nikita_pandit_1842 = (start_nikita_pandit_1842 + end_nikita_pandit_1842) / 2;
    Node_nikita_pandit_1842* root_nikita_pandit_1842 = createNode_nikita_pandit_1842(arr_nikita_pandit_1842[mid_nikita_pandit_1842]);
    root_nikita_pandit_1842->left_nikita_pandit_1842 = sortedArrayToBST_nikita_pandit_1842(arr_nikita_pandit_1842, start_nikita_pandit_1842, mid_nikita_pandit_1842 - 1);
    root_nikita_pandit_1842->right_nikita_pandit_1842 = sortedArrayToBST_nikita_pandit_1842(arr_nikita_pandit_1842, mid_nikita_pandit_1842 + 1, end_nikita_pandit_1842);
    return root_nikita_pandit_1842;
}

// Merge two BSTs into a balanced BST
Node_nikita_pandit_1842* mergeBSTs_nikita_pandit_1842(Node_nikita_pandit_1842* root1_nikita_pandit_1842, Node_nikita_pandit_1842* root2_nikita_pandit_1842) {
    int n1_nikita_pandit_1842 = 0, n2_nikita_pandit_1842 = 0, n3_nikita_pandit_1842 = 0;

    // Store inorders of the two BSTs
    int* arr1_nikita_pandit_1842 = (int*)malloc(1000 * sizeof(int)); // assuming max size
    int* arr2_nikita_pandit_1842 = (int*)malloc(1000 * sizeof(int)); // assuming max size
    storeInorder_nikita_pandit_1842(root1_nikita_pandit_1842, arr1_nikita_pandit_1842, &n1_nikita_pandit_1842);
    storeInorder_nikita_pandit_1842(root2_nikita_pandit_1842, arr2_nikita_pandit_1842, &n2_nikita_pandit_1842);

    // Merge two sorted arrays
    int* mergedArr_nikita_pandit_1842 = mergeArrays_nikita_pandit_1842(arr1_nikita_pandit_1842, n1_nikita_pandit_1842, arr2_nikita_pandit_1842, n2_nikita_pandit_1842, &n3_nikita_pandit_1842);

    // Free memory for arr1 and arr2
    free(arr1_nikita_pandit_1842);
    free(arr2_nikita_pandit_1842);

    // Build and return balanced BST from merged array
    Node_nikita_pandit_1842* mergedBST_nikita_pandit_1842 = sortedArrayToBST_nikita_pandit_1842(mergedArr_nikita_pandit_1842, 0, n3_nikita_pandit_1842 - 1);
    free(mergedArr_nikita_pandit_1842);
    return mergedBST_nikita_pandit_1842;
}

// Inorder traversal of the BST
void inorderTraversal_nikita_pandit_1842(Node_nikita_pandit_1842* root_nikita_pandit_1842) {
    if (root_nikita_pandit_1842 == NULL)
        return;
    inorderTraversal_nikita_pandit_1842(root_nikita_pandit_1842->left_nikita_pandit_1842);
    printf("%d ", root_nikita_pandit_1842->data_nikita_pandit_1842);
    inorderTraversal_nikita_pandit_1842(root_nikita_pandit_1842->right_nikita_pandit_1842);
}

