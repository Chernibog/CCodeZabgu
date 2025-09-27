#include <stdio.h>
#include <windows.h> // Для поддержки UTF-8 в консоли Windows

int main() {
    int number;

    // Установка кодовой страницы вывода консоли на UTF-8 для корректного отображения кириллицы
    SetConsoleOutputCP(CP_UTF8);

    FILE *file_f = fopen("480v\\f.txt", "r"); //FILE - тип данных
    FILE *file_g = fopen("480v\\g.txt", "w");

//поиск компонентов, которые делятся на 3 и не делятся на 7
//использует возвращаемое значение функции fscanf, чтобы определить, успешно ли было прочитано значение из файла.
    while (fscanf(file_f, "%d", &number) == 1) {
        if(number % 3==0 && number % 7 > 0) {
            fprintf(file_g,"%d\n",number);

        }
    }

    fclose(file_f); // Закрытие файла
    return 0;
}
