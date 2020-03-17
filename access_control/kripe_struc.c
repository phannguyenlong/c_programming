#include <stdio.h>
#include <string.h>

void printArray(int arr[100][100]);
int checkPath(int,int, int arr[100][100]);

void main ()
{
	int i=0,k=0;
	printf("How many states you want ? ");
	scanf("%d",&k);
	char label[100][20];
	for (i=0; i<k;i++){	
		printf(" Input label for s[%d] = ",i);
		scanf("%s", label[i]);	
    }    
    int transition[100][100];
    int s1,s2, j=0;
	char trans[4] = "";
	while (1) {
		char des[5] = "";
    	printf("Input transition (type e to exit): ");
    	scanf("%s",trans);
		char * token = strtok(trans, "-"); // slipt it
		if (*(trans) == 'e') {
			break;
		}
    	sscanf(token, "%d", &s1);
    	sscanf(token + 2, "%d", &s2);
    	transition[s1+1][j] = s2 + 1; // stage start from s1
    	j++;
	}
	printArray(transition);
	
	char path[100];
	int sourse, des, answer = 1;
	printf("Check path if path belong to Kripe: ");
	scanf("%s", path);
	char * ptr = strtok(path, "-"); // slipt it
	for (int i=2; path[i+1] != '\0'; i+=2) {
		sscanf(ptr + i, "%d", &des);
		sscanf(ptr + i -2, "%d", &sourse);
		printf("FIND %d-%d:\n", sourse,des);
		if (!checkPath(des+1,sourse+1,transition)) {
			answer = 0;
			break;
		}
	}
	if (answer) {
		puts("\n Answer is YES");
	} else {
		puts("\n Answer is NO");
	}
}

int checkPath(int des, int source, int arr[100][100]) {
	for (int i=0; i < 100; i++) {
		printf("%d and %d || ", arr[des][i], source);
		if (arr[source][i] == des) {
			puts("PATH FOUND");
			return 1;
		}
	}
	return 0;
}

void printArray(int numbers[100][100])
{
    for(int m = 0; m <8; m++) {
        for(int n = 0; n < 8; n++)
        {
            printf("%5d\t", numbers[m][n]);
        }
        printf("\n");
    }
}

