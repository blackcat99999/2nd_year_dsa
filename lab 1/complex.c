#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

void add_complex(Complex c1, Complex c2, Complex *result) {
    result->real = c1.real + c2.real;
    result->imag = c1.imag + c2.imag;
}

void multiply_complex(Complex *c1, Complex *c2, Complex *result) {
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}

void display_complex_sum(Complex c) {
    printf("Sum=%.0f+%0.0fi\n", c.real, c.imag);
}

void display_complex_product(Complex c) {
    printf("Product=%.0f+%0.0fi\n", c.real, c.imag);
}

int main() {
    Complex c1, c2, result;

    printf("Enter complex number 1: ");
    scanf("%f %f", &c1.real, &c1.imag);

    printf("Enter complex number 2: ");
    scanf("%f %f", &c2.real, &c2.imag);

    int choice;
    printf("MENU\n");
    printf("1. addition\n");
    printf("2. multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 0) {
        switch (choice) {
            case 1:
                add_complex(c1, c2, &result);
                display_complex_sum(result);
                break;
            case 2:
                multiply_complex(&c1, &c2, &result);
                display_complex_product(result);
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}