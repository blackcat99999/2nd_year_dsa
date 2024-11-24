#include <stdio.h>
#include <stdlib.h>

//seems to have unecessary complexity
//rewrite

typedef struct Node {
    int row;
    int col;
    int data;
    struct Node* next;
} Node;

typedef struct Header {
    Node* head;
} Header;

void create_header(Header headers[], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        headers[i].head = NULL;
    }
    for (int i = 0; i < cols; i++) {
        headers[rows + i].head = NULL;
    }
}

void insert_node(Header headers[], int row, int col, int data, int rows, int cols) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->data = data;
    new_node->next = headers[row].head;
    headers[row].head = new_node;

    /*new_node = (Node*)malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->data = data;
    new_node->next = headers[rows + col].head;
    headers[rows + col].head = new_node;*/
}

void display_sparse_matrix(Header headers[], int rows, int cols, int num_elements) {
    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", rows, cols, num_elements);
    for (int i = 0; i < rows; i++) {
        Node* temp = headers[i].head;
        while (temp != NULL) {
            printf("%d %d %d\n", temp->row, temp->col, temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);
    int num_elements = 0;
    Header headers[rows + cols];
    create_header(headers, rows, cols);
    int data;
    printf("Enter the elements of the sparse matrix: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &data);
            if (data != 0) {
                insert_node(headers, i, j, data, rows, cols);
                num_elements++;
            }
        }
    }
    display_sparse_matrix(headers, rows, cols, num_elements);
    return 0;
}