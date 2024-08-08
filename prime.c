#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int sum_of_primes(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        return -1;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = sum_of_primes(arr, n);
    printf("Sum = %d\n", sum);

    free(arr);

    return 0;
}