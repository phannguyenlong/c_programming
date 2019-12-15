 #include <stdio.h>

int sumOfPrime(), checkPrime();

void main() {
    int k;
    printf("Input number: ");
    scanf("%d", &k);
    // printf("%d", k);
    printf("Sum of prime is: %d",sumOfPrime(k));
}

int sumOfPrime(int k) {
    int sum=0;
    for(int i = 2; i<=k; i++ ) {
        int isPrime = checkPrime(i);
        if (isPrime) sum += i;
    }
    return sum;
}

int checkPrime(int num) {
    for (int i=2; i < num; i++) {
        if(num % i ==0) return 0;
    }
    printf("Prime is: %d\n", num);
    return 1;
}