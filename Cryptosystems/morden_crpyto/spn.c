#include <stdio.h>
#include <math.h>
#include <string.h>

char letters[26]="abcdefghijklmnopqrstuvwxyz";
void xOR_key(), subtitution(), permutation();
int convertBinaryToDecimal(), convertDecimalToBinary();

void main() {
    // l is number of blocks, m is number of bits in block
    int l=4, m=4, Nr=4, key[32] = {0,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,0,1,1,0,0,0,1,1,1,1,1,1};
    int piS[16] ={ 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7}; // try this first
    int piP[16] = {1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16}; 
    int input[16] = {0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1};
    // input session
    // for (int i = 0; i < 16; i++) {
    //     printf("Enter bit %d of %d number: ", i%4, i/4);
    //     scanf("%d",&input[i]);
    // }
    // for (int i = 0; i < 32; i++) {
    //     printf("Enter bit %d of %d number: ", i%4, i/4);
    //     scanf("%d", &key[i]);
    // }
    
    // ecrypt session
    // runing round
    for (int j = 0; j < Nr + 1; j ++) {
        printf("Round %d\n", j + 1);
        int sub_key[16];
        // extracting sub_key
        for (int x = j * Nr; x < 16 + j*Nr ; x ++) {
            sub_key[x-j*Nr] = key[x]; 
        }
        if (j == Nr) {
            xOR_key(sub_key, input);
            printf("\n");
        }
        else if (j == Nr-1) {
            // last round
            // 1 round more to the last
            // input  XOR  key
            xOR_key(sub_key, input);
            // subtitution
            subtitution(piS, input);
            printf("\n");
        } 
        else {
            // input  XOR  key
            xOR_key(sub_key, input);
            // subtitution
            subtitution(piS, input);
            // permutation
            printf("\n");
            permutation(piP, input);
            printf("\n");
        }
    }
    puts("Filnal result is: ");
    for (int a = 0; a < 16; a ++) {
        printf("%d", input[a]);
    }
}

void permutation(int piP[16], int input[16]) {
    int cpyInput[16];
    for (int i = 0; i < 16 ; i++) {
        cpyInput[i] = input[piP[i] - 1 ];
    }
    for (int j = 0; j < 16; j ++) {
        input[j] = cpyInput[j];
    }
}

void subtitution (int piS[16], int input[16]) {
    int decimail_num;
    for (int i = 0; i <= 16 - 4; i +=4) {
        int binary_num[4];
        for (int j = i; j < i + 4; j++) {
            if (i == 0) {
                binary_num[j] = input[j];
            } else binary_num[j%i] = input[j];
        }
        decimail_num = convertBinaryToDecimal(binary_num);
        // subtition with piS
        decimail_num = piS[decimail_num];
        // convert to binary
        convertDecimalToBinary(binary_num, decimail_num);
        for (int x = i; x < i + 4; x++) {
            if (i == 0) {
                input[x] = binary_num[x];
            } else input[x] = binary_num[x%i];
        }
    }
}

void xOR_key(int sub_key[16], int input[16]) {
    printf("Input: ");
    for (int i = 0; i < 16; i ++) {
        printf("%d", input[i]);
        input[i] = input[i] ^ sub_key[i];
    }
}

int convertDecimalToBinary(int binary_num[4],int decimal) {
    for (int i = 0; i < 4; i ++) {
        binary_num[4 - (i+1)] = decimal % 2;
        decimal = decimal/2;
    }
    // for (int x = 0; x < 4; x++) {
    //     printf("%d", binary_num[x]);
    // }
}

int convertBinaryToDecimal(int binary_num[4])
{
    int decimal_num =0;
    for (int i = 0; i < 4; i ++) {
        decimal_num += binary_num[i] == 1 ? pow(2, 4 - (i+1)): 0;
    }
    return decimal_num;
}