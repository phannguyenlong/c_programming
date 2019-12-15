#include <stdio.h>

int main(void)
{
    int myNumber = 200;
    int inputNumber;
    printf("Can you guess my number?\n");
    while (myNumber != inputNumber)
    {
        scanf("%d", &inputNumber);
        if (inputNumber < myNumber)
        {
            printf("Too Low\n");
        }
        else if (inputNumber > myNumber)
        {
            printf("Too hight\n");
        }
    }
    printf("Congratulation");
}