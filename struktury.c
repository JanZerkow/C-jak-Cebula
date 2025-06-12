#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void wstawNaStart(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}
void wstawNaKoniec(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}
void wypisz_pary(struct Node *p)
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
void delete_node(struct Node **head, int value)
{
    struct Node *temp = *head, *prev = NULL;

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
void print_list(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
void usun_parzyste(struct Node **head)
{

    struct Node *wsk = *head;
    struct Node *next_node;
    while (wsk != NULL)
    {
        next_node = wsk->next;
        if (wsk->data % 2 == 0)
        {
            delete_node(head, wsk->data);
        }
        wsk = next_node;
    }
}
void freeList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}
int main()
{
    struct Node *head = NULL;
    wstawNaStart(&head, 10);
    wstawNaKoniec(&head, 20);
    wstawNaStart(&head, 5);
    wstawNaKoniec(&head, 30);
    usun_parzyste(&head);
    print_list(head);
}