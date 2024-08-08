#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

void transpose(struct Element a[], struct Element b[], int r, int c) {
    int col_count[c], position[c];

    // Initialize column counts
    for (int i = 0; i < c; i++) {
        col_count[i] = 0;
    }

    // Count occurrences of each column in the original matrix
    for (int i = 0; i < r; i++) {
        col_count[a[i].col]++;
    }

    // Calculate starting positions for each column in the transposed matrix
    position[0] = 0;
    for (int i = 1; i < c; i++) {
        position[i] = position[i - 1] + col_count[i - 1];
    }

    // Transpose the matrix
    for (int i = 0; i < r; i++) {
        int j = position[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

int main() {
    int r, c, n;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &n);

    struct Element a[n], b[n];

    printf("Enter the sparse matrix in 3-tuple format:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    transpose(a, b, n, c);

    printf("\nTranspose of sparse matrix:\n");
    printf("R\tC\tElement\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", b[i].row, b[i].col, b[i].value);
    }

    return 0;
}
