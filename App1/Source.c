#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "time.h"

typedef int(*TF)(int);
typedef float(*F)(int, int);

int T1func1(int x);
int T1func2(int x);
double Function(TF func1, TF func2, int a);

int T3func1(int a, int b);
int T3func2(int a, int b);
int T3func3(int a, int b);
int T3func4(int a, int b);

float (*fb(char c)) (int, int);

struct Person* PersonFunction();

struct Detail
{
	char name[50];
	int price;
	int quantity;
};

struct Person
{
	char name[10];
	char surname[10];
	char lastname[10];
	int age;
};

void main(void)
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");

#pragma region Task 2.5

	printf("%.2f\n\n", Function(T1func1, T1func2, 5));

#pragma endregion

#pragma region Task 3

	printf("%.2f\n", Function(T1func1, T1func2, 5));

#pragma endregion

#pragma region Task 4

	int a, b;
	int chose;
	int result = 0;

	while (1){
		printf("Выберите одно из 4 действий:\n");
		printf("1) Возведение числа а в степень b\n");
		printf("2) Умножение числа а на b\n");
		printf("3) Остаток от деления а на b\n");
		printf("4) Проверка кратности a и b\n");
		printf("5) Выход\n");

		scanf_s("%d", &chose);

		if (chose == 5)
			break;

		printf("Введите числа a и b:");
		scanf_s("%d", &a);
		scanf_s("%d", &b);

		switch (chose)
		{
		case 1:
			result = T3func1(a, b);
			break;
		case 2:
			result = T3func2(a, b);
			break;
		case 3:
			result = T3func3(a, b);
			break;
		case 4:
			result = T3func4(a, b);
			break;
		default:
			break;
		}
		printf("Result is %d\n", result);
	}

#pragma endregion

#pragma region Task 5.6

	struct Detail details[10] = { { "detail1", rand() % 100, (rand() % 100) * 100 },
	{ "detail2", rand() % 100, (rand() % 100) * 100 },
	{ "detail3", rand() % 100, (rand() % 100) * 100 },
	{ "detail4", rand() % 100, (rand() % 100) * 100 },
	{ "detail5", rand() % 100, (rand() % 100) * 100 },
	{ "detail6", rand() % 100, (rand() % 100) * 100 },
	{ "detail7", rand() % 100, (rand() % 100) * 100 },
	{ "detail8", rand() % 100, (rand() % 100) * 100 },
	{ "detail9", rand() % 100, (rand() % 100) * 100 },
	{ "detail10", rand() % 100, (rand() % 100) * 100 } };


	int expensiveDetail = details[0].price;
	char detailName[50];
	strcpy(detailName, details[0].name);
	for (int i = 0; i < 10; i++) {
		if (expensiveDetail < details[i].price) {
			expensiveDetail = details[i].price;
			strcpy(detailName, details[i].name);
		}
	}

	for (int i = 0; i < 10; i++){
		printf("%s %d %d\n", details[i].name, details[i].price, details[i].quantity);
	}

	printf("The most expensive detail: %s, its price: %d\n\n", detailName, expensiveDetail);


#pragma endregion

#pragma region Task 6.3

	struct Person* persons = malloc(5 * sizeof(struct Person));
	persons = PersonFunction(persons);

	for (int i = 0; i < 5; i++)
	{
		printf("\n%s %s %s, %d", persons[i].surname, persons[i].name,
			persons[i].lastname, persons[i].age);
	}

	free(persons);
	scanf_s("%s", detailName);

#pragma endregion

}

int T1func1(int x) {
	return 15 - 4 * x;
}

int T1func2(int x) {
	return x * x * x + x * x - 1;
}

double Function(TF func1, TF func2, int a){
	return ((func1(a)) + func2(a)) / (double)func1(a);
}


int T3func1(int a, int b){
	int x = raiseToPow(a, b);
	return x;
}
int T3func2(int a, int b){
	int x = a * b;
	return x;
}
int T3func3(int a, int b){
	int x = a % b;
	return x;
}
int T3func4(int a, int b){
	if (a % b == 0)
		return 1;
	else
		return 0;
}


int raiseToPow(int x, int power)
{
	int result;
	result = 1;
	for (int i = 1; i <= power; i++){
		result *= x;
	}
	return result;
}

struct Person* PersonFunction(struct Person* persons)
{
	for (int i = 0; i < 5; i++)
	{
		printf("Enter the data of person %d\n", i + 1);
		printf("Name: ");
		scanf_s("%9s", persons[i].name, (unsigned)_countof(persons[i].name));
		printf("Surname: ");
		scanf_s("%9s", persons[i].surname, (unsigned)_countof(persons[i].surname));
		printf("Lastname: ");
		scanf_s("%9s", persons[i].lastname, (unsigned)_countof(persons[i].lastname));
		printf("Age: ");
		scanf_s("%d", &persons[i].age);
	}
	return persons;
}
