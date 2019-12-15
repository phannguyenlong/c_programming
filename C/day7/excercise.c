#include <stdio.h>

int dimension;
FILE *cfPtr;
void printArray(), sum(), sumOfPrime(), sortArray();
int checkPrime(), readFile();

void main() {
    int option, n;
    printf("Input dimension of matrix: ");
    scanf("%d", &dimension);

    // input session
    int arr[dimension][dimension];
    for (int i=0; i < dimension; i++) {
        for(int x=0; x < dimension; x++) {
            printf("Element [%d,%d] of array is: ", i, x);
            scanf("%d", &arr[i][x]);
        }
    }
    puts("The final array is: ");
    printArray(arr, 1);

    //option session
    puts("Type 'e' to exit");
    puts("Type 'a' to caculate the sum and store in a.txt");
    puts("Type 'p' to calculate the sum of all prime and store in p.txt");
    puts("Type 's' to sort the array and store matrix in s.txt");
    puts("Type 'r' to read file r.txt and multilize it to array print in main");
    // printf("Your option: ");
    while (option != 'e')
    {
        option = getchar();
        switch (option)
        {
        case 'a':
            sum(arr);
            break;
        case 'p':
            sumOfPrime(arr);
            break;
        case 's':
            sortArray(arr);
            break;
        case 'r':
            n = readFile();
            printArray(arr, n);
            break;
        case '\t':
        case ' ':
        case 'e':
            // ignore all these cases
            break;
        case '\n':
            printf("Your option: ");
            break;
        default:
            break;
        }
    }
    
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
   // save to file s.txt
    cfPtr = fopen("s.txt", "w");
    if (cfPtr == NULL) {
        puts("Failed to open file");
    } else {
        fprintf(cfPtr,"Sorted array is: \n");
        for(int y=0; y <dimension; y++) {
            for(int z=0; z< dimension; z++) {
            fprintf(cfPtr,"%d\t", arr[y][z]);
            }
            fprintf(cfPtr,"\n");
        }
        puts("Success save to s.txt");
        fclose(cfPtr);
    }
}

void sumOfPrime(int arr[dimension][dimension]) {
    int sum=0;
    for (int i=0; i < dimension; i++) {
        for (int x=0; x < dimension; x++){
            if(checkPrime(arr[i][x])) {
                sum += arr[i][x];
            }
        }
    }
    cfPtr = fopen("p.txt", "w");
    if (cfPtr == NULL) {
        puts("Failed to open file");
    } else
    {
        fprintf(cfPtr, "Sum of all prime values is: %d", sum);
        puts("Success save to p.txt");
        fclose(cfPtr);
    }
}

int checkPrime(int number) {
    if (number == 0 || number ==1) return 0;
    for(int i = 2; i < number; i ++) {
        if(number % i == 0 ) {
            return 0;
        }
    }
    return 1;
}

void sum(int arr[dimension][dimension]) {
    int sum=0;
    for (int i=0; i< dimension; i++) {
        for (int x=0; x< dimension; x++) {
            sum += arr[i][x];
        }
    }
    cfPtr = fopen("a.txt", "w");
    if (cfPtr == NULL) {
        puts("Failed to open file");
    } else
    {
        fprintf(cfPtr, "Sum of all values is: %d", sum);
        puts("Success save to a.txt");
        fclose(cfPtr);
    }
}

int readFile() {
    int num;
    cfPtr = fopen("r.txt", "r");
    if (cfPtr == NULL) {
        puts("Failed to read file");
    } else
    {
        fscanf(cfPtr,"%d", &num);
        fclose(cfPtr);
        return num;
    }
    
}

void printArray(int arr[dimension][dimension], int n) {
    for(int i=0; i <dimension; i++) {
        for(int x=0; x< dimension; x++) {
            printf("%d\t", n * arr[i][x]);
        }
        printf("\n");
    }
}