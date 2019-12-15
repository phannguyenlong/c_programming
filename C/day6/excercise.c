#include <stdio.h>

int dimension, sum(), sumOfPrime(), checkPrime();
void printArray(), sortArray();

void main() {
    int option;
    printf("Input dimesion of array: ");
    scanf("%d", &dimension);

    // input session
    int arr[dimension][dimension];
    for (int i = 0; i < dimension; i++) {
        for (int x=0; x < dimension; x++) {
            printf("Element array[%d][%d] is: ",i,x);
            scanf("%d", &arr[i][x]);
        }
    }
    puts("Final array is: ");
    printArray(arr);

    //option session
    printf("\n'e'- to exit. \n");
    printf("'a' - to call funcion sum to calculate the sum of the all values in the matrix and then print out function main.\n");
    printf("'p'- to call funtion prime returning the sum of all prime integer and print out function main.\n");
    printf("'s'- to call funtion sort and output the matrix in ascending order in function main.\n");
    while (option != 'e')
    {
        option = getchar();
        switch (option)
        {
        case 'a': 
            printf("Sum is: %d", sum(arr));
            break;
        case 'p': 
            printf("Sum of prime number is: %d", sumOfPrime(arr));
            break;
        case 's': 
            sortArray(arr);
            printArray(arr);
            break;
        case '\n':
            printf("\nYour option: ");
            break;
        case '\t':
        case ' ':
        case 'e':
            break;
        default:
            printf("Wrong Input");
            break;
        }
    }
    
}

int sumOfPrime(int arr[dimension][dimension]) {
    int sum=0;
    for (int i=0; i < dimension; i++) {
        for (int x=0; x < dimension; x++){
            if(checkPrime(arr[i][x])) {
                sum += arr[i][x];
            }
        }
    }
    return sum;
}

int checkPrime(int number) {
    for(int i = 2; i < number; i ++) {
        if(number % i == 0 || number == 0) {
            return 0;
        }
    }
    return 1;
}

int sum(int arr[dimension][dimension]) {
    int sum=0;
    for(int i = 0; i < dimension; i++) {
        for(int x = 0; x < dimension; x++) {
            sum += arr[i][x];
        }
    }
    return sum;
}

void sortArray(int arr[dimension][dimension]) {
    int temp;
    printf("Sorting array...\n");
    for(int i=0; i< dimension; i++) {
        for(int x =0; x < dimension; x ++) {
            // arr[i][x]
            for(int j=0; j < dimension; j++) {
                for(int k=0; k < dimension; k++) {
                    if (arr[i][x] < arr[j][k]) {
                        temp = arr[i][x];
                        arr[i][x]= arr[j][k];
                        arr[j][k] = temp;
                    }
                }
            } 
        }
   } 
}


void printArray(int arr[dimension][dimension]) {
    for(int i = 0; i < dimension; i++) {
        for(int x = 0; x < dimension; x++) {
            printf("%5d\t", arr[i][x]);
        }
        printf("\n");
    }
}