#include <stdio.h>

void printArray(), sum(), sumOfPrime(), sortArray(), readFile();
int dimension, numToMultiPly = 1, isPrime(), validateDigit();
FILE *cfPtr;

void main() {
    printf("Input dimension: ");
    dimension = validateDigit();
    int arr[dimension][dimension], option;
    
    // input session
    for(int i =0; i < dimension * dimension; i ++) {
        printf("Input element [%d][%d]: ", i/dimension, i%dimension);
        // scanf("%d",&arr[i/dimension][i%dimension]);
        arr[i/dimension][i%dimension] = validateDigit();
    }
    puts("The final array is: ");
    printArray(arr);
    
    // option session
    puts("Type 'e' to exit");
    puts("Type 'a' to caculate the sum and store in a.txt");
    puts("Type 'p' to calculate the sum of all prime and store in p.txt");
    puts("Type 's' to sort the array and store matrix in s.txt");
    puts("Type 'r' to read file r.txt and multilize it to array print in main");
    while(option != 'e') {
        option = getchar();
        switch (option) {
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
                readFile(arr);
                numToMultiPly = 1;
                break;
            case 'e':
            case '\t': 
            case ' ':
                break;
            case '\n':
                printf("Your input: ");
                break;
            default: 
                puts("Wrong input");
                break;
        }
    }
}

int validateDigit() {
    int status, input;
    status = scanf("%d", &input); 
    while (status != 1) {
        while((input = getchar()) != '\0' && input != '\n'); // take trash to avoid infinite loops
        puts("Must be a number!!!");
        printf("Try again: ");
        status = scanf("%d", &input);
    }
    return input;
}

void readFile(int arr[dimension][dimension]){
    cfPtr = fopen("input/r.txt", "r");
    if (cfPtr == NULL) {
        puts("Failed to read file r.txt");
    } else {
        while (!feof(cfPtr)) {
            fscanf(cfPtr, "%d", &numToMultiPly);
            puts("Array now is: ");
            printArray(arr);
        }
        fclose(cfPtr);
    }
}

void sortArray(int arr[dimension][dimension]) {
    for (int i = 0; i < dimension * dimension; i++) {
        for (int j = 0; j < dimension * dimension; j ++) {
            if (arr[i/dimension][i%dimension] < arr[j/dimension][j%dimension]) {
                int temp = arr[i/dimension][i%dimension];
                arr[i/dimension][i%dimension] = arr[j/dimension][j%dimension];
                arr[j/dimension][j%dimension] = temp;
            }
        }
    }
    
    // save to s.txt
    cfPtr = fopen("output/s.txt", "w");
    if (cfPtr == NULL) {
        puts("Failed to save in file s.txt");
    } else {
        for (int a = 0; a < dimension * dimension; a++) {
            if (a%dimension == 0 && a != 0) fprintf(cfPtr,"\n");
            fprintf(cfPtr,"%d\t", arr[a/dimension][a%dimension]);
        }
        fclose(cfPtr);
        puts("Success save file in s.txt");
    }
    
}

void sumOfPrime(int arr[dimension][dimension]) {
    int sum = 0;
    for (int i = 0; i < dimension * dimension; i++) {
        if (isPrime(arr[i/dimension][i%dimension])) {
            sum += arr[i/dimension][i%dimension];
        }
    }
    cfPtr = fopen("output/p.txt", "w");
    if (cfPtr == NULL) {
        puts("Failed to write file p.txt");
    } else {
        fprintf(cfPtr,"Sum of all prime is: %d", sum);
        fclose(cfPtr);
        puts("Success write file p.txt");
    }
}

int isPrime(int number) {
    if (number == 1 || number == 0) return 0;
    for (int i = 2; i < number; i ++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

void sum(int arr[dimension][dimension]) {
    int sum = 0;
    for (int i = 0; i < dimension * dimension; i ++) {
        sum += arr[i/dimension][i%dimension];
    }
    cfPtr = fopen("output/a.txt", "w");
    if (cfPtr == NULL) {
        puts("Failed to write file a.txt");
    } else {
        fprintf(cfPtr,"Sum of all element is: %d", sum);
        fclose(cfPtr);
        puts("Success save sum in a.txt");
    }
}

void printArray(int arr[dimension][dimension]) {
    for (int i = 0; i < dimension * dimension; i ++) {
        if ( i % dimension == 0 && i != 0) {
            printf("\n");
        }
        printf("%d\t", arr[i/dimension][i%dimension] * numToMultiPly);
    }
    printf("\n");
}
