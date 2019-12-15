#include <stdio.h>
#include <string.h>
#include <ctype.h>

void shift_cipher(char *, char);
void read_file(), write_file(char);
FILE *filePtr;
#define MAX 1000 // max size of data
char letters[27]="abcdefghijklmnopqrstuvwxyz ", fname[100];;

void main() {
    char data[MAX];
    int option; 
    puts("e - encrypt");
    puts("d - derypt");
    puts("x - to exit cipher");
    printf("Your option: ");
    while (option != 'x')
    {
        option = getchar();
        switch (option)
        {
        case 'e':
            read_file(data);
            shift_cipher(data, 'e');
            break;
        case 'd':
            read_file(data);
            shift_cipher(data, 'd');
            break;
        case '\n':
            printf("Your option: ");
            break;
        case ' ':
        case '\t':
        case 'x':
            break;
        default:
            puts("Wrong input");
            break;
        }
    }
}

void shift_cipher(char *data, char option) {
    long int key, location;
    char *locationPtr;
    printf("Enter your key: ");
    scanf("%d", &key);
    printf("Your text: ");
    write_file(option);
    // encryption
    for (int i = 0; i < strlen(data); i ++) {
        locationPtr = strchr(letters, data[i]); // return address of text in letters
        if (locationPtr == NULL) {
            printf("%c", data[i]);
            fprintf(filePtr, "%c", data[i]);
            continue;
        }
        location = locationPtr - letters; // find postion in array letters
        // encrypt || decrypt
        location = (location + (option == 'e'? key: -key) ) % 27; 
        location += location < 0 ? 27 : 0;
        // convert to text and save to file
        printf("%c", letters[location]);
        fprintf(filePtr, "%c", letters[location]);
    }
    fclose(filePtr);
    printf("\n");
    puts("End of cryptation");
}

void write_file(char option) {
    char name[100], *token, out_fname[100] = ""; // adding "" to prevent stupid error of C ?
    strcat(out_fname, option == 'e' ? "output/en_" : "output/de_");
    // extracting file name
    token = strtok (fname, "/");
    while (token)
    {
      strcpy(name, token);
      token = strtok (NULL, "/");
    }
    strcat(out_fname, name);
    filePtr = fopen(out_fname, "w");
    if (filePtr == NULL) puts("Error when loading file. Failed to write file");
}

void read_file(char *data) {
    int i = -1;
    printf("Enter location to your file: ");
    scanf("%s", fname);
    filePtr = fopen(fname, "r");
    if (filePtr == NULL) {
        puts("File name is not correct. Try again!");
        read_file(data);
    } else {
        fgets(data, MAX, filePtr);
    }
    while (data[++i])
    {
        data[i] = tolower(data[i]); // lower all character
    }
    
    fclose(filePtr);
}