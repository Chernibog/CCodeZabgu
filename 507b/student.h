// student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Максимальное количество учеников
#define MAX_STUDENTS 1000
// Максимальная длина строки
#define MAX_LINE 256

// Структура ученика
typedef struct {
    char surname[100];  // Фамилия
    char name[100];     // Имя
    int grade;          // Год обучения
    char letter;        // Буква класса
} Student;

// Прототипы функций
int load_students(const char *filename, Student students[]);
void find_classmates_in_parallel_classes(const Student students[], int count);

#endif // STUDENT_H