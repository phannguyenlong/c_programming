#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int num, isPrime = 1;
    srand(time(NULL));
    num = 0 + rand() % 1000; // rand num in 0 to 1000;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    if (isPrime)
    {
        printf("%d is a prime number", num);
    }
    else
    {
        printf("%d is not a prime number", num);
    }
}