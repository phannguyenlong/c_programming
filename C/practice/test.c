#include <stdio.h>
#include <string.h>

#define max 100

void CountSpace(char s[max])

{
    int i, count = 0, output_length, couter_out=0;
    char s_ouput[max], str;
    output_length = strlen(s);
    for (i = 0; i < strlen(s); i++)
    {
        // check white space
        if (str == ' ' && s[i] == ' ') {
            puts("RUN");
            s_ouput[couter_out] = '*';
            couter_out++;
        }
        str = s[i];
        s_ouput[couter_out] = str;
        if (s[i] == ' ')
        {
            count++;
        }
        couter_out++;
    }
    puts(s_ouput);
    printf("Chuoi co %d khoang trang\n", count);
}

int main()
{
    char s[max];
    printf("Nhap chuoi: ");
    gets(s);
    CountSpace(s);
}