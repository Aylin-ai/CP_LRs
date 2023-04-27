#include <stdio.h>  
#include <windows.h>

int main(void)
{
	int i = 65;
	int number1, number2;
	int low = 0;
	double x, y;
	int x1 = 0, x2 = 0, x3 = 0;


	//Task1
	//printf_s("Enter the number for first task: ");
	//scanf_s("%lf", &x);

	//if (x > 1)
	//	y = x;
	//else if (0 < x <= 1)
	//	y =  x * x * x * x;
	//else
	//	y = x * x;
	//printf_s("%lf", y);

	//printf_s("\nEnter the numbers for second task: ");
	//scanf_s("%d", &x1);
	//scanf_s("%d", &x2);
	//scanf_s("%d", &x3);

	//if (x1 % 2 == 0 && x2 % 2 == 0 && x3 % 2 == 0)
	//	printf_s("\nYes\n");
	//else if (x1 % 2 != 0 && x2 % 2 != 0 && x3 % 2 != 0)
	//	printf_s("\nYes\n");
	//else
	//	printf_s("\nNo\n");


	//Task2
	while (i < 91) {
		if (i % 2 == 0)
			printf_s("%c ", i);
		i++;
	}

	printf_s("\nEnter the number with last zero: ");
	scanf_s("%d", &number1);
	scanf_s("%d", &number2);
	while (1) {
		if (number2 == 0 || number1 == 0)
			break;
		if (number1 < number2)
			low = 1;
		number1 = number2;
		scanf_s("%d", &number2);
	}
	if (low == 1)
		printf_s("Rising\n");
	else
		printf_s("Not rising\n");

	system("pause");
	return 0;
}