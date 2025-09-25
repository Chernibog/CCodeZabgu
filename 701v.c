/*

Автор: Шумилко Н.Д. (4 вариант) (https://github.com/VetrovSV/OOP/blob/master/C/tasks.md)          <- ссылка на табличку с заданиями
                                  (https://bgu-chita.ru/zadachnik/Glava01/index01.htm#z701)        <- ссылка на задание

Задача 701в:
Даны квадратная матрица А порядка n и вектор b c n элементами. (A - E)b, где Е - единичная матрица порядка n.

 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // Для SetConsoleOutputCP(CP_UTF8)

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n;
    printf("Введите размер матрицы n: ");
    scanf("%d", &n);

    // Выделяем память под матрицу как массив указателей
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Выделяем память под векторы
    int *vector = (int *)malloc(n * sizeof(int));
    int *vector_answer = (int *)calloc(n, sizeof(int));

    // Вводим элементы матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Введите элемент матрицы [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Вводим элементы вектора
    for (int i = 0; i < n; i++) {
        printf("Введите элемент вектора [%d]: ", i);
        scanf("%d", &vector[i]);
    }

    // Вычитаем единичную матрицу: A = A - E
    for (int i = 0; i < n; i++) {
        matrix[i][i] -= 1;
    }

    // Умножение матрицы (A - E) на вектор b
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector_answer[i] += matrix[i][j] * vector[j];
        }
    }

    // Вывод результата
    printf("Результат (A - E) * b:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector_answer[i]);
    }
    printf("\n");

    // Освобождаем память
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(vector_answer);

    return 0;
}
