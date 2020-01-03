#include <stdio.h>

typedef struct Multiple_return
{
    int a,b;
} tupe2s;


void modulo_inverse();
tupe2s gcd_extended();

void main() {
    int num, z;
    printf("Input modulo number: ");
    scanf("%d", &z);
    printf("Input number to inverse: ");
    scanf("%d", &num);
    while ( num > z ) {
        printf("Must be less than %d, Try again: ",z);
        scanf("%d", &num);
    }
    modulo_inverse(num, z);
}

void modulo_inverse(int num, int z) {
    int x=0,y=0;
    tupe2s res;
    res = gcd_extended(z, num, &x, &y);
    printf("gcd is: %d\n", res.a);
    printf("Modulo in verse of %d in Z%d is: %d", num, z,res.b);
}

tupe2s gcd_extended(int a, int b, int *x, int *y) {
    int x1=0,y1=0;
    tupe2s res; // gcd is a, inverse is b
    // base case
    if (b == 0) {
        *x = 0, *y = 1; 
        res.a = a;
        return res;
    }
    res.a = gcd_extended(b, a%b, &x1, &y1).a;
    *x = y1 - (a/b) * x1; 
    *y = x1;
    res.b = (*x + a) % a;
    return res;
}