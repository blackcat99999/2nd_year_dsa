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
        for (j = 0; j < numVertices; j++) {
            if (i != j) {
                printf("Vertices %d & %d are Adjacent ? (Y/N) :", i + 1, j + 1);
                scanf(" %c", &response);
                if (response == 'y' || response == 'Y') {
                    adjMatrix[i][j] = 1;
                }
            }
        }
    }

    // Calculate and display degree of each vertex
    printf(" Vertex          In_Degree       Out_Degree      Total_Degree \n");
    for (i = 0; i < numVertices; i++) {
        int inDegree = 0, outDegree = 0;
        for (j = 0; j < numVertices; j++) {
            if (adjMatrix[j][i] == 1) {
                inDegree++;
            }
            if (adjMatrix[i][j] == 1) {
                outDegree++;
            }
        }
        printf("     %d              %d               %d               %d\n", i + 1, inDegree, outDegree, inDegree + outDegree);
    }

    return 0;
}