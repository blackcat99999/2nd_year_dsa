#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        (*head)->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head;
    }
}

void display_list(Node* head) {
    Node* temp = head;
    printf("Clinkedlist: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n;
    printf("Enter no.of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter info of node%d: ", i + 1);
        scanf("%d", &data);
        insert_node(&head, data);
    }
    display_list(head);
    return 0;
}