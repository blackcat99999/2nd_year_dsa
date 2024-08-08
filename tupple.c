#include <stdio.h>

int main() {
    int rows, cols, count = 0;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }

    int tuple[count + 1][3];
    tuple[0][0] = rows;
    tuple[0][1] = cols;
    tuple[0][2] = count;

    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("Sparse matrix in 3-tuple format:\n");
    for (int i = 0; i <= count; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", tuple[i][j]);
        }
        printf("\n");
    }

    return 0;
}