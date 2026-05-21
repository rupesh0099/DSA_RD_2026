
 //write a c program to Create Linked List using Recursion.


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct singlyLinked{
    int no;
    char name[21];
    struct singlyLinked* nxt;
}sll;

sll* create();
void display(sll*);

int main(){
    sll* head=NULL;
    head=create();
    display(head);
    return 0;
}


sll* create() {
    int ch;
    printf("\ndo you want to add new node:(1 for yes, 0 for No)");
    scanf("%d", &ch);

    if (ch==0)
        return NULL; 


    sll* nw=(sll*)malloc(sizeof(sll));
    if (!nw){
        printf("Memory allocation failed!\n");
        return NULL;
    }
    printf("\nEnter Roll no: ");
    scanf("%d",&nw->no);
    printf("\nEnter Name: ");
    scanf(" %[^\n]",nw->name);
    
    nw->nxt = create();  
    return nw;
}

void display(sll* head){
    while(head!=NULL){
        printf(" %d %s->",head->no,head->name);
        head=head->nxt;
    }
    printf("NULL");
}