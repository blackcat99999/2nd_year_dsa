#include <stdio.h>

// Function to merge two arrays and remove duplicates
void merge_arrays842(int arr1842[], int m842, int arr2842[], int n842, int arr3842[], int *k842) {
    *k842 = 0;

    // Copy elements from arr1842 to arr3842
    for (int i842 = 0; i842 < m842; i842++) {
        arr3842[(*k842)++] = arr1842[i842];
    }

    // Merge elements from arr2842 to arr3842, removing duplicates
    for (int i842 = 0; i842 < n842; i842++) {
        int found842 = 0;
        for (int j842 = 0; j842 < *k842; j842++) {
            if (arr2842[i842] == arr3842[j842]) {
                found842 = 1;
                break;
            }
        }
        if (!found842) {
            arr3842[(*k842)++] = arr2842[i842];
        }
    }
}

int main() {
    int m842, n842;

    printf("Enter size of array 1: ");
    scanf("%d", &m842);

    printf("Enter size of array 2: ");
    scanf("%d", &n842);

    int arr1842[m842];
    int arr2842[n842];
    int arr3842[m842 + n842];

    printf("Enter elements of array 1: ");
    for (int i842 = 0; i842 < m842; i842++) {
        scanf("%d", &arr1842[i842]);
    }

    printf("Enter elements of array 2: ");
    for (int i842 = 0; i842 < n842; i842++) {
        scanf("%d", &arr2842[i842]);
    }

    int k842 = 0;
    merge_arrays842(arr1842, m842, arr2842, n842, arr3842, &k842);

    // Print the merged array
    printf("Merged array: ");
    for (int i842 = 0; i842 < k842; i842++) {
        printf("%d ", arr3842[i842]);
    }
    printf("\n");

    return 0;
}