#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "time.h"

int T1func1(int x);
int T1func2(int x);
double Function(int (*func1) (int), int (*func2) (int), int a);
struct Person* PersonFunction(struct Person* persons);

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

	printf("%f\n\n", Function(T1func1, T1func2, 5));

	#pragma endregion

	#pragma region Task 5.6

	struct Detail details[10] = { {"detail1", rand() % 100, (rand() % 100) * 100},
	{"detail2", rand() % 100, (rand() % 100) * 100} ,
	{"detail3", rand() % 100, (rand() % 100) * 100} ,
	{"detail4", rand() % 100, (rand() % 100) * 100} ,
	{"detail5", rand() % 100, (rand() % 100) * 100} ,
	{"detail6", rand() % 100, (rand() % 100) * 100} ,
	{"detail7", rand() % 100, (rand() % 100) * 100} ,
	{"detail8", rand() % 100, (rand() % 100) * 100} ,
	{"detail9", rand() % 100, (rand() % 100) * 100} ,
	{"detail10", rand() % 100, (rand() % 100) * 100} };


	int expensiveDetail = details[0].price;
	char detailName[50];
	strcpy(detailName, details[0].name);
	for (int i = 0; i < 10; i++) {
		if (expensiveDetail < details[i].price) {
			expensiveDetail = details[i].price;
			strcpy(detailName, details[i].name);
		}
	}
	printf("Самая дорогая деталь: %s, ее цена: %d\n\n", detailName, expensiveDetail);
	

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

	#pragma endregion

}

int T1func1(int x) {
	return 15 - 4 * x;
}

int T1func2(int x) {
	return x * x * x + x * x - 1;
}

double Function(int (*func1) (int), int (*func2) (int), int a) {
	return ((func1(a)) + func2(a)) / (double)func1(a);
}

struct Person* PersonFunction(struct Person* persons)
{
	for (int i = 0; i < 5; i++)
	{
		printf("Введите данные о человеке %d\n", i);
		printf("Имя: ");
		scanf_s("%9s", persons[i].name, (unsigned)_countof(persons[i].name));
		printf("Фамилия: ");
		scanf_s("%9s", persons[i].surname, (unsigned)_countof(persons[i].surname));
		printf("Отчество: ");
		scanf_s("%9s", persons[i].lastname, (unsigned)_countof(persons[i].lastname));
		printf("Возраст: ");
		scanf_s("%d", &persons[i].age);
	}
	return persons;
}