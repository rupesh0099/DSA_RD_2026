#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct singly{
    int Number;
    char Name[10];
    int standard;
    struct singly *next;

} node;

node* create();
node* sort(node*);
void display(node*);
void freeList(node*);

int main(){

    node* head = NULL;

    head = create();
    head = sort(head);

    printf("\nSorted Linked List:\n");

    display(head);
    freeList(head);

    return 0;
}

node* create(){

    node *head = NULL, *newNode, *lastNode = NULL;
    int choice;

    do{

        newNode = (node*)malloc(sizeof(node));

        if(newNode == NULL){

            printf("Memory allocation failed!\n");

            return head;
        }

        printf("\nEnter Number: ");
        scanf("%d", &newNode->Number);

        getchar();

        printf("Enter Name: ");
        fgets(newNode->Name, sizeof(newNode->Name), stdin);

        newNode->Name[strcspn(newNode->Name, "\n")] = '\0';

        printf("Enter Standard: ");
        scanf("%d", &newNode->standard);

        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
        }
        else{
            lastNode->next = newNode;
        }

        lastNode = newNode;

        printf("Do you want to enter more records? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);

    }while(choice == 1);

    return head;
}

node* sort(node* head){

    if(head == NULL){

        printf("\nList is empty.\n");

        return head;
    }

    node *p, *q;

    for(p = head; p != NULL; p = p->next){

        for(q = p->next; q != NULL; q = q->next){

            if(p->Number > q->Number){

                int tempNo = p->Number;
                p->Number = q->Number;
                q->Number = tempNo;

                char tempName[10];
                strcpy(tempName, p->Name);
                strcpy(p->Name, q->Name);
                strcpy(q->Name, tempName);

                int tempStd = p->standard;
                p->standard = q->standard;
                q->standard = tempStd;
            }
        }
    }

    return head;
}

void display(node* head){

    if(head == NULL){

        printf("\nThe list is empty.\n");

        return;
    }

    node* temp = head;

    while(temp != NULL){

        printf("Number: %d, Name: %s, Standard: %d\n",
               temp->Number,
               temp->Name,
               temp->standard);

        temp = temp->next;
    }
}

void freeList(node* head){

    node* temp;

    while(head != NULL){

        temp = head;

        head = head->next;

        free(temp);
    }
}