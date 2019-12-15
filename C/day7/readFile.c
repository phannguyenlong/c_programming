#include <stdio.h>

void main() {
    unsigned int account;
    char name[30];
    double balance;
    
    FILE *cfPtr;

    if ((cfPtr = fopen("clients.txt","r")) == NULL) {
        puts("File could not open");
    } else // read file (account, name, balance)
    {
        printf("%s\t%s\t%s\n", "Account", "Name", "Balance");
        fscanf(cfPtr,"%d%29s%lf", &account, name, &balance);
        while ( !feof(cfPtr))
        {
            printf("%d\t%s\t%5.2lf\n", account, name, balance);
            fscanf(cfPtr,"%d%29s%lf", &account, name, &balance);
        }
        fclose(cfPtr);
    }
    
}