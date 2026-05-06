/*write a c program to create and display a node. with structure ""Student"" with following data members:   
-Name 
-Roll no
-standard
-Division
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct singly{
 char Name[10]; 
int Roll_no;
int standard;
char Division[5];
struct singly *next;
}sll;
sll*create(sll*);
void display(sll*);
int main(){
    sll* start=NULL;
    start=create(start);
    display(start);
    free(start);
    start=NULL;
    return 0; 
}
sll*create(sll*head){
    int ch;
        head=(sll*)malloc(sizeof(sll));
        printf("\nEnter the Students Name:\n");
        scanf("%s",head->Name);
        printf("\nEnter the Students ROLL_NO:");
        scanf("%d",&head->Roll_no);
        printf("\nEnter the Students Standard:\n");
        scanf("%d",&head->standard);
        printf("\nEnter the Students Division:\n");
        scanf("%s",head->Division);
 return head;
}

void display(sll*temp){
        printf("\nStudent Name is:%s\n",temp->Name);
        printf("\nStudent Roll No is:%d\n",temp->Roll_no);
        printf("\nStudent Standard is:%d\n",temp->standard);
        printf("\nStudent Division is:%s\n",temp->Division);
}