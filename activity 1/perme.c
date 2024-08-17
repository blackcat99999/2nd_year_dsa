//circular reversal 
//no of times we know the permutation will happen

#include <stdio.h>

void generate_permutations842(int arr[], int size, int fact) {
    
    int i=0,counter=0;
    
     while(1){

        if(counter == fact)
        break;

        for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        }

        printf("\n");

        int temp = 0;
        temp = arr[i];
        arr[i] = arr[(i+1)%size];
        arr[(i+1)%size] = temp;

        i=(i+1)%size;
        counter++;
     };
}

int main() {
    int size,fact=1;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= size; i++){
        fact *= i;
    }

    generate_permutations842(arr, size, fact);
    return 0;
}