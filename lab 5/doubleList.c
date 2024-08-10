#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert_node(Node** head, int data, int position) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        int i = 1;
        while (temp->next != NULL && i < position - 1) {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
    }
}

void delete_node(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    int i = 1;
    while (temp->next != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    if (node_to_delete->next != NULL) {
        node_to_delete->next->prev = temp;
    }
    free(node_to_delete);
}

void traverse(Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert_node(&head, data, i + 1);
    }

    int choice;
    while (1) {
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int data, position;
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_node(&head, data, position);
                printf("Node inserted\n");
                break;
            }
            case 2: {
                int position;
                printf("Enter position: ");
                scanf("%d", &position);
                delete_node(&head, position);
                break;
            }
            case 3: {
                printf("The list is: ");
                traverse(head);
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}