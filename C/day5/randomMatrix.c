#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int sum=0;
    printf("id\tnumber\tsum\n");
    for(int i=1; i <=10; i++ ) {
        int number;
        srand(i); // provide seed for random number
        number = 1 + rand() %10; // from 1 to 10
        sum += number;
        printf("%2d\t%3d\t%2d\n",i,number,sum);
    }
    printf("=========Program end===========");
}
