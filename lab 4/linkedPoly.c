#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

Node* create_node(int coefficient, int exponent) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node** head, int coefficient, int exponent) {
    Node* new_node = create_node(coefficient, exponent);
    if (*head == NULL || exponent > (*head)->exponent) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL && temp->next->exponent > exponent) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void print_polynomial(Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coefficient, head->exponent);
        head = head->next;
        if (head != NULL) {
            printf("+");
        }
    }
    printf("\n");
}

Node* add_polynomials(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exponent > temp2->exponent) {
            insert_node(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            insert_node(&result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            insert_node(&result, temp1->coefficient + temp2->coefficient, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL) {
        insert_node(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        insert_node(&result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }
    return result;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* result = NULL;

    int max_power1, max_power2;
    printf("Polynomial-1:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &max_power1);
    for (int i = max_power1; i >= 0; i--) {
        int coefficient;
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coefficient);
        insert_node(&head1, coefficient, i);
    }

    printf("Polynomial-2:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &max_power2);
    for (int i = max_power2; i >= 0; i--) {
        int coefficient;
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coefficient);
        insert_node(&head2, coefficient, i);
    }

    printf("Polynomial-1: ");
    print_polynomial(head1);
    printf("Polynomial-2: ");
    print_polynomial(head2);

    result = add_polynomials(head1, head2);
    printf("Sum: ");
    print_polynomial(result);

    return 0;
}