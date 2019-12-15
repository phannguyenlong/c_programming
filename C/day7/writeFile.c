#include <stdio.h>

void main() {
    unsigned int account;
    char name[30];
    double balance;
    
    FILE *cfPtr; // cfPtr = clients.dat file pointer 

    // fopen opens file. Exit program if unable to create file
    if ((cfPtr = fopen( "clients.txt", "w")) ==  NULL) {
        puts("File could not open");
    } else
    {
        puts( "Enter the account, name, and balance." );
        puts( "Enter EOF to end input." );
        printf( "%s", "? " );
        scanf( "%d%29s%lf", &account, name, &balance );

        // write account, name and balance into file with fprintf
        while ( !feof(stdin)) 
        {
            fprintf( cfPtr, "%d %s %.2f\n", account, name, balance );
            printf( "%s", "? " );
            scanf( "%d%29s%lf", &account, name, &balance );
        }
        fclose( cfPtr ); // fclose closes file 
    }
}