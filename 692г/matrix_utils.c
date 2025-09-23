#include <stdio.h>
#include <stdlib.h>

// Подключаем свой заголовок, чтобы компилятор знал сигнатуры функций
#include "matrix_utils.h"

// Заполняет матрицу размером n x n, хранящуюся в одномерном массиве
void fill_matrix(int *matrix, int n) {
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf("%d", &matrix[i * n + j]); // Сохраняем в массив
        }
    }
}

// Находит максимальное значение в треугольной области:
// Условие (j >= n - i - 1 && j <= i) — это область ниже побочной диагонали и выше главной диагонали
// То есть треугольник в центре, ограниченный главной и побочной диагоналями
int max_in_trian_matrix(int *matrix, int n) {
    int max_value = matrix[0]; // Инициализируем первым элементом (важно, если все числа отрицательные!)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= n - i - 1 && j <= i) { // Проверка на вхождение в треугольную область
                if (matrix[i * n + j] > max_value) {
                    max_value = matrix[i * n + j];
                }
            }
        }
    }
    return max_value;
}
