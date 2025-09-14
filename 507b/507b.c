#include <stdio.h>   // Для работы с вводом/выводом (printf, fgets, fopen и т.д.)
#include <stdlib.h>  // Для atoi(), exit() и других функций
#include <string.h>  // Для работы со строками (strcpy, strcmp, strtok_s, strlen и т.д.)
#include <windows.h> // Для поддержки UTF-8 в консоли Windows

// Максимальное количество учеников, которое может хранить массив
#define MAX_STUDENTS 1000

// Максимальная длина строки, считываемой из файла
#define MAX_LINE 256

// Структура Student — описывает одного ученика
typedef struct {
    char surname[100];  // Фамилия
    char name[100];     // Имя
    int grade;          // Год обучения
    char letter;        // Буква класса
} Student;

// Главная функция программы
int main() {
    // Устанавливаем кодировку консоли на UTF-8, чтобы корректно отображать русские буквы
    SetConsoleOutputCP(CP_UTF8);

    // Открываем файл для чтения. Путь: "507b\\names"
    FILE *file_f = fopen("507b\\names", "r");


    // Массив структур Student — храним всех учеников
    Student students[MAX_STUDENTS];

    // Счётчик — сколько учеников уже прочитали
    int count = 0;

    // Буфер для чтения одной строки из файла
    char line[MAX_LINE];

    // Читаем файл построчно, пока:
    // - не кончится файл (fgets вернёт NULL)
    // - не заполним массив (count < MAX_STUDENTS)
    while (fgets(line, sizeof(line), file_f) && count < MAX_STUDENTS) {

        // Удаляем символ перевода строки '\n' в конце строки (если есть)
        // strcspn ищет позицию первого вхождения '\n' и заменяет его на '\0'
        line[strcspn(line, "\n")] = '\0';+

        // context — это переменная, в которую strtok сохраняет информацию о текущей позиции в строке, чтобы продолжить разбор с того места, где остановил
        char *context;

        // Разбиваем строку на части с помощью strtok_s — это парсер строки по разделителям

        // Первая часть — имя (до первого пробела)
        char *name = strtok_s(line, " ", &context);

        // Вторая часть — фамилия (до запятой, после пробела)
        char *surname = strtok_s(NULL, ",", &context);

        // Третья часть — класс (после запятой и пробела, например "10А")
        char *class_str = strtok_s(NULL, " ", &context);


        // Парсим класс: из строки "10А" извлекаем:
        // - число 10 → atoi(class_str) (читает цифры до первого не-цифрового символа)
        int grade = atoi(class_str);

        // - последний символ — буква класса
        char letter = class_str[strlen(class_str) - 1];

        // Копируем данные в массив students
        strcpy(students[count].surname, surname);  // Копируем фамилию
        strcpy(students[count].name, name);        // Копируем имя
        students[count].grade = grade;             // Записываем год обучения
        students[count].letter = letter;           // Записываем букву класса

        // Увеличиваем счётчик учеников
        count++;
    }

    // Закрываем файл — больше не нужен
    fclose(file_f);

    // Теперь ищем однофамильцев в параллельных классах
    // (одинаковая фамилия + одинаковый год + разные буквы)

    int found = 0; // Флаг: найдена хотя бы одна пара?

    // Двойной цикл: сравниваем каждого ученика со всеми последующими
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {

            // Проверяем 3 условия:
            // 1. Фамилии совпадают
            //strcmp - сравнение строк
            if (strcmp(students[i].surname, students[j].surname) == 0 &&
                // 2. Год обучения одинаковый
                students[i].grade == students[j].grade &&
                // 3. Буквы классов разные → значит, параллельные классы
                students[i].letter != students[j].letter) {

                // Если это первая найденная пара — выводим заголовок
                if (!found) {
                    printf("Однофамильцы в параллельных классах:\n");
                    found = 1; // Устанавливаем флаг
                }

                // Выводим информацию о паре однофамильцев
                printf("%s %s (%d%c) и %s %s (%d%c)\n",
                       students[i].name, students[i].surname, students[i].grade, students[i].letter,
                       students[j].name, students[j].surname, students[j].grade, students[j].letter);
            }
        }
    }

    // Если ни одной пары не найдено — выводим сообщение
    if (!found) {
        printf("Однофамильцев в параллельных классах не найдено.\n");
    }

    // Успешное завершение программы
    return 0;
}