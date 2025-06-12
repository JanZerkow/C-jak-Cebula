#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

struct element

{
    int data;
    struct element
        *next;
};

struct element *createlement(int value)
{
    struct element *newelement = malloc(sizeof(struct element));

    newelement->data = value;
    newelement->next = NULL;
    return newelement;
}
void wstawNaStart(struct element **head, int value)
{
    struct element*newelement = createlement(value);
    newelement->next = *head;
    *head = newelement;
}
void wstawNaKoniec(struct element**head, int value)
{
    struct element
        *newelement = createlement(value);
    if (*head == NULL)
    {
        *head = newelement;
        return;
    }
    struct element
        *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newelement;
}
void delete_element(struct element
                        **head,
                    int value)
{
    struct element
        *temp = *head,
        *prev = NULL;

    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
}
void print_list(struct element
                    *head)
{
    struct element
        *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
void wypisz_pary(struct element
                     *p)
{
    while (p != NULL)
    {
        if (p->data % 2 == 0)
        {
            printf("%d ", p->data);
        }
        p = p->next;
    }
}
void usun_parzyste(struct element
                       **head)
{

    struct element
        *wsk = *head;
    struct element
        *next_element;
    while (wsk != NULL)
    {
        next_element = wsk->next;
        if (wsk->data % 2 == 0)
        {
            delete_element(head, wsk->data);
        }
        wsk = next_element;
    }
}
void freeList(struct element
                  *head)

{
    struct element
        *current = head;
    while (current != NULL)
    {
        struct element
            *temp = current;
        current = current->next;
        free(temp);
    }
}
float mean(struct element *head)
{
    float suma = 0;
    float count = 0;
    while (head != NULL)
    {
        suma += head->data;
        count++;
        head = head->next;
    }
    return suma / count;
}

int main()
{
    struct element
        *head = NULL;
    wstawNaStart(&head, 10);
    wstawNaKoniec(&head, 20);
    wstawNaStart(&head, 5);
    wstawNaKoniec(&head, 30);
    float srednia = mean(head);
    printf("%.2f", srednia);
}