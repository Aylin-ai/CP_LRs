#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "time.h"

int VolumeOfParallelepiped(int l, int w, int h) {
	return l * w * h;
}

void Numbers(double number, int* masOfNumbers) {
	*masOfNumbers = number;
	masOfNumbers++;

	*masOfNumbers = number + 1;
}

int main() {
	srand(time(0));

	//Task 1.1
	/*#pragma region Task 1.1

	int n = rand() % 10;
	int m = rand() % 10;

	int* masA = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		masA[i] = rand() % 200 - 100;
		printf("%d ", masA[i]);
	}
	printf("\n");

	int* masB = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++) {
		masB[i] = rand() % 200 - 100;
		printf("%d ", masB[i]);
	}
	printf("\n");

	int* masC = (int*)malloc((n + m) * sizeof(int));
	int* ptrC = masC;

	for (int i = 0; i < n; i++) {
		*ptrC = masA[i];
		ptrC++;
	}
	for (int i = 0; i < m; i++) {
		*ptrC = masB[i];
		ptrC++;
	}

	for (int i = 0; i < n + m; i++) {
		printf("%d ", masC[i]);
	}

	#pragma endregion*/

	//Task 1.6
	/*#pragma region Task 1.6

	int n = rand() % 20;

	int* massive = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		massive[i] = rand() % 200 - 100;
		printf("%d ", massive[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			massive[i] *= 2;
		}
		printf("%d ", massive[i]);
	}

	#pragma endregion*/

	//Task 2.6
	/*#pragma region Task 2.6

	int length, width, height;

	printf("Enter the length of parallelepiped: ");
	scanf_s("%d", &length);

	printf("Enter the width of parallelepiped: ");
	scanf_s("%d", &width);

	printf("Enter the height of parallelepiped: ");
	scanf_s("%d", &height);

	int volume = VolumeOfParallelepiped(length, width, height);
	printf("The volume of parallelepiped is: %d", volume);

	#pragma endregion*/

	//Task 2.14
	/*#pragma region Task 2.14

	double number;
	printf("Enter the number: ");
	scanf_s("%lf", &number);

	int masOfNumbers[2];

	Numbers(number, masOfNumbers);

	printf("\n");
	for (int i = 0; i < 2; i++) {
		printf("%d ", masOfNumbers[i]);
	}

	#pragma endregion*/

}