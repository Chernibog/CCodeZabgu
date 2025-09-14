/*

Автор: Шумилко Н.Д. (4 вариант) (https://github.com/VetrovSV/OOP/blob/master/C/tasks.md)          <- ссылка на табличку с заданиями
                                  (https://bgu-chita.ru/zadachnik/Glava01/index01.htm#z269)        <- ссылка на задание (найти самому)

Задача 269г:
Даны натуральное число n, символы s1,...,sn. Группы символов, разделенные пробелами (одним или несколькими) и не содержащие пробелов внутри себя будем называть словами. Найти количество слов, у которых первый и последний символы совпадают между собой.
*/
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>    // Для isspace()

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char string[128];
    boolean in_word = 0;
    int count = 0;
    int start_word = 0;

    printf("Введите строку (максимум 127 символов): ");
    fgets(string, 128, stdin);

    int len = strlen(string); // длина массива

    for (int i = 0; i <= len; i++) {
        // Проверяем на конец слова (пробел или конец строки)
        if (i == len || isspace(string[i])) { //isspace - обнаружение пробелов
            if (in_word) {
                // Проверяем совпадение первого и последнего символа
                if (string[start_word] == string[i-1]) {
                    count++;
                }
                in_word = 0;
            }
        }
        else {
            if (!in_word) {
                in_word = 1;
                start_word = i;
            }
        }
    }

    printf("Количество слов, где первый и последний символ совпадают: %d\n", count);
    return 0;
}