#include <stdio.h>

//time complexity n^2

void selection_sort_ascending(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void selection_sort_descending(int arr[], int n) {
    int i, j, max_idx;
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            int temp = arr[max_idx];
            arr[max_idx] = arr[i];
            arr[i] = temp;
        }
    }
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
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int arr_ascending[n], arr_descending[n];
    for (i = 0; i < n; i++) {
        arr_ascending[i] = arr[i];
        arr_descending[i] = arr[i];
    }
    selection_sort_ascending(arr_ascending, n);
    selection_sort_descending(arr_descending, n);
    printf("Ascending order: ");
    print_array(arr_ascending, n);
    printf("Descending order: ");
    print_array(arr_descending, n);
    return 0;
}