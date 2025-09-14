#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Для поддержки UTF-8 в консоли Windows

// Подключаем модуль для работы с матрицами
#include "matrix_utils.h"

int main() {
    // Установка кодовой страницы вывода консоли на UTF-8 для корректного отображения кириллицы
    SetConsoleOutputCP(CP_UTF8);

    int n;

    // Запрашиваем у пользователя размерность матрицы
    printf("Введите размерность матрицы n: ");
    scanf("%d", &n);

    // Выделяем память под одномерный массив, который будет хранить элементы матрицы n x n
    int *matrix = (int *)malloc(n * n * sizeof(int));
    if (!matrix) {
        fprintf(stderr, "Ошибка выделения памяти!\n");
        return 1;
    }

    // Заполняем матрицу
    fill_matrix(matrix, n);

    // Находим и выводим максимальное значение в треугольной области
    printf("Максимальное значение: %d\n", max_in_trian_matrix(matrix, n));

    // Освобождаем выделенную память
    free(matrix);

    return 0;
}