#include <stdio.h>

int main() {
    int numVertices, i, j;
    char response;

 printf("Enter number of vertex: ");
    scanf("%d", &numVertices);

    int adjMatrix[numVertices][numVertices];

    // Initialize adjacency matrix with 0
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Input adjacency information
    for (i = 0; i < numVertices; i++) {
        for (j = i + 1; j < numVertices; j++) {
            printf("Vertices %d & %d are Adjacent ? (Y/N) :", i + 1, j + 1);
            scanf(" %c", &response);
            if (response == 'y' || response == 'Y') {
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            }
        }
    }

    // Calculate and display degree of each vertex
    printf(" Vertex          Degree \n");
    for (i = 0; i < numVertices; i++) {
        int degree = 0;
        for (j = 0; j < numVertices; j++) {
            degree += adjMatrix[i][j];
        }
        printf("     %d           %d\n", i + 1, degree);
    }

    return 0;
}