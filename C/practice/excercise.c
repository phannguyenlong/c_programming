#include <stdio.h>

void printArray(), sumOfOdd(), sortArray(), readFile(), findSecBiggest();
int dimension, numberToMultiply = 1;
FILE *cfPtr;

void main() {
    printf("Input the dimension of matrix: ");
    scanf("%d", &dimension);
    int arr[dimension][dimension], option;

    //input session
    for (int i = 0; i<dimension; i++) {
        for (int x = 0; x <dimension; x++) {
            printf("Input the element [%d][%d]: ",i,x);
            scanf("%d", &arr[i][x]);
        }
    }
    puts("The current array now is:");
    printArray(arr);

    //choice session
    puts("List of option:");
    puts("e - exit");
    puts("a - call functiont to calculate sum of all odd number and save result to file a.txt");
    puts("p - to call a function BIG returning the second biggest number and save in p.txt");
    puts("r - read number from r.txt and multiply it to the matrix");
    // printf("Your option: ");
    while (option != 'e')
    {
        option = getchar();
        switch (option)
        {
        case 'a':
            sumOfOdd(arr);
            break;
        case 'p':
            // sortArray(arr);
            findSecBiggest(arr);
            break;
        case 'r':
            readFile();
            printArray(arr);
            numberToMultiply = 1;
            break;
        case '\t':
        case ' ':
        case 'e':
            break;
        case '\n':
            printf("Your option: ");
            break;
        default:
            puts("Wrong input");
            break;
        }
    }
    
}

void readFile() {
    cfPtr=fopen("r.txt", "r");
    if (cfPtr == NULL) {
        puts("Failed to open r.txt");
    } else
    {
        fscanf( cfPtr,"%d", &numberToMultiply);
        fclose(cfPtr);
    }
    
}

void findSecBiggest(int arr[dimension][dimension]) {
    int biggest=arr[0][0], SecBiggesst = arr[0][1];
    for (int i =0; i <dimension; i++) {
        for(int x = 0; x<dimension; x ++) {
            if(arr[i][x] > biggest) {
                // int temp = biggest;
                // SecBiggesst = biggest;
                biggest = arr[i][x];
            }
            if (arr[i][x] > SecBiggesst && arr[i][x] < biggest ) {
                SecBiggesst = arr[i][x];
            }
        }
    }
    cfPtr=fopen("p.txt","w");
    if (cfPtr == NULL) {
        puts("Failed to write");
    } else
    {
        fprintf(cfPtr, "The second largest is: %d", SecBiggesst);
        fclose(cfPtr);
        puts("Success save in p.txt");
    }
}

void sortArray(int arr[dimension][dimension]) {
    int temp;
    for(int i = 0; i < dimension; i ++) {
        for(int x = 0; x <dimension; x++) {
            // arr[i][x]
            for (int j=0; j <dimension; j++) {
                for(int k=0; k < dimension; k++) {
                    if (arr[i][x] < arr[j][k]){
                        temp = arr[i][x];
                        arr[i][x] = arr[j][k];
                        arr[j][k] = temp;
                    }
                }
            }
        }
    }
    // save the second largest to p.txt
    printf("%d", arr[dimension-1][dimension-2]);
    cfPtr=fopen("p.txt","w");
    if (cfPtr == NULL) {
        puts("Failed to write");
    } else
    {
        fprintf(cfPtr, "The second largest is: %d", arr[dimension-1][dimension-2]);
        fclose(cfPtr);
        puts("Success save in p.txt");
    }
    
}

void sumOfOdd(int arr[dimension][dimension]) {
    int sum=0;
    cfPtr = fopen("a.txt", "w");
    if (cfPtr == NULL) {
        puts("Failed to write file");
    }
    else {
        for (int i = 0; i <dimension; i++) {
            for (int x = 0; x < dimension; x ++) {
                if (arr[i][x] % 2 != 0) {
                    sum += arr[i][x];
                }
            }
        }
        fprintf(cfPtr, "Sum of all odd number in array is: %d", sum);
        fclose(cfPtr);
        puts("Success save to a.txt");
    }
    
}

void printArray(int arr[dimension][dimension]) {
    for (int i = 0; i <dimension; i++) {
        for (int x = 0; x <dimension; x ++) {
            printf("%d\t", arr[i][x] * numberToMultiply);
        }
        printf("\n");
    }
}