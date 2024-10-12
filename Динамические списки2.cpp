#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <clocale>

struct node
{
    char inf[256];  
    struct node* next; 
};

struct node* head = NULL;

/* Функция создания элемента */
struct node* get_struct(void)
{
    struct node* p = NULL;
    char s[256];

    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) 
    {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");   
    scanf("%s", s);

    if (*s == 0)
    {
        printf("Запись не была произведена\n");
        free(p);
        return NULL;
    }

    strcpy(p->inf, s);
    p->next = NULL;

    return p;		
}

/* Функция добавления элемента в стек */
void push(void)
{
    struct node* p = get_struct();
    if (p == NULL)
        return;

    p->next = head;
    head = p;
}

void review(void)
{
    struct node* struc = head;
    if (head == NULL)
    {
        printf("Стек пуст\n");
        return;
    }
    while (struc)
    {
        printf("Имя - %s\n", struc->inf);
        struc = struc->next;
    }
}

/* Функция удаления элемента из стека */
void pop(void)
{
    if (head == NULL)
    {
        printf("Стек пуст\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
    printf("Элемент удален\n");
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int choice;
    while (1)
    {
        printf("\n1. Добавить элемент в стек \n2. Просмотреть стек\n3. Удалить элемент из стека\n4. Выход\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            review();
            break;
        case 3:
            pop();
            break;
        case 4:
            exit(0);
        default:
            printf("Неверный выбор.\n");
        }
    }
    return 0;
}
