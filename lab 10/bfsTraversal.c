#include <stdio.h>
#include <stdlib.h>

void bfs(int adjMatrix[][5], int numVertices, int startVertex) {
    int i, j;
    int visited[numVertices];
    int queue[numVertices];
    int front = 0, rear = 0;

    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Breadth First Search: ");
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (j = 0; j < numVertices; j++) {
            if (adjMatrix[vertex][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                queue[rear++] = j;
            }
        }
    }
    printf("\n");
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

    // Perform BFS traversal
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);
    startVertex--; // adjust for 0-based indexing

    bfs(adjMatrix, numVertices, startVertex);

    return 0;
}