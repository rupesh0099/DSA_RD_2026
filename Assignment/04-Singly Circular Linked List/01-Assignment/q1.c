//write a c program to Create and display circular singly linked list.
#include<stdio.h>
#include<stdlib.h>

typedef struct singlycircular{
    int No;
    char Name[20];
    struct singlycircular*next;
}scl;

scl* create(scl*);
void display(scl*);
void freeList(scl*);

int main(){
    scl*head=NULL;
    head=create(head);
    display(head);
    freeList(head);
  return 0;
}

scl* create(scl*head){

    scl*nw,*lst;
    int choice;

    do{
        nw=(scl*)malloc(sizeof(scl));

        if(!nw){
            printf("Memory Allocation failed....!");
          return NULL;
        }

        printf("\nEnter the Number and Name: \t\n");
        scanf("%d %[^\n]s",&nw->No,nw->Name);

        nw->next=NULL;

        if(head==NULL){
            head=nw;
            lst=nw;
            lst->next=head;
        }
        else{
            nw->next=head;
            lst->next=nw;
            lst=nw;
        }

        printf("Do you want to enter more records?(1 for yes/ 0 for NO):");
        scanf("%d", &choice);

      }while(choice==1);

   return head;
}

void display(scl*head){

    if(!head){
        printf("List is Empty...!\n");
        return;
    }

    scl*temp=head;

    do{
       printf("\nNumber: %d Name: %s\n",temp->No,temp->Name);
       temp=temp->next;
    }while(temp!=head);

}

void freeList(scl*head){
    if(!head){
        printf("List is Empty....!");
        return;
    }


    scl *temp = head, *p=NULL;;

    do {
        p = temp->next;
        free(temp);
        temp = p;
    } while (temp != head);
}

