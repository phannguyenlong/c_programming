#include <stdio.h>

int k;
int sum(),l10(), oddCheck();
void sort(), checkPrime();
void main()
{
    int option;
    printf("Input how many number: ");
    scanf("%d", &k);

    // input session
    int numbers[k];
    for (int i = 0; i < k; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        // sorting session
        for (int x = 0; x < (i + 1); x++)
        {
            int middleNum = numbers[i];
            if (numbers[i] < numbers[x])
            {
                numbers[i] = numbers[x];
                numbers[x] = middleNum;
            }
        }
    }

    // choice session
    printf("Type letter to run following function\n");
    printf("OPTION:\n");
    printf("e - to end the program\n");
    printf("a - to caculate sum and print out\n");
    printf("s - to sort in accending and print out\n");
    printf("c - to caculate how many number less than 10 and print out\n");
    printf("S - to sort in decending and print out\n");
    printf("o - to caculate how many odd number and print out\n");
    printf("p - to print out all prime number\n");

    while (option != 'e')
    {
        option = getchar();
        switch (option)
        {
        case 'a':
            printf("Sum of all is %d\n", sum(numbers));
            break;
        case 's':
            sort(numbers, "a");
            break;
        case 'c':
            printf("%d number less than 10", l10(numbers));
            break;
        case 'S':
            sort(numbers, "d");
            break;
        case 'o':
            printf("%d number is odd number", oddCheck(numbers));
            break;
        case 'p':
            checkPrime(numbers);
            break;
        case '\n':
            printf("\nYour option: ");
            break;
        case '\t': // ignore other case
        case ' ':
        case 'e':
            break;
        default:
            printf("Wrong input");
            break;
        }
    }
}

int sum(int numbers[])
{
    int sum = 0;
    int i;
    for ( i = 0; i < k; i++)
    {
        sum += numbers[i];
    }
    return sum;
}

int l10(int numbers[]) {
    int result=0;
    for(int i = 0; i <k; i++) {
        if(numbers[i] <=10) {
            result += 1;
        }
    }
    return result;
}

int oddCheck(int numbers[]) {
    int result=0;
    for(int i = 0; i <k; i++) {
        if(numbers[i]%2==1) {
            result += 1;
        }
    }
    return result;
}

void checkPrime(int numbers[]) {
    for(int i=0; i < k; i++) {
        int isPrime = 1;
        if (numbers[i]==1) {continue;}
        for(int z=2; z < numbers[i]/2; z++) {
            if(numbers[i]%z==0) {isPrime =0;}
        }
        if (isPrime) {printf("%d\t",numbers[i]);}
    }
}

void sort(int numbers[], char order[])
{
    if (order == "a")
    {
        for (int i = 0; i < k; i++)
        {
            printf("%d\t", numbers[i]);
        }
    }
    else if (order == "d")
    {
        for (int i = k-1; i >=0 ; i--)
        {
            printf("%d\t", numbers[i]);
        }
    }
}
