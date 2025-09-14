#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // Для поддержки UTF-8 в консоли Windows

#define COUNT 1000 //последовательность символов

int main() {

    // Установка кодовой страницы вывода консоли на UTF-8 для корректного отображения кириллицы
    SetConsoleOutputCP(CP_UTF8);

    // Открытие файла для записи
    FILE *file = fopen("480v\\f.txt", "w");

    // Инициализация генератора случайных чисел
    srand((unsigned int)time(NULL));

    // Запись случайных чисел в файл
    for (int i = 0; i < COUNT; i++) {
        int number = rand() % 1000; // число от 0 до 999
        fprintf(file, "%d ", number);

        // Добавляем перенос строки каждые 10 чисел для лучшей читаемости
        if ((i + 1) % 10 == 0) {
            fprintf(file, "\n");
        }
    }

    // Закрытие файла
    fclose(file);

    printf("Создан файл '%s' с %d случайными числами.\n", COUNT);
    return 0;
}