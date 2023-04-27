#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "time.h"
#include <string.h>


struct T {
	char surname[10];
	char bookName[50];
	char publisher[50];
	char date[20];
};
struct Detail
{
	char name[30];
	float price;
	int quantity;
};
FILE* File;

int createFile(int n, struct T* f);
int createFileWithDetails(int n, struct Detail* details);
struct Detail getDetail(int n);
void updateDetailQuantity(int n, int newQuantity);


void main(void) {
	srand(time(0));
	setlocale(LC_ALL, "Rus");
    /*
    #pragma region Task 1

    int n;
    printf("Enter the amount of details: ");
    scanf_s("%d", &n);
    struct Detail* details = (struct Detail*)malloc(n * sizeof(struct Detail));
    int result = createFileWithDetails(n, details);
    if (result == 0)
        printf("Success");
    else if (result == -1)
    {
        printf("Failure");
    }

    #pragma endregion
    */

    /*
    #pragma region Task 1.6

    char detailName[20] = "d2";
    int amountOfChosenDetail = countLinesWithSubstring(detailName);
    printf("%d", amountOfChosenDetail);

    #pragma endregion
    */

    /*
    #pragma region Task 2

    int n = 7;
    struct Detail detail;
    detail = getDetail(n);
    printf("%s", detail.name);

    #pragma endregion
    */

    #pragma region Task 2.3.6

    updateDetailQuantity(1, 10);

    #pragma endregion




}

int createFile(int n, struct T* f) {
    if (fopen_s(&File, "FB.txt", "w")) {
        printf("Error");
        return -1;
    }
    else {
        for (int i = 0; i < n; i++) {
            printf("Surname: ");
            scanf_s(" %9s", f[i].surname, (unsigned)_countof(f[i].surname));
            printf("Book`s name: ");
            scanf_s(" %49s", f[i].bookName, (unsigned)_countof(f[i].bookName));
            printf("Publisher: ");
            scanf_s(" %49s", f[i].publisher, (unsigned)_countof(f[i].publisher));
            printf("Date of publishment: ");
            scanf_s(" %19s", f[i].date, (unsigned)_countof(f[i].date));
            fprintf(File, "Author: %s, Book: %s, Publisher: %s, Date of publishment: %s\n", f[i].surname, f[i].bookName, f[i].publisher, f[i].date);
            printf("%s %s %s %s\n", f[i].surname, f[i].bookName, f[i].publisher, f[i].date);
        }
        fclose(File);
        return 0;
    }
}

int createFileWithDetails(int n, struct Detail* details) {
    if (fopen_s(&File, "Details.txt", "w")) {
        printf("Error");
        return -1;
    }
    else {
        for (int i = 0; i < n; i++) {
            printf("Detail`s name: ");
            scanf_s(" %9s", details[i].name, (unsigned)_countof(details[i].name));
            printf("Detail`s price: ");
            scanf_s(" %f", &details[i].price);
            printf("Detail`s quantity: ");
            scanf_s(" %d", &details[i].quantity);
            fprintf(File, "%s %.2f %d \n", details[i].name, details[i].price, details[i].quantity);
            printf("%s %.2f %d\n", details[i].name, details[i].price, details[i].quantity);
        }
        fclose(File);
        return 0;
    }
}

int countLinesWithSubstring(char* substring) {
    if (fopen_s(&File, "Details.txt", "r")) {
        printf("Не удалось открыть файл\n");
        return -1;
    }

    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), File) != NULL) {
        if (strstr(line, substring) != NULL) {
            count++;
        }
    }

    fclose(File);
    return count;
}

struct Detail getDetail(int n) {
    if (fopen_s(&File, "Details.txt", "r")) {
        printf("Не удалось открыть файл\n");
        exit(1);
    }

    // Определяем размер одной записи
    int recordSize = sizeof(struct Detail);

    // Устанавливаем позицию в файле на запись под номером n
    if (fseek(File, (n - 1) * recordSize, SEEK_SET) != 0) {
        printf("Ошибка при установке позиции в файле.\n");
        exit(1);
    }

    struct Detail detail;
    fread(detail.name, sizeof(detail.name), 1, File);

    // Закрываем файл
    fclose(File);

    // Возвращаем строку
    return detail;
}

void updateDetailQuantity(int n, int newQuantity) {
    char* detail = (char*)malloc(50 * sizeof(char));

    // Открытие файла в режиме чтения и записи
    if (fopen_s(&File, "Details.txt", "r+")) {
        printf("Не удалось открыть файл\n");
        exit(1);
    }

    // Установка позиции в файле на запись под номером n
    int recordSize = sizeof(struct Detail);
    if (fseek(File, (n - 1) * recordSize, SEEK_SET) != 0) {
        printf("Ошибка при установке позиции в файле.\n");
        exit(1);
    }

    // Считывание структуры из файла
    fread(detail, recordSize, 1, File);

    char* name = strtok_s(detail, " ", &detail);
    char* price = strtok_s(detail, " ", &detail);
    char* quantity = strtok_s(detail, " ", &detail);

    char str[sizeof(name) + sizeof(price) + sizeof(quantity)] = "";

    strcat_s(str, sizeof(name) + sizeof(price) + sizeof(quantity), name);
    strcat_s(str, sizeof(name) + sizeof(price) + sizeof(quantity), " ");
    strcat_s(str, sizeof(name) + sizeof(price) + sizeof(quantity), price);
    strcat_s(str, sizeof(name) + sizeof(price) + sizeof(quantity), " ");
    strcat_s(str, sizeof(name) + sizeof(price) + sizeof(quantity), quantity);


    // Запись измененной структуры в файл
    fseek(File, (n - 1) * recordSize, SEEK_SET);
    if (fwrite(str, recordSize, 1, File) != 1) {
        printf("Ошибка при записи в файл.\n");
        exit(1);
    }
    // Закрытие файла
    fclose(File);
}



