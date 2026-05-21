// write a c program to Create a Singly linked list and Insert a node at the last

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct singlyLinked{
    int no;
    char name[21];
    struct singlyLinked* nxt;
} sll;

sll* create(sll*);
sll* insertLast(sll*);
void display(sll*);
void FreeList(sll*);

int main(){

    sll* head = NULL;

    head = create(head);
    head = insertLast(head);
    display(head);
    FreeList(head);

    return 0;
}

sll* create(sll* head){

    sll *nw, *lst = NULL;
    int ch = -1;

    do{

        nw = (sll*)malloc(sizeof(sll));

        if(nw == NULL){
            printf("\nMemory Allocation Failed!\n");
            return head;
        }

        nw->nxt = NULL;

        printf("\nEnter NO: ");
        scanf("%d", &nw->no);

        printf("Enter Name: ");
        fgets(nw->name, sizeof(nw->name), stdin);
        nw->name[strcspn(nw->name, "\n")] = '\0';

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

        printf("Do you want to add node (1/0): ");
        scanf("%d", &ch);

    }while(ch != 0);

    return head;
}

sll* insertLast(sll* head){

    sll *nw, *temp;

    nw = (sll*)malloc(sizeof(sll));

    if(nw == NULL){
        printf("\nMemory Allocation Failed!\n");
        return head;
    }

    nw->nxt = NULL;

    printf("\nEnter Last Node Value:\n");

    printf("Enter No: ");
    scanf("%d", &nw->no);

    printf("Enter Name: ");
    getchar();
    fgets(nw->name, sizeof(nw->name), stdin);
    nw->name[strcspn(nw->name, "\n")] = '\0';

    if(head == NULL){

        head = nw;
    }
    else{

        temp = head;

        while(temp->nxt != NULL){
            temp = temp->nxt;
        }

        temp->nxt = nw;
    }

    return head;
}

void display(sll* head){

    if(head == NULL){
        printf("\nList is Empty!\n");
        return;
    }

    printf("\n----- Linked List -----\n");

    while(head != NULL){

        printf("%d %s\n", head->no, head->name);

        head = head->nxt;
    }
}

void FreeList(sll* head){

    sll* temp;

    while(head != NULL){

        temp = head;

        head = head->nxt;

        free(temp);
    }
}