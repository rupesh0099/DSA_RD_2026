//write a c program to Create a Singly linked list and Delete the node at the Head position
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
node* delheadnode(node*);
void display(node*);
void freeList(node*);

int main(){

    node* head = NULL;

    head = create();
    head = delheadnode(head);
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

        printf("\nEnter the Number: ");
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

node* delheadnode(node* head){

    if(head == NULL){

        printf("\nList is already empty!\n");

        return NULL;
    }

    node* p = head;

    head = head->next;

    free(p);

    printf("\nHead node deleted successfully.\n");

    return head;
}

void display(node* head){

    if(head == NULL){

        printf("\nThe list is empty.\n");

        return;
    }

    printf("\n------ Linked List ------\n");

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