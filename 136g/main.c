// main.c

#include "linked_list.h"

void push(Node** head, int value) {
    // выделение памяти под новый узел
    Node* newNode = (Node*)malloc(sizeof(Node));

    // присваиваеем новому узлу переданное значение
    newNode->data = value;

    // устанавливаем указатель next нового узла на текущую голову списка
    newNode->next = *head;

    // Обновляем голову списка, теперь она указывает на новый узел
    *head = newNode;
}
