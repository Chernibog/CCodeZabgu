void find_classmates_in_parallel_classes_no_array(const char* filename) {
    FILE* file1 = fopen(filename, "r");
    if (!file1) {
        printf("Не удалось открыть файл %s\n", filename);
        return;
    }

    char name1[MAX_NAME], surname1[MAX_NAME];
    int grade1;
    char letter1;
    int found = 0;
    //чтение из файла1 данных
    while (fscanf(file1, "%s %[^,],%d%c", name1, surname1, &grade1, &letter1) == 4) {
        FILE* file2 = fopen(filename, "r");
        char name2[MAX_NAME], surname2[MAX_NAME];
        int grade2;
        char letter2;

        // прокручивание файла2 до текущего ученика из файла1
        while (fscanf(file2, "%s %[^,],%d%c", name2, surname2, &grade2, &letter2) == 4) {
            //strcmp - сравнение строк
            if (strcmp(name2, name1) == 0 &&
                strcmp(surname2, surname1) == 0 &&
                grade2 == grade1 &&
                letter2 == letter1) {
                break; // Нашли — останавливаемся, следующие записи будут "после"
            }
        }

        // теперь сравниваем со теми, кто идёт после текущго ученика
        while (fscanf(file2, "%s %[^,],%d%c", name2, surname2, &grade2, &letter2) == 4) {
            if (strcmp(surname1, surname2) == 0 &&   // одинаковая фамилия
                grade1 == grade2 &&                  // одинаковый класс (цифра)
                letter1 != letter2) {                // разные буквы → параллельные

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
