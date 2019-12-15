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
    int key, text_lenght, location;
    char *locationPtr;
    printf("Enter your key: ");
    scanf("%d", &key);
    // generate table of data
    // convert to number
    text_lenght = strlen(data);
    int arr[text_lenght];
    char encrypt_text[text_lenght];
    for (int i = 0; i < text_lenght; i ++) {
        locationPtr = strchr(letters, data[i]); // return address of text in letters
        location = locationPtr - letters; // find postion in array letters
        arr[i] = location;
    }
    if (option == 'e') {
        // encrytion
        for (int y = 0; y < text_lenght; y ++) {
            arr[y] = (arr[y] + key)%27;
        }
    } else if (option == 'd') {
        // decrytion
        for (int y = 0; y < text_lenght; y ++) {
            arr[y] = (arr[y] - key)%27;
            arr[y] += arr[y] < 0 ? 27 : 0;
        }
    }
    // convert to text and save to file
    write_file(option);
    printf("Your text: ");
    for (int i = 0; i < text_lenght; i ++) {
        encrypt_text[i] = letters[arr[i]];
        printf("%c", encrypt_text[i]);
        fprintf(filePtr, "%c", encrypt_text[i]);
    }
    fclose(filePtr);
    printf("\n");
    puts("End of cyptation");
}

void write_file(char option) {
    char name[100], *token, out_fname[100];
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
    if (filePtr == NULL) puts("Error when loading file");
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
        fgets(data, 100, filePtr);
    }
    while (data[++i])
    {
        data[i] = tolower(data[i]); // lower all character
    }
    
    fclose(filePtr);
}