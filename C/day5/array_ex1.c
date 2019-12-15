#include <stdio.h>

void main() {
    int sum=0, arr[10] = {1};
    for(int i=1; i <=10; i++) {
        arr[i] = i;
        sum += arr[i];
        printf("var %d: %d\n",i, sum);
    }
}