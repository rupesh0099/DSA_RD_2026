// write a c program to Create a doubly linked list and Delete a node at the end.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct doubly {
    int Number;
    char Name[10];
    struct doubly *next;
    struct doubly *prev;
} DNode;

DNode *create();
DNode *deleteAtLast(DNode *);
void printList(DNode *);
void freeList(DNode *);

int main() {
    DNode *head = NULL;
    head = create();
    head = deleteAtLast(head);
    printList(head);
    freeList(head);
    return 0;
}

DNode *create() {
    DNode *head = NULL, *newNode, *tail = NULL;
    int choice;
    
    do {
        newNode = (DNode *)malloc(sizeof(DNode));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return head;
        }
        
        printf("\nEnter the number and Name:\n");
        scanf("%d %[^\n]", &newNode->Number, newNode->Name);
        
        newNode->next = NULL;
        newNode->prev = tail;
        
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;

        printf("Do you want to enter more records? (1 for yes/0 for no): ");
        scanf("%d", &choice);

    } while (choice == 1);
    
    return head;
}

DNode *deleteAtLast(DNode *head) {
    if (!head) {
        printf("List is empty!\n");
        return NULL;
    }

    DNode *lst = head;
    while (lst->next != NULL) {
        lst = lst->next;
    }

    if (lst->prev == NULL) {
        free(lst);
        return NULL;
    } else {
        lst->prev->next = NULL;
        free(lst);
        return head;
    }
}

void printList(DNode *head) {
    if (!head) {
        printf("\n\tList is empty\n");
        return;
    }
    
    printf("\n\tDoubly Linked List:\n");
    for (; head != NULL; head = head->next) {
        printf("\tNumber: %d, Name: %s\n", head->Number, head->Name);
    }
}

void freeList(DNode *head) {
    DNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
