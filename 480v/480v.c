// main.c

#include <stdio.h>
#include <windows.h>
#include "file_module.h"

int main() {
    // Установка UTF-8 для консоли (для сообщений, если понадобятся)
    SetConsoleOutputCP(CP_UTF8);

    const char* input_file = "f.txt";

    const char* output_file = "g.txt";
    
    int result = file_modules(input_file, output_file);

    return 0;
}