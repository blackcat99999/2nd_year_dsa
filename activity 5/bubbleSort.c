#include <stdio.h>

// Function to perform Bubble Sort with early exit flag
void bubbleSort(int arr1842[], int n1842) {
    int i1842, j1842, temp1842;
    int swapped1842;

    // Outer loop for each pass
    for (i1842 = 0; i1842 < n1842 - 1; i1842++) {
        swapped1842 = 0;  // Initialize swapped flag to 0 (no swap)

        // Inner loop for comparing adjacent elements
        for (j1842 = 0; j1842 < n1842 - i1842 - 1; j1842++) {
            // If the element is greater than the next element, swap them
            if (arr1842[j1842] > arr1842[j1842 + 1]) {
                temp1842 = arr1842[j1842];
                arr1842[j1842] = arr1842[j1842 + 1];
                arr1842[j1842 + 1] = temp1842;
                swapped1842 = 1;  // Set the swapped flag to 1 (swap occurred)
            }
        }

        // If no elements were swapped, the array is sorted, break early
        if (swapped1842 == 0) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr1842[], int n1842) {
    for (int i1842 = 0; i1842 < n1842; i1842++) {
        printf("%d ", arr1842[i1842]);
    }
    printf("\n");
}

int main() {
    int arr1842[] = {64, 34, 25, 12, 22, 11, 90};
    int n1842 = sizeof(arr1842) / sizeof(arr1842[0]);

    printf("Original array: \n");
    printArray(arr1842, n1842);

    // Perform bubble sort with early exit flag
    bubbleSort(arr1842, n1842);

    printf("Sorted array: \n");
    printArray(arr1842, n1842);

    return 0;
}
