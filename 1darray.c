#include <stdio.h>
#include <stdlib.h>

void insert_element(int **arr, int *n, int element, int position) {

    *arr = realloc(*arr, (*n + 1) * sizeof(int));

    
    for (int i = *n; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    
    (*arr)[position] = element;

    
    (*n)++;
}


void delete_element(int **arr, int *n, int position) {
    
    if (position < *n) {
        
        for (int i = position; i < *n - 1; i++) {
            (*arr)[i] = (*arr)[i + 1];
        }

        
        (*n)--;
    } else {
        printf("Invalid position\n");
    }
}


int linear_search(int *arr, int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}


void traverse_array(int *arr, int n) {
    printf("Array Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size n: ");
    scanf("%d", &n);

   
    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter element of array: \n");
    for (int i = 0; i < n; i++) {
        printf("Enter Array elements: ");
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int element, position;
                printf("Element to insert: ");
                scanf("%d", &element);
                printf("Enter Position: ");
                scanf("%d", &position);
                insert_element(&arr, &n, element, position);
                printf("Element inserted\n");
                break;
            }
            case 2: {
                int position;
                printf("Enter Position to delete: ");
                scanf("%d", &position);
                delete_element(&arr, &n, position);
                printf("Element deleted\n");
                break;
            }
            case 3: {
                int element;
                printf("Element to search: ");
                scanf("%d", &element);
                int position = linear_search(arr, n, element);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
            }
            case 4:
                traverse_array(arr, n);
                break;
            case 5:
                free(arr);
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}