#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    unsigned seed;
    for(int i=1; i <=5; i++) {
        // using srand to avoid repeating values of rand 
        // comment this part and run twice to see the different
        printf("Input seed: ");
        scanf("%u",&seed);
        srand(seed);

        // OR we can use srand(time(NULL)) to replace for input seed step
        // It take the present time as the seed
        // srand(time(NULL));

        // simulat 20 time dice
        for(int time =1; time <= 10; time++) {
            // rand() function has formula like MIN + rand % MAX
            // it will prodce number MIN <= rand <= MAX
            printf("%10d", 1 + rand()%6); // it will run from 0 <= rand <= 6
            if(time%5 == 0){
                printf("\n");
            }
        }
    }
}

