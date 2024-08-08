#include <stdio.h>

// Structure to represent a sparse matrix element
typedef struct {
    int row;
    int col;
    int value;
} SparseElement;

// Function to add two sparse matrices
void addSparseMatrices(SparseElement matrix1[], SparseElement matrix2[], int m, int n, int numElements1, int numElements2) {
    SparseElement result[100]; // Assuming maximum 100 elements in the result
    int i, j, k = 0;

    // Initialize result matrix with zeros
    for (i = 0; i < m * n; i++) {
        result[i].row = 0;
        result[i].col = 0;
        result[i].value = 0;
    }

    // Add elements from matrix1 to result
    for (i = 0; i < numElements1; i++) {
        result[k].row = matrix1[i].row;
        result[k].col = matrix1[i].col;
        result[k].value = matrix1[i].value;
        k++;
    }

    // Add elements from matrix2 to result
    for (i = 0; i < numElements2; i++) {
        for (j = 0; j < k; j++) {
            if (matrix2[i].row == result[j].row && matrix2[i].col == result[j].col) {
                result[j].value += matrix2[i].value;
                break;
            }
        }
        if (j == k) {
            result[k].row = matrix2[i].row;
            result[k].col = matrix2[i].col;
            result[k].value = matrix2[i].value;
            k++;
        }
    }

    // Print the result matrix
    printf("Resultant Matrix in 3-tuple format\n");
    printf("%d\t%d\t%d\n", m, n, k);
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", result[i].row, result[i].col, result[i].value);
    }
}

int main() {
    int m, n, numElements1, numElements2, i;

    // Read sparse matrix-1
    printf("Enter sparse matrix-1 in 3-tuple format\n");
    scanf("%d%d%d", &m, &n, &numElements1);
    SparseElement matrix1[numElements1];
    for (i = 0; i < numElements1; i++) {
        scanf("%d%d%d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }

    // Read sparse matrix-2
    printf("Enter sparse matrix-2 in 3-tuple format\n");
    scanf("%d%d%d", &m, &n, &numElements2);
    SparseElement matrix2[numElements2];
    for (i = 0; i < numElements2; i++) {
        scanf("%d%d%d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }

    // Add the two sparse matrices
    addSparseMatrices(matrix1, matrix2, m, n, numElements1, numElements2);

    return 0;
}