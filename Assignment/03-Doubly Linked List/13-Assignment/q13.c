// write a c program to Create a doubly linked list and Sort the doubly linked list while creation.


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct DoublyLinked{
    int no;
    char name[21];
    struct DoublyLinked* prev;
    struct DoublyLinked* nxt;
}dll;

dll* create(dll*);
void display(dll*);
void freeList(dll*);

int main(){
    dll* head=NULL;
    head=create(head);
    printf("\n");
    display(head);
    freeList(head);
    return 0;
}

dll* create(dll* head){
    dll* nw,*lst=NULL,*temp;

    int ch;

    
    do{
        nw=(dll*)malloc(sizeof(dll));
        if(!nw){
            printf("\nMemory not allocated");
            exit(1);
        }
        nw->nxt=NULL;
        nw->prev=NULL;
        printf("\nEnter Number And Name:\n");
        scanf("%d %[^\n]s",&nw->no,nw->name);
        
        if(head==NULL||nw->no<head->no){
            
            nw->nxt=head;
            if(head) head->prev=nw;
            head=nw;
            
        }
        else{
            temp=head;
            while(temp->nxt!=NULL&&temp->nxt->no<nw->no){
                temp=temp->nxt;
            }
            nw->nxt=temp->nxt;
            nw->prev=temp;
            if(temp->nxt) temp->nxt->prev=nw;
            temp->nxt=nw;
        }
       
      
        
       
        printf("\nDo you want to add new node:(1/0)");
        scanf("%d",&ch);

    }while(ch==1);
    return head;
}




void display(dll* head){
    while (head!=NULL)
    {
        printf(" %d %s ",head->no,head->name);
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
