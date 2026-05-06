//write a c program to Create a doubly linked list and Insert the Node at Head .

#include<stdio.h>
#include<stdlib.h>

typedef struct doublyLinked{
    int no;
    char name[21];
    struct doublyLinked* prev;
    struct doublyLinked* nxt;
}dll;

dll* create(dll*);
dll* insertHead(dll*);
void display(dll*);
void freeList(dll*);

int main(){
    dll* head=NULL;
    head=create(head);
    head=insertHead(head);
    display(head);
    freeList(head);
    return 0;
}

dll* create(dll* head){
    dll* nw,*lst=NULL;
    int ans=0;
    do{
        nw=(dll*)malloc(sizeof(dll));
        if(!nw){
            printf("\nNew node not allocated");
            exit(1);
        }
        nw->nxt=NULL;
        nw->prev=NULL;
        printf("\nEnter roll no:");
        scanf("%d",&nw->no);
        printf("\nEnter name:");
        scanf(" %[^\n]s",nw->name);
        if(head==NULL){
            head=lst=nw;

        }
        else{
            lst->nxt=nw;
            nw->prev=lst;
            lst=nw;
        }
        printf("\nDo you want to add new node: (1/0)");
        scanf("%d",&ans);
    }while(ans==1);
    return head;
}

dll* insertHead(dll* head){
    dll* nw;
    nw=(dll*)malloc(sizeof(dll));
    if(!nw){
        printf("\nNew node not allocated");
        return NULL;
    }
    nw->nxt=NULL;
    nw->prev=NULL;
    printf("\nEnter number and Name to insert:\n");
    scanf("%d %s[^\n]s",&nw->no,nw->name);
    
    if(head==NULL) return head=nw;
    else{

        nw->nxt=head;
        head->prev=nw;
        head=nw;
    }
    return head;
}

void display(dll* head){
    while (head!=NULL)
    {
        printf("%d %s\n",head->no,head->name);
        head=head->nxt;
    }
    
}

void freeList(dll* head){
    dll* temp=NULL;
    while(head!=NULL){
        temp=head;
        head=head->nxt;
        free(temp);
    }
}
