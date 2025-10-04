// student.c
// Функция загружает данные об учениках из текстового файла по указанному пути
// Возвращает количество успешно загруженных студентов
#include "student.h"
#include <windows.h>
#include <stdio.h>


int load_students(const char *filename, Student students[]) {
    // открываем файл для чтения - r - read
    FILE *file = fopen(filename, "r");

    // счетчик успешно загруженных студентов
    int count = 0;
    // Буфер для хранения одной строки из файла
    char line[MAX_LINE];

    // читаем файл построчно, пока не достигнем конца или лимита массива
    while (fgets(line, sizeof(line), file) && count < MAX_STUDENTS) {
        // Удаляем символ новой строки в конце строки (strcspn)
        line[strcspn(line, "\n")] = '\0';

        //  context - переменная, чтобы разбить строку на части
        char *context;

        //strtok - разбитие строки на части
        // Извлекаем имя (первая часть до пробела)
        char *name = strtok_s(line, " ", &context);
        // Извлекаем фамилию (часть после пробела до запятой)
        char *surname = strtok_s(NULL, ",", &context);
        // Извлекаем класс (например, "10А" — после запятой)
        char *class_str = strtok_s(NULL, " ", &context);

        // Преобразуем начало строки class_str в число — это номер класса (год обучения)
        int grade = atoi(class_str);
        // Последний символ строки class_str — это буква класса
        char letter = class_str[strlen(class_str) - 1];

        // Копируем извлечённые данные в структуру студента
        strcpy(students[count].surname, surname);  // Фамилия
        strcpy(students[count].name, name);        // Имя
        students[count].grade = grade;             // Год обучения
        students[count].letter = letter;           // Буква класса

        // Увеличиваем счётчик загруженных студентов
        count++;
    }

    // Закрываем файл после завершения чтения
    fclose(file);
    // Возвращаем общее количество загруженных студентов
    return count;
}

// Функция ищет и выводит пары студентов с одинаковыми фамилиями,
// обучающихся в одном классе по году, но в разных группах (разные буквы)
void find_classmates_in_parallel_classes(const Student students[], int count) {
    // Флаг: найдена ли хотя бы одна пара
    int found = 0;

    // Перебираем всех студентов
    for (int i = 0; i < count; i++) {
        // Сравниваем текущего студента со всеми последующими
        for (int j = i + 1; j < count; j++) {
            
            // проверяем с помощью strcmp (сравнение строк) три условия:
            // 1. одинаковая фамилия
            // 2. оинаковый год обучения
            // 3. разная буква класса (параллельные классы)
            if (strcmp(students[i].surname, students[j].surname) == 0 &&
                students[i].grade == students[j].grade &&
                students[i].letter != students[j].letter) {

                // если первая пара найдена — выводим заголовок
                if (!found) {
                    printf("Однофамильцы в параллельных классах:\n");
                    found = 1;
                }

                // Вывод информации о двух однофамильцах
                printf("%s %s (%d%c) и %s %s (%d%c)\n",
                       students[i].name, students[i].surname, students[i].grade, students[i].letter,
                       students[j].name, students[j].surname, students[j].grade, students[j].letter);
            }
        }
    }

    // Если ни одной пары не найдено, сообщаем об этом
    if (!found) {
        printf("Однофамильцев в параллельных классах не найдено.\n");
    }

}


