#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Для поддержки UTF-8 в консоли Windows

typedef struct Node { //создание типа, чтобы не писать по множеству раз
    int data;
    struct Node* next;
} Node;


// Функция для добавления нового узла в начало связного списка
// Параметры:
//   Node** head — указатель на указатель на голову списка (для изменения самой головы)
//   int value — значение, которое нужно поместить в новый узел
void push(Node** head, int value) {
    // Выделяем память под новый узел
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Присваиваем новому узлу переданное значение
    newNode->data = value;

    // Устанавливаем указатель next нового узла на текущую голову списка
    newNode->next = *head;

    // Обновляем голову списка, теперь она указывает на новый узел
    *head = newNode;
}




int main(){

    SetConsoleOutputCP(CP_UTF8);

    int n,number_list,summ=1;

    Node* head = NULL; //обьявление начала списка


    printf("Введите кол-во чисел: ");
    scanf("%d", &n);

    for (int i; i < n; i++) {
        printf("Введите число: ");
        scanf("%d", &number_list);
        push(&head, number_list); //выделение памяти для нового элемента списка
    }


    while (head != NULL) {
        summ*=abs(head->data);
        head = head->next;             // Переходим к следующему узлу
    }
    printf("%d",summ);
    return 0;
}