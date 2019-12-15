#include <stdio.h>
void main()
{
    int num1, num2, num3, num4, num5, middleNum;
    printf("Please input 1st number: ");
    scanf("%d", &num1);
    printf("Please input 2nd number: ");
    scanf("%d", &num2);
    printf("Please input 3rd number: ");
    scanf("%d", &num3);
    printf("Please input 4th number: ");
    scanf("%d", &num4);
    printf("Please input 5th number: ");
    scanf("%d", &num5);

    if (num1>num2)
	{
		middleNum=num1;
		num1=num2;
		num2=middleNum;
	}
	if (num2>num3)
	{
		middleNum=num2;
		num2=num3;
		num3=middleNum;
	}
	if (num3>num4)
	{
		middleNum=num3;
		num3=num4;
		num4=middleNum;
	}
	if (num4>num5)
	{
		middleNum=num4;
		num4=num5;
		num5=middleNum;
	}


	if (num1>num2)
	{
		middleNum=num1;
		num1=num2;
		num2=middleNum;
	}
	if (num2>num3)
	{
		middleNum=num2;
		num2=num3;
		num3=middleNum;
	}
	if (num3>num4)
	{
		middleNum=num3;
		num3=num4;
		num4=middleNum;
	}

	if (num1>num2)
	{
		middleNum=num1;
		num1=num2;
		num2=middleNum;
	}
	if (num2>num3)
	{
		middleNum=num2;
		num2=num3;
		num3=middleNum;
	}
	if (num1>num2)
	{
		middleNum=num1;
		num1=num2;
		num2=middleNum;
	}
    
    printf("%d %d %d %d %d", num1, num2, num3, num4, num5);
}