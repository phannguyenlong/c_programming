#include <stdio.h>

void writeFile(), readFile();

void main() {
    int option;
    printf("Your option: ");
    while (option != 'e') {
        option = getchar();
        switch (option)
        {
        case 'w': 
            writeFile();
            printf("\nYour option: "); // to debbug (so ugly)
            break;
        case 'r':
            readFile();
            break;
        case 'e':
        case '\t':
        case ' ':
            // ignore these symbols
            break;
        case '\n':
            printf("\nYour option: ");
            break;
        default:
            printf("Wrong input\n");
            break;
        }
    }
}

void writeFile() {
    unsigned int studentID;
    char name[30];
    double point;
    FILE *cfPtr; // define pointer for file

    cfPtr = fopen("file.txt", "w"); // return a file pointer or NULL
    if (cfPtr == NULL)
    {
        puts("File could not open");
    } else
    {
        int counter = 1;
        puts("Enter student ID, name and point");
        puts("Enter EOF to end");
        printf("%d. ", counter);
        scanf("%d%29s%lf",&studentID, name, &point);
        // write data to file
        while ( !feof(stdin) ) // stdin will take the input from key board
        // feof is "end of file" will return non zero if it is not the end of file
        {
            counter++;
            fprintf(cfPtr, "%d %s %.2f\n", studentID, name, point);
            printf("%d. ", counter);
            scanf("%d%29s%lf",&studentID, name, &point);
        }
        fclose(cfPtr); // close file
    }
    puts("Write file done!");
} 

void readFile() {
    unsigned int studentID;
    char name[30];
    double point;
    FILE *cfPtr; // create file pointer
    cfPtr = fopen("file.txt", "r");
    if (cfPtr == NULL) {
        puts("Error when reading file");
    } else
    {
        printf("%s\t%s\t%s\n", "ID", "Name", "Point");
        while ( !feof(cfPtr) )  // foef(cfPtr) will return non zero if it reach end of file
        {
            fscanf(cfPtr, "%d%29s%lf", &studentID, name, &point);
            printf("%d\t%s\t%5.2f\n", studentID, name, point);
        }
    }
    puts("Read file done!");
}