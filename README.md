# CP_LRs
Лабораторные работы по Системному программированию
ЛР4
Строки, используемые в коде
char str1[] = "Когда я думаю о мышлении, я думаю о сознании. Ведь это одно и то же";
const char substr2[] = " подстроки 2"; char* str2 = (char*)calloc(100, 1); const char str11[] = "Строка 1 для";
char str3[80] = "Текст, чтобы занять, а не чтобы понять. Арбуз, ананас, мандарин, аксиома.";
char str4[80] = "Текст, чтобы занять, а не чтобы понять. Арбуз, ананас, мандарин, аксиома.";
ЛР5
    printf("Самая дорогая деталь: %s, ее цена: %d\n\n", detailName, expensiveDetail);
		printf("Введите данные о человеке %d\n", i);
		printf("Имя: ");
		scanf_s("%9s", persons[i].name, (unsigned)_countof(persons[i].name));
		printf("Фамилия: ");
		scanf_s("%9s", persons[i].surname, (unsigned)_countof(persons[i].surname));
		printf("Отчество: ");
		scanf_s("%9s", persons[i].lastname, (unsigned)_countof(persons[i].lastname));
		printf("Возраст: ");
		scanf_s("%d", &persons[i].age);
  
