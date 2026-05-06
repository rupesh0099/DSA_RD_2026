// write a c program to Create a Singly linked list and delete a node at the last
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct singlyLinked{
    int no;
    char name[21];
    struct singlyLinked* nxt;
}sll;

sll* create(sll* );
void display(sll*);
sll* deleteLast(sll*);

int main(){
    sll* head=NULL;
    head=create(head);
    head=deleteLast(head);
    display(head);
    return 0;
}

sll* create(sll* head){
    sll *nw, *lst=NULL;
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
        printf("\ndo you Want to add another node? (1/0): ");
        scanf("%d",&ch);
    }while(ch!=0);
    
    return head;
}

sll* deleteLast(sll* head){
    if(head == NULL){
        printf("\nList is already empty!\n");
        return NULL;
    }

    if(head->nxt == NULL){  
        return NULL;
    }

    sll *temp = head, *prev = NULL;
    while(temp->nxt != NULL){
        prev = temp;
        temp = temp->nxt;
    }

    prev->nxt = NULL;
    free(temp);
    

    return head;
}

void display(sll* head){
    printf("\nLinked List: \n");
    while(head != NULL){
        printf(" %d  %s  ",head->no,head->name);
        head = head->nxt;
    }
    printf("NULL\n");
}
