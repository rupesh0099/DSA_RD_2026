/*"write a c program to Create a Singly linked list and Display it in reverse order (Use Recursive Function)  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
O/P :
------  
4 DD
3 CC
2 BB
1 AA"
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct singlyLinked{
    int no;
    char name[21];
    struct singlyLinked* nxt;
}sll;

sll* create(sll*);
void reverse(sll*);

int main(){
    sll* head=NULL;
    head=create(head);
    reverse(head);
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

void reverse(sll*head){ 
  if(head == NULL){  
    return;
}
   reverse(head->nxt); 
  printf("\n%d\n%s",head->no, head->name); 
}
