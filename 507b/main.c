// main.c
#include "student.h"
#include <windows.h>

int main() {
    // Устанавливаем кодировку консоли на UTF-8 для корректного отображения русских букв
    SetConsoleOutputCP(CP_UTF8);

    // Объявляем массив студентов для хранения данных
    Student students[MAX_STUDENTS];

    // Загружаем данные об учениках из файла "507b\\names" в массив students, возвращается количество загруженных
    int count = load_students("507b\\names", students);

    // Ищем и выводим пары однофамильцев, обучающихся в параллельных классах (один год, разные буквы)
    find_classmates_in_parallel_classes(students, count);

    // Завершаем программу с кодом успеха
    return 0;
}