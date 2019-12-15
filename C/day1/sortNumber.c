#include <stdio.h>
void main()
{
   int num1, num2, num3, num4, num5, numbers[5], number;
   printf("Type 5 number:\n");
   for (int i = 0; i < 5; i++)
   {
      scanf("%d", &number);
      numbers[i] = number;
      // for(int x= 0; x <(i+1); x++){
      //    int a = numbers[i];
      //    if (numbers[i] < numbers[x]) {
      //       numbers[i] = numbers[x];
      //       numbers[x] = a;
      //    }
      // }
   }
   for (int i=0; i<5; i++) {
      for (int x=0; x <i+1; x++) {
         if (numbers[i] <numbers[x]) {
            int temp;
            temp = numbers[i];
            numbers[i] = numbers[x];
            numbers[x] = temp;
         }
      }
   }
   printf("The numbers arranged in ascending order are given below: \n");
   for (int i = 0; i < 5; ++i)
      printf("%d\n", numbers[i]);
}