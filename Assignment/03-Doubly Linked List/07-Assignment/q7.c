// write a c program to Create a doubly linked list and Delete a node at given position.
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
DNode *deleteAtposition(DNode *);
void printList(DNode *);
void freeList(DNode *);
int main()
{
    DNode *head = NULL;
    head = create();
    head = deleteAtposition(head);
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

DNode *deleteAtposition(DNode *head)
{
    if (!head)
    {
        printf("list is empty");
        return NULL;
    }

    int pos;
    printf("Enter the Position to deleting Node:\n");
    scanf("%d", &pos);

    DNode *temp = head;
    for (int i = 1; temp && i < pos; i++)
        temp = temp->next;

    if (!temp)
    {
        printf("\n\tInvalid position!");
        return head;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    if (temp == head)
        head = temp->next;
    free(temp);

    printf("\n\tNode at position %d deleted at successfully", pos);
    return head;
}

void printList(DNode *head)
{
    if (!head)
    {
        printf("\n\t List is empty");
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