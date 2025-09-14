#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

// Объявление функций для работы с матрицей

// Заполняет матрицу размером n x n, хранящуюся в одномерном массиве
void fill_matrix(int *matrix, int n);

// Находит максимальное значение в треугольной области матрицы
// (ограниченной главной и побочной диагоналями)
int max_in_trian_matrix(int *matrix, int n);

#endif // MATRIX_UTILS_H