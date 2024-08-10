#include <stdio.h>


void addPolynomials(int poly1[], int poly2[], int degree) {
    int result[degree + 1];
    int i;

    
    for (i = 0; i <= degree; i++) {
        result[i] = 0;
    }

    for (i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }

    printf("Resultant Polynomial: ");
    for (i = degree; i >= 0; i--) {
        if (result[i] != 0) {
            if (i == 0) {
                printf("%d", result[i]);
            } else if (i == 1) {
                printf("%dx+", result[i]);
            } else {
                printf("%dx^%d+", result[i], i);
            }
        }
    }
    printf("\n");
}

int main() {
    int degree, i;
    int poly1[10], poly2[10];

   
    printf("Enter maximum degree of x: ");
    scanf("%d", &degree);

    
    printf("Enter Polynomial-1 from lowest degree to highest degree: ");
    for (i = 0; i <= degree; i++) {
        scanf("%d", &poly1[i]);
    }

    
    printf("Enter Polynomial-2: ");
    for (i = 0; i <= degree; i++) {
        scanf("%d", &poly2[i]);
    }

    
    addPolynomials(poly1, poly2, degree);

    return 0;
}