#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "time.h"
#include <string.h>

#define MAX_STR_LEN 20

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
void printEveryLine();
void getDetail(int n);
void changeValueInLine(int lineNumber, int newValue);

typedef struct Node {
    char str[MAX_STR_LEN + 1];
    struct Node* next;
} Node;

Node* createNode(char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy_s(newNode->str, MAX_STR_LEN + 1, str);
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->str);
        current = current->next;
    }
}

void deleteSecondLast(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    if ((*head)->next->next == NULL) {
        Node* temp = (*head)->next;
        free(temp);
        (*head)->next = NULL;
        return;
    }
    Node* current = *head;
    while (current->next->next->next != NULL) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void insertBeforeK(Node** head, int k, char* str) {
    if (*head == NULL || k <= 1) {
        // ���� ������ ���� ��� k ������ ��� ����� 1, �� ��������� ������� � ������ ������
        Node* newNode = createNode(str);
        newNode->next = *head;
        *head = newNode;
        return;
    }
    // ���� k-�� ������� ������
    Node* current = *head;
    for (int i = 1; i < k - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    // ������� ����� ������� � ��������� ��� ����� k-�� ���������
    Node* newNode = createNode(str);
    newNode->next = current->next;
    current->next = newNode;
}



void main(void) {
    srand(time(0));
    setlocale(LC_ALL, "Rus");

    int n = 0;
    char* detailName = malloc(20 * sizeof(char));
    int newValue = 0;

    int choice = 0;
    while (1) {
        printf("��������:\n");
        printf("1) �������� ������ ���� � ��������\n");
        printf("2) ����� ���� �������\n");
        printf("3) ����� ������� � ������������ ������\n");
        printf("4) ����� ������ ��� ������� n\n");
        printf("5) ��������� ���������� ������\n");
        printf("6) �����\n");
        scanf_s("%d", &choice);

        if (choice == 6)
            break;

        switch (choice)
        {
        case 1:
            printf("Enter the amount of details: ");
            scanf_s("%d", &n);
            struct Detail* details = (struct Detail*)malloc(n * sizeof(struct Detail));
            int result = createFileWithDetails(n, details);
            if (result == 0)
                printf("Success\n");
            else if (result == -1)
            {
                printf("Failure\n");
            }
            free(details);
            break;
        case 2:
            printEveryLine();
            break;
        case 3:
            printf("������� ��� ������: ");
            scanf_s("%s", detailName, 20);
            int amountOfChosenDetail = countLinesWithSubstring(detailName);
            printf("�������: %d\n", amountOfChosenDetail);
            break;
        case 4:
            printf("������� ����� ������: ");
            scanf_s("%d", &n);
            getDetail(n);
            break;
        case 5:
            printf("������� ����� ������, � ������� ������ �������� ����������: ");
            scanf_s("%d", &n);
            printf("������� ����� ���������� �������: ");
            scanf_s("%d", &newValue);
            changeValueInLine(n, newValue);
            printf("�����\n");
            break;
        default:
            break;
        }

    }
    
    
    /*
    #pragma region Part 2

    Node* head = createNode("��� 1 �������");
    Node* current = head;

    // ��������� ��������� ��������
    for (int i = 2; i <= 10; i++) {
        char str[MAX_STR_LEN + 1];
        sprintf_s(str, MAX_STR_LEN + 1, "��� %d �������", i);
        Node* newNode = createNode(str);
        current->next = newNode;
        current = current->next;
    }

    // �������� ��� �������� ������
    printList(head);
    printf("\n");

    deleteSecondLast(&head);
    printList(head);
    printf("\n");

    insertBeforeK(&head, 5, "��� ����� �������");
    printList(head);

    #pragma endregion
    */
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
        }
        fclose(File);
        return 0;
    }
}

int countLinesWithSubstring(char* substring) {
    if (fopen_s(&File, "Details.txt", "r")) {
        printf("�� ������� ������� ����\n");
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

void printEveryLine() {
    if (fopen_s(&File, "Details.txt", "r")) {
        printf("�� ������� ������� ����\n");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), File)) {
        printf("%s", buffer);
    }
    fclose(File);
}

void getDetail(int n) {
    if (fopen_s(&File, "Details.txt", "r")) {
        printf("�� ������� ������� ����\n");
        exit(1);
    }

    char buffer[1024];
    int lineCount = 0;
    while (fgets(buffer, sizeof(buffer), File)) {
        lineCount++;
        if (lineCount == n) {
            printf("%s", buffer);
            break;
        }
    }
    fclose(File);
}

void changeValueInLine(int lineNumber, int newValue) {
    FILE* file;
    if (fopen_s(&file, "Details.txt", "r")) {
        printf("�� ������� ������� ����\n");
        exit(1);
    }

    // ������ ��� ������ ����� � ������
    char** lines = NULL;
    char buffer[1024];
    int lineCount = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        lines = (char**)realloc(lines, sizeof(char*) * (lineCount + 1));
        lines[lineCount] = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy_s(lines[lineCount], strlen(buffer) + 1, buffer);
        lineCount++;
    }

    // ��������� ����
    fclose(file);

    // �������� ������ ������
    if (lineNumber <= lineCount) {
        char* line = lines[lineNumber - 1];

        // ��������� ������ �� ��������� ��������
        char* token;
        char* context = NULL;
        token = strtok_s(line, " ", &context);
        int currentTokenPosition = 1;
        char newLine[1024] = { 0 };
        while (token != NULL) {
            if (currentTokenPosition == 3) {
                // ������ �������� �� �����
                char newValueString[32] = { 0 };
                sprintf_s(newValueString, sizeof(newValueString), "%d\n ", newValue);
                strcat_s(newLine, sizeof(newLine), newValueString);
                token = NULL;
                break;
            }
            else {
                strcat_s(newLine, sizeof(newLine), token);
                strcat_s(newLine, sizeof(newLine), " ");
            }
            token = strtok_s(NULL, " ", &context);
            currentTokenPosition++;
        }

        // �������� ������ ������ �� �����
        free(lines[lineNumber - 1]);
        lines[lineNumber - 1] = (char*)malloc(sizeof(char) * (strlen(newLine) + 1));
        strcpy_s(lines[lineNumber - 1], strlen(newLine) + 1, newLine);
    }

    // ��������� ���� �� ����������
    if (fopen_s(&file, "Details.txt", "w")) {
        printf("�� ������� ������� ����\n");
        exit(1);
    }

    // �������������� ��� ������ � ����
    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s", lines[i]);
        free(lines[i]);
    }
    free(lines);

    fclose(file);
}