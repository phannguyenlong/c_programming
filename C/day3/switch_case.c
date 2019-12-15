#include <stdio.h>
#include <math.h>

void main()
{
    int grade;
    printf("Ipput a letter\n");
    while ((grade = getchar()) != EOF) // EOF is "end of document" (in window it is crl z)
    // getchar will take ONLY 1 character from the keyboard
    {
        switch (grade)
        {
        case 'A':
        case 'a':
            printf("aaaaaaa\n");
            break;
        case 'B':
        case 'b':
            printf("BBBBBBB\n");
            break;
        case '\n': //MUST include these lines becase C recievce Enter as a character too
        case '\t':
        case ' ':
            break;
        default: 
            printf("Wrong input\n");
        }
    }
    printf("Program finnish");
}