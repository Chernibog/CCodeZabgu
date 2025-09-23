//https://ivtipm.github.io/Programming/Glava12/index12.htm
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "EuAlg.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int x, y;

    printf("Введите два целых числа: ");
    scanf("%d %d", &x, &y);

    if (x == 0 && y == 0) {
        printf("Ошибка: НОД(0, 0) не определён.\n");
        return 1;
    }

    printf("НОД(%d, %d) = %d\n", abs(x), abs(y), gcd(x, y));

    return 0;
}
