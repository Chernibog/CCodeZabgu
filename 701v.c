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

    //присвоение значение n строкам и колонкам
    int rows = n;
    int cols = n;

    // Выделяем память под матрицу и векторы
    int *matrix = (int *)malloc(rows * cols * sizeof(int));
    int *vector = (int *)malloc(n * sizeof(int));
    int *vector_answer = (int *)calloc(n, sizeof(int));

//  --- иное обьявление динамической матрицы ---
//    int **matr = malloc(n * sizeof(int*));		// выделена память под n указателей на массивы
//    for (size_t i = 0; i<n; i++)	// перебор номеров строк
//        matr[i] = malloc(m * sizeof(int));


    // Вводим элементы матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Введите элемент матрицы [%d][%d]: ", i, j);
            scanf("%d", &matrix[i * cols + j]);
        }
    }

    // Вводим элементы вектора
    for (int i = 0; i < n; i++) {
        printf("Введите элемент вектора [%d]: ", i);
        scanf("%d", &vector[i]);
    }

    // Вычитаем единичную матрицу
    for (int i = 0; i < rows; i++) {
        matrix[i * cols + i] -= 1;
    }

    // Умножение матрицы (A - E) на вектор b
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            vector_answer[i] += matrix[i * cols + j] * vector[j];
        }
    }

    // Вывод результата
    printf("Результат (A - E) * b:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector_answer[i]);
    }
    printf("\n");

    // Освобождаем память
    free(matrix);
    free(vector);
    free(vector_answer);

    return 0;
}