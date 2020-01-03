// this gcd is base on Euler theorem
#include <stdio.h>
#include <stdlib.h>

int gcd();

void main() {
    int a,b, res;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b); 
    res = a > b ? gcd(a,b) : gcd(b,a);
    printf("GCD of %d and %d is %d", a,b, res);
}

int gcd(int a, int b) {
    // a > b in this function
    return b == 0 ? a : gcd(b, a%b);
}
