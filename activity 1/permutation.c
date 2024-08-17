#include <stdio.h>

//The Steinhaus-Johnson-Trencher algorithm has a time complexity of O(n) 
//It generates permutations in lexicographic order.

void generate_permutations842(int arr842[], int size842) {
    int k842, j842;
    while (1) {
        // Print the current permutation
        for (int i842 = 0; i842 < size842; i842++) {
            printf("%d ", arr842[i842]);
        }
        printf("\n");

        // Step 1: Find the largest index k842 such that arr842[k842-1] < arr842[k842]
        for (k842 = size842 - 1; k842 > 0; k842--) {
            if (arr842[k842 - 1] < arr842[k842]) break;
        }
        if (k842 == 0) break; // all permutations generated

        // Step 2: Find the largest index j842 such that arr842[j842] > arr842[k842-1]
        for (j842 = size842 - 1; j842 > k842 - 1; j842--) {
            if (arr842[j842] > arr842[k842 - 1]) break;
        }

        // Step 3: Swap arr842[k842-1] and arr842[j842]
        int temp842 = arr842[k842 - 1];
        arr842[k842 - 1] = arr842[j842];
        arr842[j842] = temp842;

        // Step 4: Reverse the suffix starting at k842
        int left842 = k842, right842 = size842 - 1;
        while (left842 < right842) {
            temp842 = arr842[left842];
            arr842[left842] = arr842[right842];
            arr842[right842] = temp842;
            left842++;
            right842--;
        }
    }
}

int main() {
    int size842;
    printf("Enter the size of the array: ");
    scanf("%d", &size842);

    int arr842[size842];
    printf("Enter the elements of the array: ");
    for (int i842 = 0; i842 < size842; i842++) {
        scanf("%d", &arr842[i842]);
    }

    generate_permutations842(arr842, size842);
    return 0;
}