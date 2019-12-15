#include <stdio.h>
#include <string.h>

void shift_cipher_encrypt(), shift_cipher_decrypt();
void subtitution_cipher_decrypt(),subtitution_cipher_encrypt();
void affine_cipher_encrypt(), affine_cipher_decrypt();
void handleSecOption(char);

void main() {
    int option; 
    puts("e - exit");
    puts("s - go to shift cipher");
    puts("t - subtitution cipher");
    puts("a - go to Affine cipher");
    printf("Your option: ");
    while (option != 'e') {
        option = getchar();
        switch (option)
        {
        case 's':
            handleSecOption('s');
            break;
        case 't':
            handleSecOption('t');
            break;
        case 'a':
            handleSecOption('a');
            break;
        case '\n':
            printf("Your option: ");   
            break;
        case ' ':
        case '\t':
        case 'e':
            break;
        default:
            puts("Wrong input");
            break;
        }
    }
}

void handleSecOption(char typeOfCipher) {
    int option;
    puts("e - encrypt");
    puts("d - derypt");
    puts("x - to exit cipher");
    while (option != 'x'){
        option = getchar();
        switch (option)
        {
        case 'e':
            if (typeOfCipher == 'a') affine_cipher_encrypt();
            else if (typeOfCipher == 't') subtitution_cipher_encrypt();
            else if (typeOfCipher == 's') shift_cipher_encrypt();
            break;
        case 'd':
            if (typeOfCipher == 'a') affine_cipher_decrypt();
            else if (typeOfCipher == 't') subtitution_cipher_decrypt();
            else if (typeOfCipher == 's') shift_cipher_decrypt();
            break;
        case ' ':
        case '\t':
        case 'x':
            break;
        case '\n':
            printf("Your option (type x to exit cipher): ");
            break;
        default:
            puts("Wrong input");
            break;
        }
    }
}

void affine_cipher_encrypt() {
    int a,b, gcd = 2, text_lenght;
    char text[100], letters[26]="abcdefghijklmnopqrstuvwxyz";
    printf("Input your text: ");
    scanf("%s", text);
    // validating a
    while ( gcd != 1) {
        int i;
        printf("Input a: ");
        scanf("%d", &a);
        for(i = 1; i <= a && i <= 26; i++)
        {
            if(a % i == 0 && 26 % i == 0) gcd = i;
        }
        gcd != 1 ? printf("Must be gcd(a,26)=1\n"): printf("");
    }
    printf("Input b: ");
    scanf("%d", &b);
    // encrypt session
    printf("Encrypt text is: ");
    text_lenght = strlen(text);
    for (int i = 0; i < text_lenght ; i ++) {
        for (int j =0; j < 26; j ++) {
            if (text[i] == letters[j]) {
                int location = (a*j + b) % 26;
                printf("%c", letters[location]);
            }
        }
    }
    printf("\n");
}

void affine_cipher_decrypt() {
    int a,b, k, a_counter, gcd = 2, text_lenght, remainder;
    char cipher_text[100], letters[26]="abcdefghijklmnopqrstuvwxyz";
    printf("Input your text: ");
    scanf("%s", cipher_text);
    // validating a
    while ( gcd != 1) {
        int i;
        printf("Input a: ");
        scanf("%d", &a);
        for(i = 1; i <= a && i <= 26; i++)
        {
            if(a % i == 0 && 26 % i == 0) gcd = i;
        }
        gcd != 1 ? printf("Must be gcd(a,26)=1\n"): printf("");
    }
    printf("Input b: ");
    scanf("%d", &b);
    // finding a^-1
    k = 0; // set runner to 0
    do
    {
        k++;
        remainder = (26*k+1) % a;
    } while (remainder != 0); // while to find the beutifull number of a
    printf("k is %d\n", k);
    a_counter = (26*k + 1) / a;
    printf("a_counter: %d\n", a_counter);
    // encryption session
    text_lenght = strlen(cipher_text);
    for (int i = 0; i < text_lenght ; i ++) {
        for (int j =0; j < 26; j ++) {
            if (cipher_text[i] == letters[j]) {
                int location = (a_counter*(j - b)) % 26;
                if (location < 0) location += 26; // convert the negative
                printf("%c", letters[location]);
            }
        }
    }
    printf("\n");
}

void subtitution_cipher_encrypt() {
    char sub_array[26],sub_Text[100],array[26]="abcdefghijklmnopqrstuvwxyz";
    // input session
    for (int i=0;i<26;i++){
        printf("input a permutation: ");
        scanf(" %c",&sub_array[i]);
        for (int j=0;j<i;j++){
            while (sub_array[i]==sub_array[j]){
                printf("the letter have been putted. Input again: ");
                scanf(" %c",&sub_array[i]);
                j = 0; // reset to validate from begginning
            }
        }
    }
    // ecryption session
    char Text[100];
    printf("Enter sentence: ");
    scanf(" %s",&Text);
    int Text_length;
    Text_length=strlen(Text);
    for (int i=0;i<Text_length;i++){
        for (int j=0;j<26;j++){
            if (Text[i]==array[j]){
                sub_Text[i]=sub_array[j];
                break;
            }
        }
    }
    printf("Your encrypt text is: ");
    for (int i=0;i<Text_length;i++){
        printf("%c",sub_Text[i]);
    }
    printf("\n");
}

void subtitution_cipher_decrypt() {
    char sub_array[26],sub_Text[100],array[26]="abcdefghijklmnopqrstuvwxyz";
    for (int i=0;i<26;i++){
        printf("input a permutation: ");
        scanf(" %c",&sub_array[i]);
        for (int j=0;j<i;j++){
            while (sub_array[i]==sub_array[j]){
                printf("the letter have been putted. Input again: ");
                scanf(" %c",&sub_array[i]);
                j = 0; // reset
            }
        }
    }
    char Text[100];
    printf("Enter sentence: ");
    scanf(" %s",&sub_Text);
    int Text_length;
    Text_length=strlen(sub_Text);
    for (int i=0;i<Text_length;i++){
        for (int j=0;j<26;j++){
            if (sub_Text[i]==sub_array[j]){
                Text[i]=array[j];
            }
        }
    }
    printf("Your encrypt text is: ");
    for (int i=0;i<Text_length;i++){
        printf("%c",Text[i]);
    }
    printf("\n");
}

void shift_cipher_decrypt() {
    char cipherText[100], letters[26] = "abcdefghijklmnopqrstuvwxyz";
    int k, text_lenght;
    // inptu session
    printf("Input your text: ");
    scanf("%s", cipherText);
    printf("Your text is: %s\n", cipherText);
    printf("Input K: ");
    scanf("%d", &k);
    // generate table of data
    // convert to number
    text_lenght = strlen(cipherText);
    int arr[text_lenght];
    char decrypt_text[text_lenght];
    for (int i = 0; i < text_lenght; i ++) {
        for (int x = 0; x <26; x ++) {
            if (cipherText[i]  == letters[x]) {
                arr[i] = x;
            }
        }
    }
    // decrytion
    for (int y = 0; y < text_lenght; y ++) {
        arr[y] = (arr[y] - k)%26;
        if (arr[y] < 0) arr[y] = 26 + arr[y];
    }
    // convert to text
    printf("Your cipher text: ");
    for (int i = 0; i < text_lenght; i ++) {
        decrypt_text[i] = letters[arr[i]];
        printf("%c", decrypt_text[i]);
    }
    printf("\n");
    puts("End of encrypt");
}

void shift_cipher_encrypt() {
    char plainText[100], letters[26] = "abcdefghijklmnopqrstuvwxyz";
    int k, text_lenght; 
    // inptu session
    // getchar(); // caching new line character avoid passing fgets
    printf("Input your text: ");
    scanf("%s", plainText);
    printf("Your text is: %s\n", plainText);
    printf("Input K: ");
    scanf("%d", &k);
    // generate table of data
    // convert to number
    text_lenght = strlen(plainText);
    int arr[text_lenght];
    char encrypt_text[text_lenght];
    for (int i = 0; i < text_lenght; i ++) {
        for (int x = 0; x <26; x ++) {
            if (plainText[i]  == letters[x]) {
                arr[i] = x;
            }
        }
    }
    // encrytion
    for (int y = 0; y < text_lenght; y ++) {
        arr[y] = (arr[y] + k)%26;
    }
    // convert to text
    printf("Your cipher text: ");
    for (int i = 0; i < text_lenght; i ++) {
        encrypt_text[i] = letters[arr[i]];
        printf("%c", encrypt_text[i]);
    }
    printf("\n");
    puts("End of encrypt");
}