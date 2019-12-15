#include <stdio.h>
#include <string.h>

char letters[26]="abcdefghijklmnopqrstuvwxyz";
void vingenere_cipher_encrypt(), vingenere_cipher_decrypt();
void hill_cipher_encrypt(), hill_cipher_decrypt();
void handleSecOption(char), printArray();
int find_counter();

void main() {
    int option; 
    puts("Type option as following:");
    puts("e - exit");
    puts("v - go to Vingenere cipher");
    puts("h - go to Hill cipher");
    printf("Your option: ");
    while (option != 'e') {
        option = getchar();
        switch (option)
        {
        case 'v':
            handleSecOption('v');
            break;
        case 'h':
            handleSecOption('h');
            break;
        case '\n':
            printf("Your option: ");
            break;
        case 'e':
        case ' ':
        case '\t':
            break;
        default:
            puts("Wrong input. Try again");
            break;
        }
    }
}

void handleSecOption(char typeOfCipher) {
    int option;
    puts("x - to exit the cipher");
    puts("e - to encrypt");
    puts("d - to decrypt");
    printf("Your option: ");
    while (option != 'x')
    {
        option = getchar();
        switch (option)
        {
        case 'e':
            typeOfCipher == 'v'? vingenere_cipher_encrypt(): hill_cipher_encrypt();
            break;
        case 'd':
            typeOfCipher == 'v' ? vingenere_cipher_decrypt(): hill_cipher_decrypt();
            break;
        case '\n':
            printf("Your option (type x to exit cipher): ");
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

void vingenere_cipher_encrypt() {
    int dimension, text_length, location, cipher_number;
    char plain_text[100], *locationPtr;
    // input session
    printf("Input number of element in your key: ");
    scanf("%d", &dimension);
    int key[dimension];
    for (int i=0; i < dimension; i++) {
        printf("Input element %d: ", i + 1);
        scanf("%d", &key[i]);
    }
    printf("Enter your test: ");
    scanf("%s", plain_text);
    text_length = strlen(plain_text);
    // encrypt session
    printf("Your cipher text is: ");
    for (int i=0; i < text_length; i++) {
        locationPtr = strchr(letters, plain_text[i]); // return address of text in letters
        location = locationPtr - letters; // find postion in array letters
        cipher_number = (location + key[i%dimension])%26;
        putchar(letters[cipher_number]);
    }
    printf("\n");
}

void vingenere_cipher_decrypt() {
    int dimension, text_length, location, cipher_number;
    char cipher_text[100], *locationPtr;
    // input session
    printf("Input number of element in your key: ");
    scanf("%d", &dimension);
    int key[dimension];
    for (int i=0; i < dimension; i++) {
        printf("Input element %d: ", i + 1);
        scanf("%d", &key[i]);
    }
    printf("Enter your test: ");
    scanf("%s", cipher_text);
    text_length = strlen(cipher_text);
    // decrypt session
    printf("Your plain text is: ");
    for (int i=0; i < text_length; i++) {
        locationPtr = strchr(letters, cipher_text[i]); // return address of text in letters
        location = locationPtr - letters; // find postion in array letters
        cipher_number = (location - key[i%dimension] + 26)%26;
        putchar(letters[cipher_number]);
    }
    printf("\n");
}

void hill_cipher_encrypt() {
    int dimension = 2, text_length, cipher_number,location, key[2][2], det_key=0, gcd=0;
    char plain_text[100], *locationPtr;
    // input session
    while (gcd != 1) {
        puts("=============Input key=============");
        for (int i=0; i < dimension * dimension; i ++) {
            printf("Element [%d][%d] is: ", i/dimension, i%dimension);
            scanf("%d",&key[i/dimension][i%dimension]);
        }
        puts("Your key is:");
        printArray(2, key);
        // validating det of key
        det_key = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
        if (det_key == 0) {
            puts("Det must not be 0");
            continue;
        }
        for(int i = 1; i <= det_key && i <= 26; i++) 
        { // finding gcd
            if(det_key % i == 0 && 26 % i == 0) gcd = i;
        }
        gcd != 1 ? puts("Must be gcd(det(key),26)=1"): printf("");
    }
    printf("Input your text: ");
    scanf("%s", plain_text);
    // encrypt session
    printf("Your cipher text is: ");
    text_length = strlen(plain_text);
    while (text_length % dimension != 0) {
        strcat(plain_text, "a");
        text_length = strlen(plain_text);
    }
    for (int i = dimension; i <= text_length; i += dimension) { // i is step to where to cut into subarray
        int sub_array[2];
        for (int j = i - dimension; j < i; j ++) { // j wil run to add element in subarray
            locationPtr = strchr(letters, plain_text[j]); // return address of text in letters
            location = locationPtr - letters; // find postion in array letters
            sub_array[j%dimension] = location;
        }
        // multiplication 2 maitrix
        for (int x = 0; x<dimension; x++) {
            cipher_number = 0;
            for (int y= 0; y < dimension; y ++) {
                cipher_number += (sub_array[y]* key[y][x]);
            }
            cipher_number = cipher_number%26;
            putchar(letters[cipher_number]);
        }      
    }
    printf("\n");
}

void hill_cipher_decrypt() {
    int dimension = 2, text_length, cipher_number,location, key[2][2], det_key=0, gcd=0;
    char cipher_text[100], *locationPtr;
    // input session
    while (gcd != 1) {
        puts("=============Input key=============");
        for (int i=0; i < dimension * dimension; i ++) {
            printf("Element [%d][%d] is: ", i/dimension, i%dimension);
            scanf("%d",&key[i/dimension][i%dimension]);
        }
        puts("Your key is:");
        printArray(2, key);
        // validating det of key
        det_key = key[0][0] * key[1][1] - key[0][1] * key[1][0];
        if (det_key == 0) {
            puts("Det must not be 0");
            continue;
        }
        for(int i = 1; i <= det_key && i <= 26; i++) 
        { // finding gcd
            if(det_key % i == 0 && 26 % i == 0) gcd = i;
        }
        gcd != 1 ? puts("Must be gcd(det(key),26)=1"): printf("");
    }
    printf("Input your text: ");
    scanf("%s", cipher_text);
    // decrypt session
    printf("Your plain text is: ");
    text_length = strlen(cipher_text);
    // creating inverse matrix
    int inverse_key[dimension][dimension];
    det_key = find_counter(det_key); // this is counter of det _key
    inverse_key[0][0] = (key[1][1] * det_key) % 26;
    inverse_key[0][1] = (-key[0][1] * det_key) % 26;
    inverse_key[1][0] = (-key[1][0] * det_key) % 26;
    inverse_key[1][1] = (key[0][0] * det_key) % 26;
    // decryption
    for (int i = dimension; i <= text_length; i += dimension) { // i is step to where to cut into subarray
        int sub_array[2];
        for (int j = i - dimension; j < i; j ++) { // j wil run to add element in subarray
            locationPtr = strchr(letters, cipher_text[j]); // return address of text in letters
            location = locationPtr - letters; // find postion in array letters
            sub_array[j%dimension] = location;
        }
        // multiplication 2 maitrix
        for (int x = 0; x<dimension; x++) {
            cipher_number = 0;
            for (int y= 0; y < dimension; y ++) {
                cipher_number += (sub_array[y]* inverse_key[y][x]);
            }
            cipher_number = (cipher_number)%26;
            if (cipher_number < 0) cipher_number += 26;
            putchar(letters[cipher_number]);
        }      
    }
    printf("\n");
}

int find_counter(int number) {
    int k = 0, remainder; // set runner to 0
    do
    {
        k++;
        remainder = (26*k+1) % number;
    } while (remainder != 0); // while to find the beutifull number of a
    return (26*k + 1) / number;
}

void printArray(int k, int arr[k][k]) {
    for (int i = 0; i < k*k; i ++) {
        if (i % k == 0 && i != 0) {
            printf("\n");
        }
        printf("%d\t", arr[i/k][i%k]);
    }
    printf("\n");
}