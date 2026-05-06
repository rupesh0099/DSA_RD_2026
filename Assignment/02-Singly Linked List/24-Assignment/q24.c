/*"create a linnked list and delete a node before key node (given by user)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
                 key: 3
O/P ---->  |_1_|_AA_|_100_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_|"*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct singly
{
    int Number;
    char Name[10];
    int standard;
    struct singly *next;
} node;
node *create();
node *delnode(node *,int);
void display(node *);
void freeList(node *);
int main()
{
    node *head = NULL;
    head = create();
    int pos;
    printf("\n Enter the position: \n");
    scanf("%d", &pos);
    head = delnode(head,pos);
    display(head);
    freeList(head);
    return 0;
}
node *create()
{
    node *head = NULL, *newNode, *lastNode = NULL;
    int choice;
    do
    {
        newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return head;
        }
        printf("\nEnter the number:\n");
        scanf("%d", &newNode->Number);
        getchar();
        printf("Enter name: ");
        fgets(newNode->Name, sizeof(newNode->Name), stdin);
        newNode->Name[strcspn(newNode->Name, "\n")] = '\0';
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            lastNode->next = newNode;
        }
        lastNode = newNode;
        printf("do you want to enter more records?(1 for yes/ 0 for NO):");
        scanf("%d", &choice);
    } while (choice == 1);
    return head;
}
node* delnode(node* head, int pos) {
    if (!head) {
        printf("\nNothing to delete\n");
        return NULL;
    }

    if (pos <= 1) {
        node* temp = head->next;
        head->next = NULL ;
        free(temp);
        return head;
    }

    node*temp=head,*prev=NULL;
      for(int i=1;temp!=NULL && i<pos-1;prev=temp,temp=temp->next,i++);
           
      if(temp!=NULL){
          prev->next=temp->next;
          free(temp);
      }else{
        printf("\n******Invalid Position...!******\n");
      }
     return head;
}
void display(node *head)
{
    if (head == NULL)
    {
        printf("\nthe list is empty.\n");
        return;
    }
    printf("\nLinked List:\n");
    node *temp = head;
    while (temp != NULL)
    {
        printf("Number: %d, Name: %s\n", temp->Number, temp->Name);
        temp = temp->next;
    }
}

void freeList(node *head)
{
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
