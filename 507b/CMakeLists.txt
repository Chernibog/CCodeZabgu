cmake_minimum_required(VERSION 3.25)
project(school)

set(CMAKE_C_STANDARD 11)

# Добавляем исполняемый файл, собираем из всех .c файлов
add_executable(school
        main.c
        student.c
        student.h)