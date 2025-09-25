// matrix_utils.c
#include <stdio.h>
#include "matrix_utils.h"

void fill_matrix(int **matrix, int n) {
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int max_in_trian_matrix(int **matrix, int n) {
    // Инициализируем максимальное значение первым элементом треугольной области
    int max_value;
    int found = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= n - i - 1 && j <= i) {
                if (!found) {
                    max_value = matrix[i][j];
                    found = 1;
                } else if (matrix[i][j] > max_value) {
                    max_value = matrix[i][j];
                }
            }
        }
    }

    return found ? max_value : 0; // Если область пуста (n=0), возвращаем 0
}
