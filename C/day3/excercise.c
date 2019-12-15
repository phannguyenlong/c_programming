#include <stdio.h>

void main() {
    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, numOfInput=0, inputValue, sum;
    printf("Input 10 or less than 10 number \n");
    while (++numOfInput <= 10)
    {
        printf("Input number %d or type -1 to exit: ", numOfInput);
        scanf("%d", &inputValue);
        if (inputValue == EOF) {
            printf("Exit input\n");
            break;
        }
        sum += inputValue;
        if (numOfInput == 1) num1 = inputValue;
        else if (numOfInput == 2) {
             num2 = inputValue;
        }
        else if (numOfInput == 3) num3 = inputValue;
        else if (numOfInput == 4) num4 = inputValue;
        else if (numOfInput == 5) num5 = inputValue;
        else if (numOfInput == 6) num6 = inputValue;
        else if (numOfInput == 7) num7 = inputValue;
        else if (numOfInput == 8) num8 = inputValue;
        else if (numOfInput == 9) num9 = inputValue;
        else if (numOfInput == 10) num10 = inputValue;
    };

    printf("Type letter to run following function\n");
    printf("OPTION:\n");
    printf("crl z - to end the program\n");
    printf("a - to caculate sum and print out\n");
    printf("s - to sort in accending and print out\n");
    printf("c - to caculate how many number less than 10 and print out\n");
    printf("S - to sort in decending and print out\n");
    printf("o - to caculate how many odd number and print out\n");
    printf("p - to print out all prime number\n");
    int option;
    while ((option = getchar()) != EOF) // EOF is "end of document" (in window it is crl z)
    // getchar will take ONLY 1 character from the keyboard
    printf("Input a letter: ");
    {
        switch (option)
        {
        case 'A':
        case 'a':
            printf("Sum of all number is: %d\n", sum);
            break;
        case 's':
            printf("%d %d %d %d %d %d %d %d %d %d\n", num1, num2, num3, num4, num5, num6, num7, num8, num9, num10);
            break;
        case 'c': 
            printf("CCCCCCCCC");
            break;
        case '\n': //MUST include these lines becase C recievce Enter as a character too
        case '\t':
        case ' ':
            break;
        default: 
            printf("Wrong input\n");
        }
    }
    printf("=============END OF PROGRAM=============");
}