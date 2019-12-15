#include <stdio.h>

int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0, num10 = 0, numOfInteger;
int sum();
void sort(), sortS(), l10(), oddCheck(), checkPrime();
void main()
{
    int inputValue, option, middleNum, k;
    do
    {
        printf("How many number (Must be less than 10): ");
        scanf("%d", &numOfInteger);
        if (numOfInteger > 10)
            printf("Must be less than 10\n");
    } while (numOfInteger > 10);
    for (int i = 1; i <= numOfInteger; i++)
    {
        printf("Input number %d: ", i);
        scanf("%d", &inputValue);
        if (i == 1)
            num1 = inputValue;
        if (i == 2)
            num2 = inputValue;
        if (i == 3)
            num3 = inputValue;
        if (i == 4)
            num4 = inputValue;
        if (i == 5)
            num5 = inputValue;
        if (i == 6)
            num6 = inputValue;
        if (i == 7)
            num7 = inputValue;
        if (i == 8)
            num8 = inputValue;
        if (i == 9)
            num9 = inputValue;
        if (i == 10)
            num10 = inputValue;
    }
    // sorting session
    if (num10 < num9)
    {
        middleNum = num10;
        num10 = num9;
        num9 = middleNum;
    }
    if (num9 < num8)
    {
        middleNum = num9;
        num9 = num8;
        num8 = middleNum;
    }
    if (num8 < num7)
    {
        middleNum = num8;
        num8 = num7;
        num7 = middleNum;
    }
    if (num7 < num6)
    {
        middleNum = num7;
        num7 = num6;
        num6 = middleNum;
    }
    if (num6 < num5)
    {
        middleNum = num6;
        num6 = num5;
        num5 = middleNum;
    }
    if (num5 < num4)
    {
        middleNum = num5;
        num5 = num4;
        num4 = middleNum;
    }
    if (num4 < num3)
    {
        middleNum = num4;
        num4 = num3;
        num3 = middleNum;
    }
    if (num3 < num2)
    {
        middleNum = num3;
        num3 = num2;
        num2 = middleNum;
    }
    if (num2 < num1)
    {
        middleNum = num2;
        num2 = num1;
        num1 = middleNum;
    }
    if (num10 < num9)
    {
        middleNum = num10;
        num10 = num9;
        num9 = middleNum;
    }
    if (num9 < num8)
    {
        middleNum = num9;
        num9 = num8;
        num8 = middleNum;
    }
    if (num8 < num7)
    {
        middleNum = num8;
        num8 = num7;
        num7 = middleNum;
    }
    if (num7 < num6)
    {
        middleNum = num7;
        num7 = num6;
        num6 = middleNum;
    }
    if (num6 < num5)
    {
        middleNum = num6;
        num6 = num5;
        num5 = middleNum;
    }
    if (num5 < num4)
    {
        middleNum = num5;
        num5 = num4;
        num4 = middleNum;
    }
    if (num4 < num3)
    {
        middleNum = num4;
        num4 = num3;
        num3 = middleNum;
    }
    if (num3 < num2)
    {
        middleNum = num3;
        num3 = num2;
        num2 = middleNum;
    }
    if (num10 < num9)
    {
        middleNum = num10;
        num10 = num9;
        num9 = middleNum;
    }
    if (num9 < num8)
    {
        middleNum = num9;
        num9 = num8;
        num8 = middleNum;
    }
    if (num8 < num7)
    {
        middleNum = num8;
        num8 = num7;
        num7 = middleNum;
    }
    if (num7 < num6)
    {
        middleNum = num7;
        num7 = num6;
        num6 = middleNum;
    }
    if (num6 < num5)
    {
        middleNum = num6;
        num6 = num5;
        num5 = middleNum;
    }
    if (num5 < num4)
    {
        middleNum = num5;
        num5 = num4;
        num4 = middleNum;
    }
    if (num4 < num3)
    {
        middleNum = num4;
        num4 = num3;
        num3 = middleNum;
    }
    if (num10 < num9)
    {
        middleNum = num10;
        num10 = num9;
        num9 = middleNum;
    }
    if (num9 < num8)
    {
        middleNum = num9;
        num9 = num8;
        num8 = middleNum;
    }
    if (num8 < num7)
    {
        middleNum = num8;
        num8 = num7;
        num7 = middleNum;
    }
    if (num7 < num6)
    {
        middleNum = num7;
        num7 = num6;
        num6 = middleNum;
    }
    if (num6 < num5)
    {
        middleNum = num6;
        num6 = num5;
        num5 = middleNum;
    }
    if (num5 < num4)
    {
        middleNum = num5;
        num5 = num4;
        num4 = middleNum;
    }
    if (num10 < num9)
    {
        middleNum = num10;
        num10 = num9;
        num9 = middleNum;
    }
    if (num9 < num8)
    {
        middleNum = num9;
        num9 = num8;
        num8 = middleNum;
    }
    if (num8 < num7)
    {
        middleNum = num8;
        num8 = num7;
        num7 = middleNum;
    }
    if (num7 < num6)
    {
        middleNum = num7;
        num7 = num6;
        num6 = middleNum;
    }
    if (num6 < num5)
    {
        middleNum = num6;
        num6 = num5;
        num5 = middleNum;
    }
    if (num10 < num9)
    {
        middleNum = num10;
        num10 = num9;
        num9 = middleNum;
    }
    if (num9 < num8)
    {
        middleNum = num9;
        num9 = num8;
        num8 = middleNum;
    }
    if (num8 < num7)
    {
        middleNum = num8;
        num8 = num7;
        num7 = middleNum;
    }
    if (num7 < num6)
    {
        middleNum = num7;
        num7 = num6;
        num6 = middleNum;
    }
    if (num10 < num9)
    {
        middleNum = num10;
        num10 = num9;
        num9 = middleNum;
    }
    if (num9 < num8)
    {
        middleNum = num9;
        num9 = num8;
        num8 = middleNum;
    }
    if (num8 < num7)
    {
        middleNum = num8;
        num8 = num7;
        num7 = middleNum;
    }
    if (num10 < num9)
    {
        middleNum = num10;
        num10 = num9;
        num9 = middleNum;
    }
    if (num9 < num8)
    {
        middleNum = num9;
        num9 = num8;
        num8 = middleNum;
    }
    if (num10 < num9)
    {
        middleNum = num10;
        num10 = num9;
        num9 = middleNum;
    }

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
            printf("Sum is: %d\n", sum());
            break;
        case 's':
            sort();
            break;
        case 'S':
            sortS();
            break;
        case 'c':
            l10();
            break;
        case 'p':
            checkPrime();
            break;
        case 'o':
            oddCheck();
            break;
        case '\n':
            printf("\nYour option: ");
            break;
        case '\t':
        case ' ':
        case 'e':
            break;
        default:
            printf("Wrong input\n");
            break;
        }
    }
    printf("===============Program end===================");
}

int sum()
{
    return num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10;
}

void checkPrime(){
    for (int i = 2; i < num1; i++){
        if (num1%i == 0) break;
        if (i = num1 - 1) printf("%d ", num1);
    }
    for (int i = 2; i < num2; i++){
        if (num2%i == 0) break;
        if (i = num2 - 1) printf("%d ", num2);
    }
    for (int i = 2; i < num3; i++){
        if (num3%i == 0) break;
        if (i = num3 - 1) printf("%d ", num3);
    }
    for (int i = 2; i < num4; i++){
        if (num1%i == 0) break;
        if (i = num4 - 1) printf("%d ", num4);
    }
    for (int i = 2; i < num5; i++){
        if (num5%i == 0) break;
        if (i = num5 - 1) printf("%d ", num5);
    }
    for (int i = 2; i < num6; i++){
        if (num6%i == 0) break;
        if (i = num6 - 1) printf("%d ", num6);
    }
    for (int i = 2; i < num7; i++){
        if (num7%i == 0) break;
        if (i = num7 - 1) printf("%d ", num7);
    }for (int i = 2; i < num8; i++){
        if (num8%i == 0) break;
        if (i = num8 - 1) printf("%d ", num8);
    }for (int i = 2; i < num9; i++){
        if (num9%i == 0) break;
        if (i = num9 - 1) printf("%d ", num9);
    }
    for (int i = 2; i < num10; i++){
        if (num10%i == 0) break;
        if (i = num10 - 1) printf("%d ", num10);
    }
}

void oddCheck()
{
    int numOfOdd = 0;
    if (num1 % 2 == 1)
    {
        printf("%d ", num1);
        numOfOdd++;
    }
    if (num2 % 2 == 1)
    {
        printf("%d ", num2);
        numOfOdd++;
    }
    if (num3 % 2 == 1)
    {
        printf("%d ", num3);
        numOfOdd++;
    }
    if (num4 % 2 == 1)
    {
        printf("%d ", num4);
        numOfOdd++;
    }
    if (num5 % 2 == 1)
    {
        printf("%d ", num5);
        numOfOdd++;
    }
    if (num6 % 2 == 1)
    {
        printf("%d ", num6);
        numOfOdd++;
    }
    if (num7 % 2 == 1)
    {
        printf("%d ", num7);
        numOfOdd++;
    }
    if (num8 % 2 == 1)
    {
        printf("%d ", num8);
        numOfOdd++;
    }
    if (num9 % 2 == 1)
    {
        printf("%d ", num9);
        numOfOdd++;
    }
    if (num10 % 2 == 1)
    {
        printf("%d ", num10);
        numOfOdd++;
    }
    
    printf("\nNumber of odd is: %d\n", numOfOdd);
}

void l10()
{
    if (num10 <= 10)
        printf("10 number less than 10\n");
    else if (num9 <= 10)
        printf("9 number less than 10\n");
    else if (num8 <= 10)
        printf("8 number less than 10\n");
    else if (num7 <= 10)
        printf("7 number less than 10\n");
    else if (num6 <= 10)
        printf("6 number less than 10\n");
    else if (num5 <= 10)
        printf("5 number less than 10\n");
    else if (num4 <= 10)
        printf("4 number less than 10\n");
    else if (num3 <= 10)
        printf("3 number less than 10\n");
    else if (num2 <= 10)
        printf("2 number less than 10\n");
    else if (num1 <= 10)
        printf("1 number less than 10\n");
    else
        printf("No number less than 10");
}

void sort()
{
    int middleNum;
    switch (numOfInteger)
    {
    case 1:
        printf("%d\n", num10);
        break;
    case 2:
        printf("%d %d\n", num9, num10);
        break;
    case 3:
        printf("%d %d %d\n", num8, num9, num10);
        break;
    case 4:
        printf("%d %d %d %d\n", num7, num8, num9, num10);
        break;
    case 5:
        printf("%d %d %d %d %d\n", num6, num7, num8, num9, num10);
        break;
    case 6:
        printf("%d %d %d %d %d %d\n", num5, num6, num7, num8, num9, num10);
        break;
    case 7:
        printf("%d %d %d %d %d %d %d\n", num4, num5, num6, num7, num8, num9, num10);
        break;
    case 8:
        printf("%d %d %d %d %d %d %d %d\n", num3, num4, num5, num6, num7, num8, num9, num10);
        break;
    case 9:
        printf("%d %d %d %d %d %d %d %d %d\n", num2, num3, num4, num5, num6, num7, num8, num9, num10);
        break;
    case 10:
        printf("%d %d %d %d %d %d %d %d %d %d\n", num1, num2, num3, num4, num5, num6, num7, num8, num9, num10);
        break;
    default:
        break;
    }
}

void sortS()
{
    int middleNum;
    switch (numOfInteger)
    {
    case 1:
        printf("%d\n", num10);
        break;
    case 2:
        printf("%d %d\n", num10, num9);
        break;
    case 3:
        printf("%d %d %d\n", num10, num9, num8);
        break;
    case 4:
        printf("%d %d %d %d\n", num10, num9, num8, num7);
        break;
    case 5:
        printf("%d %d %d %d %d\n", num10, num9, num8, num7, num6);
        break;
    case 6:
        printf("%d %d %d %d %d %d\n", num10, num9, num8, num7, num6, num5);
        break;
    case 7:
        printf("%d %d %d %d %d %d %d\n", num10, num9, num8, num7, num6, num5, num4);
        break;
    case 8:
        printf("%d %d %d %d %d %d %d %d\n", num10, num9, num8, num7, num6, num5, num4, num3);
        break;
    case 9:
        printf("%d %d %d %d %d %d %d %d %d\n", num10, num9, num8, num7, num6, num5, num4, num3, num2);
        break;
    case 10:
        printf("%d %d %d %d %d %d %d %d %d %d\n", num10, num9, num8, num7, num6, num5, num4, num3, num2, num1);
        break;
    default:
        break;
    }
}