// write a c program to Create a Singly linked list and Insert a node at the last

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct singlyLinked{
    int no;
    char name[21];
    struct singlyLinked* nxt;
}sll;

sll* create(sll* );
sll* insertLast(sll*);
void display(sll*);
void FreeList(sll*);

int main(){
    sll* head=NULL;
    head=create(head);
    head=insertLast(head);
    display(head);
    FreeList(head);
    return 0;
}

sll* create(sll* head){
    sll *nw,*lst=NULL;
    int ch=-1;

    do{
        nw=(sll*)malloc(sizeof(sll));
        nw->nxt=NULL;
        printf("\nEnter NO: ");
        scanf("%d",&nw->no);
        printf("\nEnter Name: ");
        scanf(" %s",nw->name);
        
        if(head==NULL){
            head=nw;
        }
        else{
            lst=head;
            while(lst->nxt!=NULL){
                    lst=lst->nxt;
            }
            lst->nxt=nw;
        }
        printf("\ndo you Want ot add node: (1/0)");
        scanf("%d",&ch);
    }while(ch!=0);
    return head;
}

sll* insertLast(sll* head){
    
    sll* nw,*temp=head;
    nw=(sll*)malloc(sizeof(sll));
   
    if (!nw) {
        printf("\nMemory allocation failed!\n");
        return head;
    }

    nw->nxt=NULL;
    printf("\nEnter last Node value: \n");
    printf("\nEnter no: ");
    scanf("%d",&nw->no);
    printf("\nEnter Name: ");
    scanf(" %s",nw->name);
    for(;temp->nxt!=NULL;temp=temp->nxt);
    if(head==NULL){
        head=nw;
    }
    else{
        temp->nxt=nw;
    }

    
    return head;
}
void display(sll* head){
    printf("\n");
    for(int i=0;head!=NULL;i++){
        printf("%d %s \n",head->no,head->name);
            
                head=head->nxt;
        
    }
}

void FreeList(sll*head){
       sll*temp;
       while(head!=NULL){
           temp=head;
           head=head->nxt;
           free(temp);
       }
   }