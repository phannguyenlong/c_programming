#include<stdio.h>
int m,n,k;
int sum();
int sumPrime();
int primeChecking();
void printArray(),sArray();


int main(void)
{
    printf("How many number you want to enter: ");
    scanf("%d",&k);
   
    int numbers[k][k];
    for(m=0;m<=k;m++)
    {
        for(n=0;n<=k;n++)
        {
            printf("The dimension of matrix [%d][%d] is: ",m,n);
            scanf("%d",&numbers[m][n]);
        }
    }
    puts("Final matrix is: ");
    printArray(numbers);
    //user choice
    printf("'e'- to exit. \n");
    printf("'a' - to call funcion sum to calculate the sum of the all values in the matrix and then print out function main.\n");
    printf("'p'- to call funtion prime returning the sum of all prime integer and print out function main.\n");
    printf("'s'- to call funtion sort and output the matrix in ascending order in function main.\n");
    int option;
    option=getchar();
    while(option!='e')
    {
        switch(option)
        {
            case 'a':
            printf("the sum is: %d",sum(numbers));
            break;
            case 'p':
            printf("the sum of prime integers is: %d",sumPrime(numbers));
            break;
            case 's':
            sArray(numbers);
            printArray(numbers);
            break;
        }
    }
}
int sum(int numbers[k][k])
{
    int sum=0;
    for(int m=0;m<k;m++)
    {
        for(int n=0;n<k;n++)
        sum=+numbers[m][n];
        return sum;
    }
}
void printArray(int numbers[k][k])
{
    for(int m = 0; m <k; m++) {
        for(int n = 0; n < k; n++)
        {
            printf("%5d\t", numbers[m][n]);
        }
        printf("\n");
    }
}
int sumPrime(int numbers[k][k])
{
    int sum=0;
    for (int i=0;i<k;i++)
    {
        for(int x=0;x<k;x++)
        {
            if(primeChecking(numbers[i][x]))
            {
                sum+=numbers[i][x];
            }
        }
    }
}
int primeChecking(int number)
{
    for(int i=2;i<number;i++)
    {
        if(number%1==0 || number ==0 )
        {
            return 0;
        } 
    }
    return 1;
}
void sArray(int numbers[k][k])
{
    int temp;
    printf("sorted array:\n ");
    for(int i=0; i<k;i++)
    {
        for(int x=0;x<k;x++)
        {
            for(int j=0; j<k;j++)
            {
                for(int z=0;z<k;z++)
                {
                    if (numbers[i][x]<numbers[j][z])
                    {
                        temp = numbers[i][x];
                        numbers[i][x]=numbers[j][z];
                        numbers[j][z]=temp;
                    }
                }
            }
        }
    }
}