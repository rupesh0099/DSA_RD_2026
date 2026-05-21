#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct singlyLinked{
    int no;
    char name[21];
    struct singlyLinked* nxt;
}sll;

sll* create(sll*);
sll* revert(sll*);
void display(sll*);
void freeList(sll*);

int main(){

    sll* head = NULL;

    head = create(head);
    head = revert(head);
    display(head);

    return 0;
}

sll* create(sll* head){

    sll *nw, *lst = NULL;
    int ch;

    do{

        nw = (sll*)malloc(sizeof(sll));

        if(nw == NULL){
            printf("Memory allocation failed!\n");
            return head;
        }

        nw->nxt = NULL;

        printf("\nEnter No: ");
        scanf("%d", &nw->no);

        printf("Enter Name: ");
        scanf("%s", nw->name);

        if(head == NULL){
            head = nw;
        }
        else{
            lst = head;
            while(lst->nxt != NULL){
                lst = lst->nxt;
            }
            lst->nxt = nw;
        }

        printf("Do you want to add another node? (1/0): ");
        scanf("%d", &ch);

    }while(ch != 0);

    return head;
}

sll* revert(sll* head){

    sll *q = NULL, *r = NULL;

    while(head != NULL){

        r = head->nxt;
        head->nxt = q;
        q = head;
        head = r;
    }

    return q;
}

void display(sll* head){

    printf("\nReversed Linked List:\n");

    while(head != NULL){

        printf("|_%d_|_%s_| -> ", head->no, head->name);

        head = head->nxt;
    }

    printf("NULL\n");
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
