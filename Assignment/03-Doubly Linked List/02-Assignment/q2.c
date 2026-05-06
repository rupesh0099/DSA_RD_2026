// write a c program to Create Doubly linked list and display it in reverse order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct singly
{
    int Number;
    char Name[10];
    struct singly *next;
    struct singly *prev;
} DNode;
DNode *create();
void printReverse(DNode *);
void freeList(DNode *);
int main()
{
    DNode *head = NULL;
    DNode *tail = NULL;
    tail = create();
    printReverse(tail);
    freeList(tail);
    return 0;
}

DNode *create()
{
    DNode *head = NULL, *newNode, *tail = NULL;
    int choice;
    do
    {
        newNode = (DNode *)malloc(sizeof(DNode));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return head;
        }
        printf("\nEnter the number:\n");
        scanf("%d", &newNode->Number);
        getchar();
        printf("Enter name: ");
        fgets(newNode->Name, sizeof(newNode->Name), stdin);
        newNode->Name[strcspn(newNode->Name, "\n")] = '\0';
        newNode->next = NULL;
        newNode->prev = tail;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
        printf("do you want to enter more records?(1 for yes/ 0 for NO):");
        scanf("%d", &choice);
    } while (choice == 1);
    return tail;
}

void printReverse(DNode *tail)
{
    if (!tail)
    {
        printf("\n\tList is Empty.");
        return;
    }
    printf("Doubly Linked List in Reverse:");
    for (; tail != NULL; tail = tail->prev)
    {
        printf("\n\t Number:%d,Name:%s", tail->Number, tail->Name);
    }
}

void freeList(DNode *tail)
{
    DNode *temp;
    while (tail)
    {
        temp = tail;
        tail = tail->prev;
        free(temp);
    }
}
