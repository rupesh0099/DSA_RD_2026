/*write a c program to Create a Menu driven for circular singly linked list which consists the following functions: - 
          - Create(), 
          - Insert(),
          - Delete(), 
          - Display().*/


#include<stdio.h>
#include<stdlib.h>

typedef struct singlyCircular{
    int no;
    char name[21];
    struct singlyCircular* next;
}scl;

scl* create(scl*);
scl* insert(scl*);
scl* deleteNode(scl*);
void freeList(scl* head);
void display(scl*);

int main(){
    scl* head=NULL;
    int choice;
    do{
        printf("\n\n-----======Circular Singly Linked List Menu====-----");
        printf("\n1. Create");
        printf("\n2. Insert");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:head=create(head);break;
            case 2:head=insert(head);break;
            case 3:head=deleteNode(head);break;
            case 4:display(head);break;
            case 5:printf("\nExiting Program...");freeList(head); break;
            default:printf("\nInvalid choice! Try again.");
        }
    }while(choice!=5);
    return 0;
}

scl* create(scl* head){
	scl* nw,*lst=NULL;
	int ans;
	do{
	nw=(scl*)malloc(sizeof(scl));
		if(!nw){
			printf("\n memory is not allocated");
			return head;
		}
		printf("\nEnter Number and Name: \n");
		scanf("%d %[^\n]s",&nw->no,nw->name);
		if(head==NULL){
				lst=head=nw;
				nw->next=head;
		}
		else{
				lst->next=nw;
				nw->next=head;
				lst=nw;
		}
		printf("\nDo you want to add new node? (1/0): \n");
		scanf("%d",&ans);
	}while(ans==1);
	return lst;
}

scl* insert(scl* lst){
	
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
			scanf("%d %[^\n]s",&nw->no,nw->name);
			
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


scl* deleteNode(scl* lst){
     if (!lst) {
        printf("List is empty...!\n");
        return NULL;
    }

    int pos;
    printf("Enter the position to delete node:\n");
    scanf("%d", &pos);

    scl* temp = lst->next, *prev = lst;
    int i;

    if (pos == 1) {
        if (temp == lst) {
            free(lst);
            return NULL;
        }

        lst->next = temp->next;
        free(temp);
        printf("\nNode deleted successfully at position %d\n", pos);
        return lst;
    }

    for (i = 1; temp != lst && i < pos; prev = temp, temp = temp->next, i++);

    if (i < pos || temp == lst->next) {
        printf("\nInvalid position!\n");
        return lst;
    }

    prev->next = temp->next;
    if (temp == lst) lst = prev;
    free(temp);
    printf("\nNode deleted successfully at position %d\n", pos);

    return lst;
}

void display(scl* lst){
	if(!lst){
		printf("\nEmpty list");
		return;
	}
	scl* p=lst->next;
	printf("\n");
	do{
		printf("Number: %d Name: %s \n",p->no,p->name);
		p=p->next;
	}while(p!=lst->next);
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
