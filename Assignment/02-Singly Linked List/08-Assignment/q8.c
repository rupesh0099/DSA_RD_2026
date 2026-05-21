// write a c program to Create a Singly linked list and Insert a node in the given position.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singly
{
    int Number;
    char Name[20];
    struct singly *next;
} node;

node *create();
node *insert(node *);
void display(node *);
void freeList(node *);

int main()
{
    node *head = NULL;

    head = create();
    head = insert(head);
    display(head);
    freeList(head);

    return 0;
}

node *create()
{
    node *head = NULL, *newNode, *lastNode = NULL;
    int choice;

    do
    {
        newNode = (node *)malloc(sizeof(node));

        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return head;
        }

        printf("\nEnter Number: ");
        scanf("%d", &newNode->Number);

        getchar();

        printf("Enter Name: ");
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
        }

        lastNode = newNode;

        printf("Do you want to enter more records? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return head;
}

node *insert(node *head)
{
    node *nw, *temp;
    int pos, i;

    printf("\nEnter the position to insert: ");
    scanf("%d", &pos);

    nw = (node *)malloc(sizeof(node));

    if (nw == NULL)
    {
        printf("Memory allocation failed!\n");
        return head;
    }

    printf("Enter Number: ");
    scanf("%d", &nw->Number);

    getchar();

    printf("Enter Name: ");
    fgets(nw->Name, sizeof(nw->Name), stdin);
    nw->Name[strcspn(nw->Name, "\n")] = '\0';

    nw->next = NULL;

    if (pos <= 1 || head == NULL)
    {
        nw->next = head;
        return nw;
    }

    temp = head;

    for (i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        nw->next = temp->next;
        temp->next = nw;
    }
    else
    {
        printf("\nInvalid Position!\n");
        free(nw);
    }

    return head;
}

void display(node *head)
{

    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\n------ Linked List ------\n");

    node *temp = head;

    while (temp != NULL)
    {
        printf("Number: %d, Name: %s \n",
               temp->Number,
               temp->Name);

        temp = temp->next;
    }
}

void freeList(node *head)
{
    node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}