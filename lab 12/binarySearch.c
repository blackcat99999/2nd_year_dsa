#include <stdio.h>

void binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Element found\n");
            return;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element not found\n");
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter no.of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in ascending order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array: ");
    print_array(arr, n);
    int key;
    printf("Enter element to be searched: ");
    scanf("%d", &key);
    binary_search(arr, n, key);
    return 0;
}