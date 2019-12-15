#include <stdio.h>

void main()
{
    float avaScore;
    int studentID;
    char studentName[30];
    printf("Type your name: ");
    fgets(studentName, sizeof(studentName), stdin); // read string
    printf("Type your studentID: ");
    scanf("%d", &studentID);
    for (int i = 0; i < 5; i++)
    {
        float score;
        printf("Type subject %d score: ", i + 1);
        scanf("%f", &score);
        avaScore += score;
    }
    printf("Student: %sID: %d\n", studentName, studentID);
    printf("Avarange Score: %f", avaScore / 5);
}