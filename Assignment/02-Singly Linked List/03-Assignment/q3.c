/*write a c program to Create a Singly linked list and Display the alternate nodes 

I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_NULL_|. 

O/P  ---->  |_1_|_AA_|_100_| --> |_3_|_CC_|_300_| --> |_5_|_EE_|_NULL_|
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
void alternate(node*);
void freeList(node*);
int main(){
    node* head=NULL;
    head=create();
    alternate(head);
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
void alternate(node*temp){
    while(temp!=NULL){
        printf("\nNumber is:%d\n",temp->Number);
        printf("\ncharacter is:%s\n",temp->Name);
        if(temp->next!=NULL)
            temp=temp->next->next;
        else
            break;
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


