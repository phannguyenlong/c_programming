#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(), solveLES();
int calculateDeterminal(), validateDigit(), cal_gcd();

void main() {
    puts("The equation will has form Ax = b");
    puts("You will enter A and b");
    printf("Input dimension: ");
    int dimension, detA;
    while ((dimension = validateDigit()) < 2) {
        puts("Must larger or equal 2");
        printf("Try again: ");
    }
    int arr[dimension][dimension], b[dimension];
    puts("Input your array A: ");
    for (int i=0; i < dimension * dimension; i ++) {
        printf("Element [%d][%d] is: ", i/dimension, i%dimension);
        arr[i/dimension][i%dimension] = validateDigit();
    }
    puts("Inputs b: ");
    for (int j = 0; j <dimension; j++) {
        printf("Element %d is: ", j);
        b[j] = validateDigit();
    }
    puts("A now is: ");
    printArray(dimension, arr);
    puts("Calcalating determinal of A");
    detA = calculateDeterminal(dimension, arr);
    printf("Det of A is: %d \n", detA);
    // solving LES session
    detA == 0 ? puts("LES has no solution") : solveLES(dimension, arr, b, detA);
}

void solveLES(int k, int arr[k][k], int b[k], int detA) {
    int sub_arr[k][k], det_sub_arr, gcd, sign_detA;
    puts("Solving LES ...");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k*k; j++) {
            if ( i == j%k ) {
                // interchange i collum with b
                sub_arr[j/k][j%k] = b[j/k];
            } else {
                sub_arr[j/k][j%k] = arr[j/k][j%k];
            }
        }
        // calculae det(sub_arr)/ det(A)
        // simplification the fraction
        det_sub_arr = calculateDeterminal(k, sub_arr);
        if (det_sub_arr % detA == 0) {
            printf("The solution %d is: %d\n", i + 1, det_sub_arr / detA);
        } else {
            sign_detA = detA;
            gcd = cal_gcd(det_sub_arr, detA);
            if ( det_sub_arr < 0 && detA < 0 ) {
                det_sub_arr = -det_sub_arr;
                sign_detA = -detA;
            }
            // and print out solution
            printf("The solution %d is: %d/%d\n", i + 1, det_sub_arr / gcd, sign_detA / gcd);
        }
    }
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
        // printArray(k-1, sub_arr);
        det += minor * calculateDeterminal(k-1, sub_arr);
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

int cal_gcd(int n1, int n2) {
    int gcd = 0, min;
    min = abs(n1) < abs(n2) ? abs(n1) : abs(n2);
    // min = n1< n2 ? n1: n2;
    for(int i=1; i <= min; ++i)
    {
        // Checks if i is factor of both integers
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }
    return abs(gcd);
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