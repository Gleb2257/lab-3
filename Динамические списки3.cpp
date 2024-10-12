#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <clocale>

// Определение структуры узла
struct node
{
    char inf[256];  
    struct node* next;
};

// Указатели на начало и конец очереди
struct node* head = NULL, * last = NULL;

struct node* get_struct(void)
{
    struct node* p = NULL;
    char s[256];

    if ((p = (node*)malloc(sizeof(struct node))) == NULL)  
    {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");  
    scanf("%s", s);
    if (*s == 0)
    {
        printf("Запись не была произведена\n");
        return NULL;
    }
    strcpy(p->inf, s);

    p->next = NULL;

    return p;
}

/* Добавление элемента в конец очереди */
void enqueue(void)
{
    struct node* p = get_struct(); // создаем новый элемент
    if (head == NULL && p != NULL) 
    {
        head = p;
        last = p;
    }
    else if (head != NULL && p != NULL) 
    {
        last->next = p;
        last = p;
    }
    return;
}

/* Удаление элемента из начала очереди */
void dequeue(void)
{
    if (head == NULL)
    {
        printf("Очередь пуста\n");
        return;
    }

    struct node* temp = head; // временный указатель для удаления элемента
    printf("Удаление элемента: %s\n", head->inf);

    head = head->next; 
    free(temp); 

    if (head == NULL) 
    {
        last = NULL; 
    }
}

/* Просмотр содержимого очереди */
void review(void)
{
    struct node* struc = head;
    if (head == NULL)
    {
        printf("Очередь пуста\n");
        return;
    }
    while (struc)
    {
        printf("Имя - %s\n", struc->inf);
        struc = struc->next;
    }
}

int main(void)

{
    setlocale(LC_ALL, "Russian");

    int choice;
    char name[256];

    while (1)
    {
        printf("\nМеню:\n");
        printf("1. Добавить элемент \n");
        printf("2. Удалить элемент \n");
        printf("3. Просмотр очереди \n");
        printf("4. Выйти\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            review();
            break;
        case 4:
            exit(0);
        default:
            printf("Неверный выбор\n");
        }
    }

    return 0;
}
