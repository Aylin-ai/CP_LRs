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
void changeValueInLine(int lineNumber, int newValue);

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

    changeValueInLine(2, 428);

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

void changeValueInLine(int lineNumber, int newValue) {
    FILE* file;
    if (fopen_s(&file, "Details.txt", "r")) {
        printf("Не удалось открыть файл\n");
        exit(1);
    }

    // Читаем все строки файла в память
    char** lines = NULL;
    char buffer[1024];
    int lineCount = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        lines = (char**)realloc(lines, sizeof(char*) * (lineCount + 1));
        lines[lineCount] = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy_s(lines[lineCount], strlen(buffer) + 1, buffer);
        lineCount++;
    }

    // Закрываем файл
    fclose(file);

    // Изменяем нужную строку
    if (lineNumber <= lineCount) {
        char* line = lines[lineNumber - 1];

        // Разбиваем строку на отдельные значения
        char* token;
        char* context = NULL;
        token = strtok_s(line, " ", &context);
        int currentTokenPosition = 1;
        char newLine[1024] = { 0 };
        while (token != NULL) {
            if (currentTokenPosition == 3) {
                // Меняем значение на новое
                char newValueString[32] = { 0 };
                sprintf_s(newValueString, sizeof(newValueString), "%d\n", newValue);
                strcat_s(newLine, sizeof(newLine), newValueString);
                if (token[strlen(token) - 1] != '\n') { // проверяем, является ли токен последним в строке
                    strcat_s(newLine, sizeof(newLine), " ");
                }
            }
            else {
                strcat_s(newLine, sizeof(newLine), token);
                strcat_s(newLine, sizeof(newLine), " ");
            }
            token = strtok_s(NULL, " ", &context);
            currentTokenPosition++;
        }

        // Заменяем старую строку на новую
        free(lines[lineNumber - 1]);
        lines[lineNumber - 1] = (char*)malloc(sizeof(char) * (strlen(newLine) + 1));
        strcpy_s(lines[lineNumber - 1], strlen(newLine) + 1, newLine);
    }

    // Открываем файл на перезапись
    if (fopen_s(&file, "Details.txt", "w")) {
        printf("Не удалось открыть файл\n");
        exit(1);
    }

    // Перезаписываем все строки в файл
    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s", lines[i]);
        free(lines[i]);
    }
    free(lines);

    fclose(file);
}