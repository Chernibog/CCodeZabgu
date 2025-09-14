// EuAlg.c - Реализация алгоритма Евклида для нахождения НОД

#include "EuAlg.h"
#include <stdlib.h> // Для abs()

int gcd(int a, int b) {
    // Берём модули входных чисел, чтобы работать только с положительными
    a = abs(a);
    b = abs(b);

    // Алгоритм Евклида (рекурсивная реализация)
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}