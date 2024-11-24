#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

void insert_at_position(DoublyLinkedList* dll, int data, int position) {
    if (position < 0) {
        printf("Error: Position cannot be negative\n");
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (dll->head == NULL || position == 0) {
        new_node->next = dll->head;
        if (dll->head) {
            dll->head->prev = new_node;
        }
        dll->head = new_node;
    } else {
        Node* current = dll->head;
        int current_position = 0;
        while (current_position < position - 1 && current->next) {
            current = current->next;
            current_position++;
        }
        if (current_position != position - 1) {
            // Append to the end of the list
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
            new_node->prev = current;
        } else {
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next) {
                current->next->prev = new_node;
            }
            current->next = new_node;
        }
    }
    printf("Node inserted\n");
}

void delete_at_position(DoublyLinkedList* dll, int position) {
    if (position < 0) {
        printf("Error: Position cannot be negative\n");
        return;
    }

    if (dll->head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    if (position == 0) {
        Node* temp = dll->head;
        dll->head = dll->head->next;
        if (dll->head) {
            dll->head->prev = NULL;
        }
        free(temp);
    } else {
        Node* current = dll->head;
        int current_position = 0;
        while (current_position < position - 1 && current->next) {
            current = current->next;
            current_position++;
        }
        if (current_position != position - 1) {
            printf("Error: Position out of range\n");
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        if (current->next) {
            current->next->prev = current;
        }
        free(temp);
    }
    printf("Node deleted\n");
}

void traverse(DoublyLinkedList* dll) {
    Node* current = dll->head;
    while (current) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int num_nodes;
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    int elements[num_nodes];
    printf("Enter the elements: ");
    for (int i = 0; i < num_nodes; i++) {
        scanf("%d", &elements[i]);
    }

    DoublyLinkedList dll;
    dll.head = NULL;

    for (int i = 0; i < num_nodes; i++) {
        insert_at_position(&dll, elements[i], i);
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int element;
            int position;
            printf("Enter element: ");
            scanf("%d", &element);
            printf("Enter position: ");
            scanf("%d", &position);
            insert_at_position(&dll, element, position);
        } else if (choice == 2) {
            int position;
            printf("Enter position: ");
            scanf("%d", &position);
            delete_at_position(&dll, position);
        } else if (choice == 3) {
            traverse(&dll);
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}