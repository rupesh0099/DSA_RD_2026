// write a c program to Create a doubly linked list and Insert the Node at the end.
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
DNode *InsertAtlast(DNode *);
void printList(DNode *);
void freeList(DNode *);
int main()
{
    DNode *head = NULL;
    head = create();
    head = InsertAtlast(head);
    printList(head);
    freeList(head);
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
    return head;
}

DNode *InsertAtlast(DNode *head)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    if (!newNode)
    {
        printf("\n\tMemory allocation failed!");
        return head;
    }
    printf("\n\tEnter the Number and Name:");
    scanf("%d %s", &newNode->Number, newNode->Name);
    newNode->next = newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    printf("Inserting At last posiition.....");
    DNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printList(DNode *head)
{
    if (!head)
    {
        printf("\n\t List is empty");
        return;
    }
    printf("\n\tDoubly Linked LIst");
    for (; head != NULL; head = head->next)
    {
        printf("\n\tNumber: %d,Name: %s", head->Number, head->Name);
    }
}

void freeList(DNode *head)
{
    DNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
