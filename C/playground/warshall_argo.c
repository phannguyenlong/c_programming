#include <stdio.h>
void printArray(), marshall_argo();

void main() {
    int dimension = 4;
    int arr[4][4] = 
    {  
        {0,1,0,1},
        {1,0,0,0},
        {0,0,1,0},
        {1,0,0,0}
    };
    // printf("Input dimension for matrix: ");
    // scanf("%d", &dimension);
    // int arr[dimension][dimension];
    // for (int i = 0; i<dimension*dimension; i++) {
    //     printf("Input element [%d][%d]: ", i/dimension, i %dimension);
    //     scanf("%d", &arr[i/dimension][i%dimension]);
    // }
    puts("Your input matrix: ");
    printArray(arr, dimension);
    puts("Calculating ...");
    marshall_argo(dimension, arr, 0);
}

void marshall_argo(int k, int arr[k][k], int round) {
    int sub_arr[k][k], i = round;
    if (round == k) {
        puts("RESULT");
        printArray(arr, k);
    } else {
        printf("ROUND %d\n", round);
        printArray(arr, k);
        // i is number of round
        // j take column and row base on row
        for (int j = 0; j < k; j++) {
            // arr[i][j] and arr[j][i]
            sub_arr[j][i] = arr[j][i];
            sub_arr[i][j] = arr[i][j];
            if (j == i) continue;
            // x run throung row to fill blank
            for (int x = 0; x < k; x ++) {
                if (x == i) continue;
                if (arr[j][x] == 1) {
                    sub_arr[j][x] = 1;
                } else {
                    sub_arr[j][x] = (arr[j][i] == 1 && arr[i][x]) == 1 ? 1 : 0;
                }
                // USE FOR DEBUG
                // printf("i:%d, j:%d, x: %d,",i,j,x);
                // printf("arr[%d][%d]: %d and arr[%d][%d]:%d = sub[%d][%d]: %d\n",i,x,arr[i][x],x,i,arr[x][i], j,x,sub_arr[j][x]);
            } 
        }
        marshall_argo(k, sub_arr, i + 1);
    }
}

void printArray(int *arr, int dimension) {
    for (int i=0; i < dimension * dimension; i ++) {
        if (i%dimension == 0 && i != 0) printf("\n");
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}