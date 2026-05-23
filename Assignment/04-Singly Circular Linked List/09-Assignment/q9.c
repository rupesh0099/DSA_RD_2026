//write a c program to create a circular singly linked list and delete the node by position 
#include <stdio.h>
#include <stdlib.h>

typedef struct singlycircular {
    int No;
    char Name[20];
    struct singlycircular *next;
} scl;

scl *create();
scl *deleteAtPosition(scl *, int);
void display(scl *);
void freeList(scl *);

int main() {
    scl *head = NULL;
    int pos;

    head = create();
    
    printf("\nEnter position to delete node: ");
    scanf("%d", &pos);
    
    head = deleteAtPosition(head, pos);
    
    display(head);
    freeList(head);

    return 0;
}

scl *create() {
    scl *head = NULL, *nw, *lst = NULL;
    int choice;

    do {
        nw = (scl *)malloc(sizeof(scl));

        if (!nw) {
            printf("Memory Allocation failed...!\n");
            return NULL;
        }

        printf("\nEnter the Number and Name:\n");
        scanf("%d %[^\n]s", &nw->No,nw->Name);
        
        nw->next = NULL;

        if (head == NULL) {
            head = nw;
            lst = nw;
            lst->next = head;
        } else {
            nw->next = head;
            lst->next = nw;
            lst = nw;
        }

        printf("Do you want to enter more records? (1 for yes / 0 for NO): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return head;
}

scl *deleteAtPosition(scl *head, int pos) {
    if (!head) {
        printf("List is Empty...!\n");
        return NULL;
    }

    scl *temp = head, *prev = NULL;
    int i;

    if (pos == 1) {
        if (head->next == head) {
            free(head);
            return NULL;
        }

        scl *last = head;
        while (last->next != head) {
            last = last->next;
        }

        temp = head;
        head = head->next;
        last->next = head;
        free(temp);
        printf("\nNode deleted successfully at position %d\n", pos);
        return head;
    }

    for (i = 1; temp->next != head && i < pos; prev = temp, temp = temp->next, i++);

    if (i < pos || temp == head) {
        printf("\nInvalid position!\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("\nNode deleted successfully at position %d\n", pos);

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
void freeList(scl *head) {
    if (!head) {
        return;
    }

    scl *temp = head, *nextNode;

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
}
