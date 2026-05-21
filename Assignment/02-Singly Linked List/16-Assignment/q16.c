/*write a c program to Create a Singly linked list and Display it in reverse order (Use Normal Function)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_|
O/P :
------
4 DD
3 CC
2 BB
1 AA*/
#include <stdio.h>
#include <stdlib.h>

typedef struct singly
{
    int no;
    char name[21];
    struct singly *nxt;
} sll;

sll *create(sll *);
void reverse(sll *);
void freeList(sll *);
int main()
{
    sll *head = NULL;
    head = create(head);
    reverse(head);
    return 0;
}

sll *create(sll *head)
{
    sll *nw, *lst = NULL;
    int ch;
    do
    {

        nw = (sll *)malloc(sizeof(sll));
        if (!nw)
        {
            printf("\nNew node not allocated");
            return head;
        }
        nw->nxt = NULL;
        printf("\nEnter Roll No: ");
        scanf("%d", &nw->no);
        printf("\nEnter name: ");
        scanf(" %s", nw->name);

        if (head == NULL)
        {
            head = nw;
        }
        else
        {
            lst = head;
            while (lst->nxt != NULL)
            {
                lst = lst->nxt;
            }
            lst->nxt = nw;
        }
        printf("\ndo you want to add new Node : (1/0)");
        scanf("%d", &ch);
    } while (ch != 0);
    return head;
}

void reverse(sll *head)
{
    if (head == NULL)
    {
        printf("List is Empty...!");
        return;
    }
    int count = 0;
    sll *p = head;
    while (p != NULL)
    {
        count++;
        p = p->nxt;
    }
    while (count > 0)
    {
        p = head;
        for (int i = 1; i < count; i++)
        {
            p = p->nxt;
        }
        count--;
        printf("| %d | %s |", p->no, p->name);
    }
}

void freeList(sll *head)
{
    sll *temp;

    while (head != NULL)
    {
        temp = head;

        head = head->nxt;

        free(temp);
    }
}