#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main() {
	srand(time(0));

	//Задание 1.1
	/*#pragma region Задание 1.1

	int massiveA[10];
	int number_1_1 = 0;
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		massiveA[i] = rand() % 200 - 100;
		if (massiveA[i] < 0) {
			number_1_1++;
			sum += massiveA[i];
		}
		printf("%i ", massiveA[i]);
	}
	printf("\nThe amount of negative numbers in massive: ");
	printf("%i\n", number_1_1);

	printf("The sum of all negative numbers from the massive: ");
	printf("%i\n", sum);


	#pragma endregion*/

	//Задание 1.6
	/*#pragma region Задание 1.6

	int mas[10];
	int number_1_6 = 0;

	for (int i = 0; i < 10; i++) {
		mas[i] = rand() % 200 - 100;
		if (mas[i] % 2 != 0)
			number_1_6++;
		printf("%d ", mas[i]);
	}
	printf("\nThe amount of needed number is: ");
	printf("%d", number_1_6);

	#pragma endregion*/

	//Задание 2.1
	/*#pragma region Задание 2.1

	int massive[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			massive[i][j] = 0;
			if (i == j) {
				massive[i][j] = i;
			}
			printf("%d ", massive[i][j]);
		}
		printf("\n");
	}

	#pragma endregion*/

	//Задание 2.6
	/*#pragma region Задание 2.6

	int x[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			x[i][j] = rand() % 200 - 100;
			printf("%d \t", x[i][j]);
		}
		printf("\n");
	}

	int minElem = x[0][0];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (x[i][j] < minElem) {
				minElem = x[i][j];
			}
		}
	}
	printf("The smallest number of this massive is: ");
	printf("%d", minElem);

	#pragma endregion*/


	return 0;
}