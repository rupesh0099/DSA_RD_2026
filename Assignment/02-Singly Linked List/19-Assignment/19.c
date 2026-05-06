
/*"write a c program to Create a Singly linked list  and perform menu driven which includes following functions: 
          - create(),
          - Insert(),
          - Delete(),
          - Reverse(),
          - print()"*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct singlyLinked{
    int no;
    char name[21];
    struct singlyLinked* nxt;
}sll;

sll* create(sll* );
sll* reverse(sll* head);
sll* deleteAtPosition(sll*);
sll* insertAtPosition(sll*);
void display(sll*);


int main(){
    sll* head=NULL;
   int ch=-1;
   while(1){
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Reverse\n5.Print\n6.Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                head=create(head);
                break;
            
            case 2:
                head=insertAtPosition(head);
                break;

            case 3:
                head=deleteAtPosition(head);
                break;

            case 4:
                head=reverse(head);
                break;

            case 5:
                display(head);
                break;
            
            case 6:
                printf("\nExiting..........");
                exit(0);
            
                default:
                    printf("\nEnter valid Option");
                    break;
        }

   }
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
        scanf(" %[^\n]s",nw->name);
        
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

sll* insertAtPosition(sll* head){
    int pos;
    sll *nw, *temp=head;

    nw=(sll*)malloc(sizeof(sll));
    printf("\nEnter position to insert new node: ");
    scanf("%d",&pos);
    
    printf("\nEnter NO: ");
    scanf("%d",&nw->no);
    printf("\nEnter Name: ");
    scanf(" %[^\n]s",nw->name);
    
    if(pos==1){ 
        nw->nxt=head;
        head=nw;
        return head;
    }

    for(int i=1; temp!=NULL&&i<pos-1; i++){
        temp=temp->nxt;
    }

    if(temp==NULL){
        printf("\nInvalid position!\n");
        
    }
    else{
        nw->nxt=temp->nxt;
        temp->nxt=nw;
    }
    
    return head;
}

sll* deleteAtPosition(sll* head){
    int pos, i;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);

    if(head == NULL){
        printf("\nList is already empty!\n");
        return NULL;
    }

    if(pos == 1){  
        sll* temp = head;
        head = head->nxt;
        
        return head;
    }

    sll *temp=head,*prev=NULL;
    for(i=1; temp!=NULL && i<pos; i++){
        prev=temp;
        temp=temp->nxt;
    }

    if(temp == NULL){
        printf("\nInvalid position!\n");
        return head;
    }

    prev->nxt = temp->nxt;
    

    return head;
}

sll* reverse(sll* head){
    sll* prev=NULL,*curr=head,*Next=NULL;
 
    while(curr!=NULL){
         Next=curr->nxt;
         curr->nxt=prev;
         prev=curr;
         curr=Next;
    }
 
    return prev;
     
 
 
 } 
 
 void display(sll* head){
     while(head!=NULL){
         printf("|%d|%s|%p|->",head->no,head->name,head->nxt);
         head=head->nxt;
     }
     printf("|NULL|");
 }