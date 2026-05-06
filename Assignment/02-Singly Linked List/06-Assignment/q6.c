/*   write a c program to Create a Singly Linked list and  Display the addition of two consecutive nodes to the next node 
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 

O/P ---->    |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_AABB_|_700_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_800_| --> |_7_|_CCDD_|_NULL_|
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
void display(sll*);
sll* add(sll*);

void search(const sll*);

int main(){
    sll* head=NULL;
    head=create(head);
    head=add(head);
    display(head);
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
        printf("\ndo you Want to add node: (1/0)");
        scanf("%d",&ch);
    }while(ch!=0);
    return head;
}

sll* add(sll* head){
    sll* temp=NULL;
    temp=head;
    while(temp!=NULL&&temp->nxt!=NULL){
            sll* nw=(sll*)malloc(sizeof(sll));
            nw->no = temp->no + temp->nxt->no;
            strcpy(nw->name,temp->name);
            strcat(nw->name,temp->nxt->name);
            nw->nxt=temp->nxt->nxt;
            temp->nxt->nxt=nw;
            temp=nw->nxt;

    }
    return head;
}
void display(sll* head){
    printf("\n");
    for(int i=0;head!=NULL;i++){
        printf("\n%d %s \n",head->no,head->name);
                head=head->nxt;
        
    }
}