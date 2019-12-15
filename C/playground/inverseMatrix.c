#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void printArray(), findInverseMatrix();
int validateDigit();
float calculateDeterminal();

void main() {
    printf("Input dimension: ");
    int dimension, determinal;
    while ((dimension = validateDigit()) < 2) {
        puts("Must larger or equal 2");
        printf("Try again: ");
    }
    float arr[dimension][dimension];
    
    for (int i=0; i < dimension * dimension; i ++) {
        printf("Element [%d][%d] is: ", i/dimension, i%dimension);
        arr[i/dimension][i%dimension] = validateDigit();
    }
    puts("Array now is: ");
    printArray(dimension, arr);

    puts("Calcalating deternominal...");
    determinal = calculateDeterminal(dimension, arr);
    printf("Det of array is: %d\n", determinal);

    if (determinal == 0) {
        puts("Matrix not invertiable");
    } else {
        puts("Finding inverse matrix...");
        float inverseMatrix[dimension][dimension];
        findInverseMatrix(dimension, arr, inverseMatrix, determinal);
        puts("Iverse matrix is: ");
        printArray(dimension, inverseMatrix);
    }
}

void findInverseMatrix(int k, int arr[k][k], float res[k][k], int det) {
    // using A^-1 = 1/(det(A)) * adj(A)
    int sub_arr[k-1][k-1];
    for (int i = 0; i < k*k; i++) {
        // i / k is row, i % k is column
        // extracting adjoint matrix
        int row = 0; // reset row to 0
        for (int x = 0; x < k; x ++) {
            if (x == (i/k)) continue; // passing selected row
            int column = 0; // reset column to 0
            for (int y = 0; y < k; y++) {
                if (y == (i%k)) continue; // passing selected column
                sub_arr[row][column] = arr[x][y];
                column += 1;
            }
            row += 1;
        }
        // puts("Sub array is: ");
        // printArray(k-1, sub_arr);
        float r = (float) 1 / det;
        res[i/k][i%k] = pow(-1, (i/k + 1) + (i%k + 1)) * r * calculateDeterminal(k-1,sub_arr);
        // printf("Res is: %.2f\n", res[i/k][i%k]);
    }
}

float calculateDeterminal(int k, float arr[k][k]) {
    float minor, cofactor, sub_arr[k-1][k-1], det = 0;
    // it works by choosing the first row to calculate det
    if (k == 2) { // case 2x2 matrix
        return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    }
    for (int i = 0; i < k; i ++) { // i is column
        minor = arr[0][i] * pow(-1, i );
        // extracting sub array
        for (int x = 1; x < k; x++) { // row
            int column = 0 ;
            for (int y = 0; y < k; y++) { // column
                if (y == i) continue; // passing selected column
                sub_arr[x-1][column] = arr[x][y];
                column += 1;
            }
        }
        // puts("Sub array is: ");
        // printArray(k-1, sub_arr);
        // printf("Minor is: %d\n", minor);
        det += minor * calculateDeterminal(k-1, sub_arr);
        // printf("Det is: %d\n", det);
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

void printArray(int k, float arr[k][k]) {
    for (int i = 0; i < k*k; i ++) {
        if (i % k == 0 && i != 0) {
            printf("\n");
        }
        printf("%f\t", arr[i/k][i%k]);
    }
    printf("\n");
}