#include <stdio.h>
#include <stdlib.h>

int count_nonzero(int **matrix, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

void display_upper_triangular(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j > i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void display_diagonal_neighbors(int **matrix, int size) {
    printf("Elements above the main diagonal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i + 1) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");

    printf("Elements below the main diagonal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i - 1) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size of the square matrix: ");
    scanf("%d", &size);

    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int nonzero_count = count_nonzero(matrix, size);
    printf("Nonzero elements: %d\n", nonzero_count);

    printf("Upper triangular matrix:\n");
    display_upper_triangular(matrix, size);

    display_diagonal_neighbors(matrix, size);

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}