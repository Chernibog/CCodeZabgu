
#include <stdio.h>

// Функция читает числа из input_path, фильтрует их и записывает в output_path
// Условие: число делится на 3 и НЕ делится на 7
int file_modules(const char* input_path, const char* output_path) {
    FILE *file_f = fopen(input_path, "r");
    
    FILE *file_g = fopen(output_path, "w");

    int number;
    //fscanf - возвращает 1, если число прочитанно, если нет или конец файла, то 0
    while (fscanf(file_f, "%d", &number) == 1) {
        if (number % 3 == 0 && number % 7 != 0) {
            fprintf(file_g, "%d\n", number);
        }
    }

    fclose(file_g);
    fclose(file_f);
    return 0; 
}