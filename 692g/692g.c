// main.c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_utils.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n;
    printf("Введите размерность матрицы n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Некорректный размер матрицы.\n");
        return 1;
    }

    // Выделяем память под матрицу как массив указателей
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Заполняем матрицу
    fill_matrix(matrix, n);

    // Находим и выводим максимальное значение в треугольной области
    printf("Максимальное значение: %d\n", max_in_trian_matrix(matrix, n));

    // Освобождаем память
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
