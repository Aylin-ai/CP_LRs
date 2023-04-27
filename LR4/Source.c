#include <stdio.h>            
#include <locale.h>
#include <stdlib.h>
#include "time.h"


char* strchr(char* S, char symbol);
char* strncat(char* s1, const char* s2, size_t n);

void aToHigh(char* s);
void spaceDeleter(char* s);

int main(void)
{
    setlocale(LC_ALL, "Rus");

#pragma region Task_1_1

    char str1[] = "����� � ����� � ��������, � ����� � ��������. ���� ��� ���� � �� ��";
    char* ptr = strchr(str1, '�');
    printf("������� 1.1\n%s", ptr);

#pragma endregion

#pragma region Task_1_6

    const char substr2[] = " ��������� 2";
    char* str2 = (char*)calloc(100, 1);
    const char str11[] = "������ 1 ���";

    strncat(str2, str11, my_strlen(str11));

    strncat(str2, substr2, 5);

    printf("\n������� 1.6\n%s", str2);

#pragma endregion

#pragma region Task 2.6

    char str3[80] = "�����, ����� ������, � �� ����� ������. �����, ������, ��������, �������.";

    aToHigh(str3);

    printf("\n������� 2.6\n%s", str3);

#pragma endregion

#pragma region Task 2.14

    char str4[80] = "�����, ����� ������, � �� ����� ������. �����, ������, ��������, �������.";

    spaceDeleter(str4);

    printf("\n������� 2.14\n%s\n", str4);

#pragma endregion


    return 0;
}

int my_strlen(const char* str)
{
    return (*str) ? my_strlen(++str) + 1 : 0;
}

char* strchr(char* S, char symbol) {
    int i = 0;
    while (S[i] && S[i] != symbol)
        i++;
    return symbol == S[i] ? (char*)S + i : NULL;
}

char* strncat(char* s1, const char* s2, size_t n) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++);

    for (j = 0; j < n; j++) {
        s1[i + j] = s2[j];
    }

    s1[i + j] = '\0';

    return s1;
}

void aToHigh(char* s) {
    for (int i = 0; i < my_strlen(s); i++) {
        if ((s[i] == ' ' || s[i] == ',' || s[i] == '.') && s[i + 1] == '�') {
            s[i + 1] = '�';
        }
    }
}

void spaceDeleter(char* s) {
    for (int i = 0; i < my_strlen(s); i++) {
        if (s[i] == ' ') {
            for (int j = i; j < my_strlen(s); j++) {
                s[j] = s[j + 1];
            }
        }
    }
}