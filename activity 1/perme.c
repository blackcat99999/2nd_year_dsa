#include <stdio.h>

void generate_permutations(int arr[], int size, int n) {
    if (n == 1) {
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        generate_permutations(arr, size, n - 1);

        if (i % 2 == 0) {
            int temp = arr[n - 1];
            arr[n - 1] = arr[i];
            arr[i] = temp;
        } else {
            int temp = arr[0];
            arr[0] = arr[n - 1];
            arr[n - 1] = temp;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    generate_permutations(arr, size, size);
    return 0;
}