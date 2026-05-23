// write a c program to Create a doubly linked list, accept a key, and delete the node which contains the key element.
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
DNode *searchkey(DNode *);
void printList(DNode *);
void freeList(DNode *);
int main()
{
    DNode *head = NULL;
    head = create();
    head = searchkey(head);
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

DNode *searchkey(DNode *head)
{
    DNode *temp = NULL;
    int key, flag = 0;
    printf("Enter the key:\n");
    scanf("%d", &key);
    for (temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->Number == key)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nKey Found\n");
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;

        printf("\nkey %d deleted successfully\n", temp->Number);
        if (temp == head)
            head = temp->next;
        free(temp);
        temp = NULL;
    }
    else
    {
        printf("\nNot found");
    }
    return head;
}

void printList(DNode *head)
{
    if (head == NULL)
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
