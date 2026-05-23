//write a c program to create two doubly linked lists, sort them individually and then merge the two sorted lists


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
DNode *sort(DNode *);
DNode*merge(DNode*,DNode*);
void display(DNode *);
void freeList(DNode *);
int main()
{
    DNode *head1 = NULL;
    DNode *head2 = NULL;
    printf("\ncreate 1st doubly linked list:\n ");
    head1 = create();
    printf("\ncreate 2nd doubly linked list:\n ");
    head2 = create();
    head1=merge(head1,head2);
    head1=sort(head1);
    display(head1);
    freeList(head1);
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
        printf("\nEnter the Number and Name:\n");
        scanf("%d %[^\n]s", &newNode->Number,newNode->Name);
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
DNode *sort(DNode *head)
{
    DNode *q = NULL, *p = NULL;
    char ch[20];
    for (p = head; p != NULL; p = p->next)
    {
        for (q = p; q != NULL; q = q->next)
        {
            if (p->Number > q->Number)
            {
                int temp = q->Number;
                q->Number = p->Number;
                p->Number = temp;
                strcpy(ch, q->Name);
                strcpy(q->Name, p->Name);
                strcpy(p->Name, ch);
            }
        }
    }

    return head;
}

DNode*merge(DNode*head1,DNode*head2){
    DNode* temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    head2->prev=temp;

    return head1;
}

void display(DNode *head)
{
    while (head != NULL)
    {
        printf("Number: %d Name: %s\n", head->Number, head->Name);
        head = head->next;
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