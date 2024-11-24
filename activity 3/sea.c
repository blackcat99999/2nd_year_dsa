#include <stdio.h>

// Function declarations
int linearSearch(int arr[], int n, int x);
int sequentialSearch(int arr[], int n, int x);
int binarySearchNonRecursive(int arr[], int n, int x);
int binarySearchRecursive(int arr[], int low, int high, int x);
void sortArray(int arr[], int n);  // To sort array for binary search

int main() {
    int choice, n, x, result;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search (Non-Recursive)\n");
        printf("3. Binary Search (Recursive)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 5) {
            break;
        }
        
        

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &x);
                result = linearSearch(arr, n, x);
                if (result != -1)
                    printf("Element found at index %d\n", result);
                else
                    printf("Element not found\n");
                break;
                
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &x);
                sortArray(arr, n); // Ensure array is sorted for binary search
                result = binarySearchNonRecursive(arr, n, x);
                if (result != -1)
                    printf("Element found at index %d\n", result);
                else
                    printf("Element not found\n");
                break;
                
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &x);
                sortArray(arr, n); // Ensure array is sorted for binary search
                result = binarySearchRecursive(arr, 0, n - 1, x);
                if (result != -1)
                    printf("Element found at index %d\n", result);
                else
                    printf("Element not found\n");
                break;

            case 4:
                printf("Exiting...\n");
                return 0;
                break;
                
            default:
                printf("Invalid choice!\n");
        }
        
    } while (choice != 5);
    
    return 0;
}

// Linear Search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}


// Binary Search (Non-Recursive)
int binarySearchNonRecursive(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;
}

// Binary Search (Recursive)
int binarySearchRecursive(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearchRecursive(arr, low, mid - 1, x);
        return binarySearchRecursive(arr, mid + 1, high, x);
    }
    
    return -1;
}

// Function to sort array (for binary search)
void sortArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
