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

void insert_node(Node** head, int data, int position) {
    Node* new_node = create_node(data);
    if (*head == NULL || position == 1) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node* temp = *head;
        for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_node(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);
}

int count_nodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void traverse(Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int search(Node* head, int data) {
    int position = 1;
    while (head != NULL) {
        if (head->data == data) {
            return position;
        }
        position++;
        head = head->next;
    }
    return -1;
}

void sort(Node** head) {
    int swapped;
    Node* temp = *head;
    Node* index = NULL;
    int temp_data;
    if (*head == NULL)
        return;
    do {
        swapped = 0;
        temp = *head;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                temp_data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp_data;
                swapped = 1;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void reverse(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Node* head = NULL;
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert_node(&head, data, i + 1);
    }
    int choice;
    while (1) {
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
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
                printf("The total number of nodes: %d\n", count_nodes(head));
                break;
                       case 4: {
                printf("The list is: ");
                traverse(head);
                break;
            }
            case 5: {
                int data;
                printf("Enter element to be searched: ");
                scanf("%d", &data);
                int position = search(head, data);
                if (position != -1) {
                    printf("Element found at node-%d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
            }
            case 6: {
                sort(&head);
                printf("List sorted\n");
                break;
            }
            case 7: {
                reverse(&head);
                printf("Reverse list: ");
                traverse(head);
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}