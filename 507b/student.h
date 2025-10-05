// student.h
#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 1000
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    char surname[MAX_NAME];
    int grade;      // номер класса (например, 10)
    char letter;    // буква класса (например, 'А')
} Student;

int load_students(const char *filename, Student students[]);
void find_classmates_in_parallel_classes(const Student students[], int count);

#endif
