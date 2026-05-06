/*"write a c program to Create a Singly linked list and revert it 
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
O/P ---->    |_4_|_DD_|_100_| --> |_3_|_CC_|_200_| --> |_2_|_BB_|_300_| --> |_1_|_AA_|_NULL_|"
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct singlyLinked{
    int no;
    char name[21];
    struct singlyLinked* nxt;
}sll;

sll* create(sll* );
sll* revert(sll* head);
void display(sll*);

int main(){
    sll* head=NULL;
    head=create(head);
    head=revert(head);
    display(head);
    return 0;
}

sll* create(sll* head){
    sll *nw, *lst=NULL;
    int ch=-1;

    do{
        nw=(sll*)malloc(sizeof(sll));
        nw->nxt=NULL;
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

sll* revert(sll* head) {
    sll*q=NULL,*r=NULL;
    while(head!=NULL){
        r=head->nxt;
        head->nxt=q;
        q=head;
        head=r;
    }
    return q;
}

    

 

void display(sll* head){
   while(head!=NULL){
       printf("\n%s\n", head->name); 
        head=head->nxt;
   }
}