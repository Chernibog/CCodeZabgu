// linked_list.c

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include "linked_list.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n, number_list;
    long long summ = 1;

    Node* head = NULL;

    printf("Введите кол-во чисел: ");
    scanf("%d", &n);

    //заполнение списка
    for (int i = 0; i < n; i++) {
        printf("Введите число: ");
        scanf("%d", &number_list);
        push(&head, number_list);
    }
    //current - "временный указатель, чтобы проходить по списку"
    Node* current = head;
    while (current != NULL) {
        summ *= abs(current->data);
        current = current->next;
    }

    printf("%lld\n", summ);
    return 0;

}
