// write a c program to Create a doubly linked list and Insert the Node at given position.
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
DNode *InsertAtposition(DNode *);
void printList(DNode *);
void freeList(DNode *);
int main()
{
    DNode *head = NULL;
    head = create();
    head = InsertAtposition(head);
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

DNode *InsertAtposition(DNode *head)
{
    int pos;
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    printf("Enter the Position to inserting New Node:\n");
    scanf("%d", &pos);
    if (!newNode)
    {
        printf("\n\tMemory allocation failed!");
        return head;
    }
    printf("\n\tEnter the Number and Name:");
    scanf("%d %s", &newNode->Number, newNode->Name);
    newNode->next = newNode->prev = NULL;
    printf("Inserting At posiition.....");
    if (pos <= 1 || !head)
    {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        return newNode;
    }
    DNode *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; temp = temp->next, i++)
        ;
    if (temp != NULL)
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
    else
    {
        printf("invalid position....!");
        return head;
    }
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
