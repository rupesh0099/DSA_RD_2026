/* write a c program to Create and Display Singly Linked list. with structure ""Student"" with following data members:
-Name 
-Roll no
-standard
-Division*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct singly{
 char Name[10]; 
int Roll_no;
int standard;
char Division[5];
struct singly *next;
}node;
node*create();
void display(node*);
void freeList(node*);
int main(){
    node* head=NULL;
    head=create();
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
        printf("\nEnter the number and name:\n");
        scanf("%d",&newNode->Roll_no);
        getchar();
        printf("Enter name: ");
        fgets(newNode->Name,sizeof(newNode->Name),stdin);
        newNode->Name[strcspn(newNode->Name,"\n")]='\0';
        printf("Enter the Standard: ");
        scanf("%d",&newNode->standard);
        printf("Enter the Division: ");
        scanf("%s",&newNode->Division);
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
void display(node*head){
    if(head==NULL){
        printf("\nthe list is empty.\n");
        return;
    }
    printf("\nLinked List:\n");
    node*temp=head;
    while(temp!=NULL){
        printf("Number: %d, Name:%s,Standard: %d,Division: %s\n",temp->Roll_no,temp->Name,temp->standard,temp->Division);
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