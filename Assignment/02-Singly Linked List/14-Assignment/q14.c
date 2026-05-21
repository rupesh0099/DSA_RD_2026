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
void findMiddle(node*);
void freeList(node*);

int main(){

    node* head = NULL;

    head = create();
    findMiddle(head);
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

void findMiddle(node* head){

    if(head == NULL){

        printf("\nList is empty.\n");

        return;
    }

    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;

        fast = fast->next->next;
    }

    printf("\n------ Middle Node ------\n");

    printf("Number   : %d\n", slow->Number);
    printf("Name     : %s\n", slow->Name);
    printf("Standard : %d\n", slow->standard);
}

void freeList(node* head){

    node* temp;

    while(head != NULL){

        temp = head;

        head = head->next;

        free(temp);
    }
}