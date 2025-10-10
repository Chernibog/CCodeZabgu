// linked_list.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

// обьявление структуры узла
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// обьявление функции добавления элемента в начало списка
void push(Node** head, int value);

#endif // LINKED_LIST_H