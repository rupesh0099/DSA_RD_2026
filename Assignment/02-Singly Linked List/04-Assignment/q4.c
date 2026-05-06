/*write a c program to Create a Singly linked list and swap the two consecutive nodes 
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  


O/P  ---->   |_2_|_BB_|_100_| --> |_1_|_AA_|_200_| --> |_4_|_DD_|_300_| --> |_3_|_CC_|_400_| --> |_6_|_FF_|_500_| --> |_5_|_EE_|_NULL_|
*/
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
void swap(node*);
void display(node*);
void freeList(node*);
int main(){
    node* head=NULL;
    head=create();
    swap(head);
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

void swap(node *p){
    int temp_num;
    char temp_name[10];
    node*q=NULL;
    while(p!=NULL){
        q=p->next;
        if(q==NULL)
          break;
        temp_num=p->Number;
        p->Number=q->Number;
        q->Number=temp_num;
        strcpy(temp_name,p->Name);
        strcpy(p->Name,q->Name);
        strcpy(q->Name,temp_name);
        p=p->next->next;
    }
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



