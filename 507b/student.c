#include "student.h"
#include <stdio.h>
#include <string.h>

void find_classmates_in_parallel_classes_no_array(const char* filename) {
    FILE* file1 = fopen(filename, "r");

    char name1[MAX_NAME], surname1[MAX_NAME];
    int grade1;
    char letter1;
    int found = 0;

    // читаем первого ученика
    //%[^,] - чтение фамилии до запятой
    while (fscanf(file1, "%s %[^,],%d%c", name1, surname1, &grade1, &letter1) == 4) {
        FILE* file2 = fopen(filename, "r");
        if (!file2) {
            fclose(file1);
            return;
        }

        char name2[MAX_NAME], surname2[MAX_NAME];
        int grade2;
        char letter2;

        // Пропускаем учеников до текущей позиции
        int skip = 0;
        while (skip == 0 &&
               fscanf(file2, "%s %[^,],%d%c", name2, surname2, &grade2, &letter2) == 4) {
            if (strcmp(name2, name1) == 0 &&
                strcmp(surname2, surname1) == 0 &&
                grade2 == grade1 &&
                letter2 == letter1) {
                skip = 1; // нашли начало "после текущего"
                break;
            }
        }

        // читаем всех последующих ученикрв
        //%[^,] - чтение фамилии до запятой
        while (fscanf(file2, "%s %[^,],%d%c", name2, surname2, &grade2, &letter2) == 4) {
            if (strcmp(surname1, surname2) == 0 &&
                grade1 == grade2 &&
                letter1 != letter2) {

                if (!found) {
                    printf("Однофамильцы в параллельных классах:\n");
                    found = 1;
                }
                printf("%s %s (%d%c) и %s %s (%d%c)\n",
                       name1, surname1, grade1, letter1,
                       name2, surname2, grade2, letter2);
            }
        }
        fclose(file2);
    }

    if (!found) {
        printf("Однофамильцев в параллельных классах не найдено.\n");
    }

    fclose(file1);
}
