#include <stdio.h>

void dfs(int adjMatrix[][5], int numVertices, int startVertex, int visited[]) {
    int i;
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    for (i = 0; i < numVertices; i++) {
        if (adjMatrix[startVertex][i] == 1 && visited[i] == 0) {
            dfs(adjMatrix, numVertices, i, visited);
        }
    }
}

int main() {
    int numVertices, i, j, startVertex;
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

    // Perform DFS traversal
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);
    startVertex--; // adjust for 0-based indexing

    int visited[numVertices];
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("Depth First Search: ");
    dfs(adjMatrix, numVertices, startVertex, visited);
    printf("\n");

    return 0;
}