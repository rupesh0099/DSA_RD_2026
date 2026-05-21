#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct singlyLinked{
    int no;
    char name[21];
    struct singlyLinked* nxt;
}sll;

sll* create(sll*);
sll* insertAtPosition(sll*);
sll* deleteAtPosition(sll*);
sll* reverse(sll*);
void display(sll*);
void freeList(sll*);
int main(){

    sll* head = NULL;
    int ch;

    while(1){

        printf("\n1.Create\n2.Insert\n3.Delete\n4.Reverse\n5.Print\n6.Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);

        switch(ch){

            case 1:
                head = create(head);
                break;

            case 2:
                head = insertAtPosition(head);
                break;

            case 3:
                head = deleteAtPosition(head);
                break;

            case 4:
                head = reverse(head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                freeList(head);
                exit(0);

            default:
                printf("\nInvalid Choice\n");
        }
    }
}

sll* create(sll* head){

    sll *nw, *lst=NULL;
    int ch;

    do{

        nw = (sll*)malloc(sizeof(sll));
        nw->nxt = NULL;

        printf("\nEnter NO: ");
        scanf("%d",&nw->no);

        printf("Enter Name: ");
        scanf(" %[^\n]",nw->name);

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

        printf("Add more? (1/0): ");
        scanf("%d",&ch);

    }while(ch != 0);

    return head;
}

sll* insertAtPosition(sll* head){

    int pos;
    sll *nw, *temp = head;

    nw = (sll*)malloc(sizeof(sll));

    printf("\nEnter Position: ");
    scanf("%d",&pos);

    printf("Enter NO: ");
    scanf("%d",&nw->no);

    printf("Enter Name: ");
    scanf(" %[^\n]",nw->name);

    nw->nxt = NULL;

    if(pos == 1){
        nw->nxt = head;
        return nw;
    }

    for(int i=1; temp!=NULL && i<pos-1; i++){
        temp = temp->nxt;
    }

    if(temp == NULL){
        printf("\nInvalid Position\n");
        free(nw);
        return head;
    }

    nw->nxt = temp->nxt;
    temp->nxt = nw;

    return head;
}

sll* deleteAtPosition(sll* head){

    int pos;
    printf("\nEnter Position: ");
    scanf("%d",&pos);

    if(head == NULL){
        printf("\nList Empty\n");
        return NULL;
    }

    sll *temp = head, *prev = NULL;

    if(pos == 1){
        head = head->nxt;
        free(temp);
        return head;
    }

    for(int i=1; temp!=NULL && i<pos; i++){
        prev = temp;
        temp = temp->nxt;
    }

    if(temp == NULL){
        printf("\nInvalid Position\n");
        return head;
    }

    prev->nxt = temp->nxt;
    free(temp);

    return head;
}

sll* reverse(sll* head){

    sll *prev=NULL,*curr=head,*next=NULL;

    while(curr != NULL){
        next = curr->nxt;
        curr->nxt = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void display(sll* head){

    if(head == NULL){
        printf("\nList Empty\n");
        return;
    }

    printf("\nLinked List:\n");

    while(head != NULL){
        printf("%d %s -> ",head->no,head->name);
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
