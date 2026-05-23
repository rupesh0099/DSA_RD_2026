// write a c program to Delete duplicate values(nodes) in doubly linked list.
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
DNode *deleteDuplicate(DNode *);
void printList(DNode *);
void freeList(DNode *);
int main()
{
    DNode *head = NULL;
    head = create();
    head = deleteDuplicate(head);
    printList(head);
    freeList(head);
    return 0;
}
DNode *create()
{
    DNode *head = NULL, *newNode, *lastNode = NULL;
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
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            lastNode->next = newNode;
            newNode->prev = lastNode;
        }
        lastNode = newNode;
        printf("do you want to enter more records?(1 for yes/ 0 for NO):");
        scanf("%d", &choice);
    } while (choice == 1);
    return head;
}

DNode *deleteDuplicate(DNode *head)
{
    DNode *temp = head, *p = temp->next, *freetemp = NULL;
    for (; temp != NULL; temp = temp->next)
    {
        for (p = temp->next; p != NULL; p = p->next)
        {
            if (temp->Number == p->Number)
            {
                if (p->prev)
                    p->prev->next = p->next;
                if (p->next)
                    p->next->prev = p->prev;
                printf("\nduplicate %d deleted successfully\n", p->Number);
                freetemp = p;
                free(freetemp);
            }
        }
    }

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
        printf("\n\tNumber: %d , Name : %s", head->Number, head->Name);
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
