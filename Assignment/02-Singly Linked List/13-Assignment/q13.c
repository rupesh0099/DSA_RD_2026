// write a c program to Create a Singly linked list and delete a perticular node
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct singly{
 int Number;
 char Name[10]; 
int standard;
struct singly *next;
}node;
node*create();
node* delperNode(node*);
void display(node*);
void freeList(node*);
int main(){
    node* head=NULL;
    head=create();
    head=delperNode(head);
    display(head);
    freeList(head);
    return 0; 
}
node*create(){
    node *head=NULL,*newNode,*lastNode=NULL;
    int choice;
    do{
        newNode=(node*)malloc(sizeof(node));
        if(newNode==NULL){
            printf("Memory allocation failed!\n");
            return head;
        }
        printf("\nEnter the number:\n");
        scanf("%d",&newNode->Number);
        getchar();
        printf("Enter name: ");
        fgets(newNode->Name,sizeof(newNode->Name),stdin);
        newNode->Name[strcspn(newNode->Name,"\n")]='\0';
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
        }else{
            lastNode->next=newNode;
        }
        lastNode=newNode;
        printf("do you want to enter more records?(1 for yes/ 0 for NO):");
        scanf("%d",&choice);
    }while(choice==1);
    return head;
}
 node* delperNode(node*head){
    node*q=NULL,*p;
    int key=0,flag=0;
    printf("Enter the key:\n");
    scanf("%d",&key);
    for(p=head;p!=NULL;q=p,p=p->next){
        if(p->Number==key){
            if(p==head){
                head=p->next;
            }else{
                q->next=p->next;
            }
            free(p);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\n\tNot found");
    }
    return head;
}

 void display(node*head){
   if(head==NULL){
       printf("\nthe list is empty.\n");
       return;
   }
   printf("\nLinked List:\n");
   node*temp=head;
   while(temp!=NULL){
       printf("Number: %d, Name: %s\n",temp->Number,temp->Name);
       temp=temp->next;
   }
}

   void freeList(node*head){
       node*temp;
       while(head!=NULL){
           temp=head;
           head=head->next;
           free(temp);
       }
   }
