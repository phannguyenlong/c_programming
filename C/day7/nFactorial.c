#include <stdio.h>

int countFactorial();

void main() {
    int n;
    printf("Type the number: ");
    scanf("%d", &n);
    printf("Factorial is: %d", countFactorial(n));
}

int countFactorial(int n) {
    if (n < 1) return 1;
    else return n*countFactorial(n-1);
}


