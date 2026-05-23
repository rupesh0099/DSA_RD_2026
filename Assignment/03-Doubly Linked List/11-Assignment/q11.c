/*"write a c program to Create Menu Driven for doubly linked list which consist following functions:-
-create(),
- Insert(),
- Delete(),
- Display(),
- Reverse()."*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct singlyLinked
{
    int Number;
    char Name[21];
    struct singlyLinked *nxt;
    struct singlyLinked *prev;
} DNode;

DNode *create();
void reverse(DNode *);
DNode *deleteAtPosition(DNode *);
DNode *insertAtPosition(DNode *);
void display(DNode *);
void freeList(DNode *);

int main()
{
    DNode *head = NULL;
    int ch = -1;
    while (1)
    {
        printf("\n 1.Create \n 2.Insert \n 3.Delete \n 4.Reverse \n 5.Print \n 6.Exit \n");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = create();
            break;

        case 2:
            head = insertAtPosition(head);
            break;

        case 3:
            head = deleteAtPosition(head);
            break;

        case 4:
            reverse(head);
            break;

        case 5:
            display(head);
            break;

        case 6:
            freeList(head);
            printf("\nExiting..........");
            exit(0);

        default:
            printf("\nEnter valid Option");
            break;
        }
    }
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
        newNode->nxt = NULL;
        newNode->prev = tail;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            tail->nxt = newNode;
        }
        tail = newNode;
        printf("do you want to enter more records?(1 for yes/ 0 for NO):");
        scanf("%d", &choice);
    } while (choice == 1);
    return head;
}

DNode *insertAtPosition(DNode *head)
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
    newNode->nxt = newNode->prev = NULL;
    printf("Inserting At posiition.....");
    if (pos <= 1 || !head)
    {
        newNode->nxt = head;
        if (head)
            head->prev = newNode;
        return newNode;
    }
    DNode *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; temp = temp->nxt, i++);
    
    if (temp != NULL)
    {
        newNode->nxt = temp->nxt;
        newNode->prev = temp;
        if (temp->nxt)
            temp->nxt->prev = newNode;
        temp->nxt = newNode;
    }
    else
    {
        printf("invalid position....!");
        return head;
    }
    return head;
}

DNode *deleteAtPosition(DNode *head)
{
    int pos;
    printf("Enter the Position to deleting Node:\n");
    scanf("%d", &pos);

    if (!head)
    {
        printf("list is empty");
        return head;
    }
    DNode *temp = head;
    for (int i = 1; temp->nxt && i < pos; i++)
        temp = temp->nxt;

    if (!temp)
    {
        printf("\n\tInvalid position!");
        return head;
    }

    if (temp->prev)
        temp->prev->nxt = temp->nxt;
    if (temp->nxt)
        temp->nxt->prev = temp->prev;

    if (temp == head)
        head = temp->nxt;
    free(temp);

    printf("\n\tNode at position %d deleted at successfully", pos);
    return head;
}

void reverse(DNode *head)
{
    if (!head)
    {
        printf("\n\tList is Empty.");
        return;
    }
    for (; head->nxt != NULL; head = head->nxt);

    printf("Doubly Linked List in Reverse:");
    for (; head != NULL; head = head->prev)
    {
        printf("\n\t Number:%d,Name:%s", head->Number, head->Name);
    }
}

void display(DNode *head)
{
    while (head != NULL)
    {
        printf(" %d  %s ", head->Number, head->Name);
        head = head->nxt;
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