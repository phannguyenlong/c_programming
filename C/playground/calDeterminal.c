#include <stdio.h>
#include <math.h>

void printArray();
int calculateDeterminal(), validateDigit();

void main() {
    printf("Input dimension: ");
    int dimension;
    while ((dimension = validateDigit()) < 2) {
        puts("Must larger or equal 2");
        printf("Try again: ");
    }
    int arr[dimension][dimension];
    for (int i=0; i < dimension * dimension; i ++) {
        printf("Element [%d][%d] is: ", i/dimension, i%dimension);
        arr[i/dimension][i%dimension] = validateDigit();
    }
    puts("Array now is: ");
    printArray(dimension, arr);
    puts("Calcalating deternominal");
    printf("Det of array is: %d", calculateDeterminal(dimension, arr));
}

int calculateDeterminal(int k, int arr[k][k]) {
    int minor, cofactor, sub_arr[k-1][k-1], det = 0;
    if (k == 2) { // case 2x2 matrix
        return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    }
    for (int i = 0; i < k; i ++) { // i is column
        minor = arr[0][i] * pow(-1, i );
        // extracting sub array
        for (int x = 1; x < k; x++) { // row
            int column = 0 ;
            for (int y = 0; y < k; y++) { // column
                if (y == i) continue;
                sub_arr[x-1][column] = arr[x][y];
                column += 1;
            }
        }
        puts("Sub array is: ");
        printArray(k-1, sub_arr);
        printf("Minor is: %d\n", minor);
        det += minor * calculateDeterminal(k-1, sub_arr);
        printf("Det is: %d\n", det);
    }
    return det;
}

int validateDigit() {
    int input, status;
    status = scanf("%d", &input);
    while (status != 1)
    {
        while ((input = getchar()) != '\0' && input != '\n');
        puts("Must be a number!!!");
        printf("Try again: ");
        status = scanf("%d", &input);
    }
    return input;
}

void printArray(int k, int arr[k][k]) {
    for (int i = 0; i < k*k; i ++) {
        if (i % k == 0 && i != 0) {
            printf("\n");
        }
        printf("%d\t", arr[i/k][i%k]);
    }
    printf("\n");
}