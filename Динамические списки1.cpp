#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct node
{
    char inf[256];  
    int priority;   // приоритет объекта
    struct node* next; 
};

struct node* head = NULL, * last = NULL;

/* Функция создания элемента */
struct node* get_struct(void)
{
    struct node* p = NULL;
    char s[256];
    int pr;

    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) 
    {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");  
    scanf("%s", s);
    printf("Введите приоритет объекта (целое число): \n");
    scanf("%d", &pr);

    if (*s == 0)
    {
        printf("Запись не была произведена\n");
        free(p);
        return NULL;
    }

    strcpy(p->inf, s);
    p->priority = pr;
    p->next = NULL;

    return p;	
}

/* Функция добавления элемента в приоритетную очередь */
void spstore(void)
{
    struct node* p = get_struct();
    if (p == NULL)
        return;

    if (head == NULL)
    {
        head = p;
        return;
    }

    if (p->priority > head->priority)
    {
        p->next = head;
        head = p;
        return;
    }

    struct node* curr = head;
    while (curr->next != NULL && curr->next->priority >= p->priority)
    {
        curr = curr->next;
    }

    p->next = curr->next;
    curr->next = p;
}

/* Просмотр содержимого списка. */
void review(void)
{
    struct node* struc = head;
    if (head == NULL)
    {
        printf("Список пуст\n");
        return;
    }
    while (struc)
    {
        printf("Имя - %s, Приоритет - %d\n", struc->inf, struc->priority);
        struc = struc->next;
    }
}

/* Удаление элемента с наивысшим приоритетом */
void del_top_priority(void)
{
    if (head == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
    printf("Элемент с наивысшим приоритетом удален.\n");
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int choice;
    while (1)
    {
        printf("\n1. Добавить элемент\n2. Просмотреть очередь\n3. Удалить элемент с наивысшим приоритетом\n4. Выход\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            spstore();
            break;
        case 2:
            review();
            break;
        case 3:
            del_top_priority();
            break;
        case 4:
            exit(0);
        default:
            printf("Неверный выбор.\n");
        }
    }
    return 0;
}
