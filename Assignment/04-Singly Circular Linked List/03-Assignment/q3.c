//write a c program to Create a circular singly  linked list and insert a new node  at given position
#include<stdio.h>
#include<stdlib.h>

typedef struct singlycircular{
    int No;
    char Name[20];
    struct singlycircular*next;
}scl;

scl* create(scl*);
scl* insertAtposition(scl*);
void display(scl*);
void freeList(scl*);

int main(){

    scl*head=NULL;
    head=create(head);
    head=insertAtposition(head);
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

   return lst;
}

scl* insertAtposition(scl* lst){
	
	scl* nw,*p;
	int i,pos;
	
			nw=(scl*)malloc(sizeof(scl));
			if(!nw){
					printf("\nNew memory not allocared");
					return lst;
			}
			nw->next=NULL;
			printf("\n\nEnter position to Enter new node: ");
			scanf("%d",&pos);
			
			printf("\nEnter Number and name:");
			scanf("%d %[^\n]s",&nw->No,nw->Name);
			
			if(pos==1){
				if(lst==NULL){
					lst=nw;
					lst->next=lst;
				}
				else{

					nw->next=lst->next;
					lst->next=nw;
				}
			}	
			else{
					
					for(i=1,p=lst->next;i<pos-1&&p!=lst;i++,p=p->next);
				    if(i==pos-1){
							if(p==lst){
									nw->next=lst->next;
									lst->next=nw;
									lst=nw;
							}
							else{
									nw->next=p->next;
									p->next=nw;
							}
					}
					else{
							printf("\nInvalid position");
					}
			}
	

    return lst;
}

void display(scl* lst){

    if(!lst){
        printf("List is Empty...!\n");
        return;
    }

    scl*temp=lst->next;

    do{
        printf("\n Number:%d Name:%s \n",temp->No,temp->Name);
        temp=temp->next;
    }while(temp!=lst->next);

}

void freeList(scl *lst) {
    if (!lst) {
        return;
    }

    scl *temp = lst->next, *p;

    while (temp != lst) {
        p = temp->next;
        free(temp);
        temp = p;
    }
    free(lst);
}
