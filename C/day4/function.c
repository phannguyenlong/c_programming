#include <stdio.h>

void hello();
int add();

void main() {
    hello();
    printf("Sum of 5 and 6 is %d\n", add(5,6));
}

void hello() {
    printf("hello world\n");
}

int add (int num1, int num2)  {
    return num1 + num2;
}


