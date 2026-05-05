#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[10];
    int rno;
    float marks;
};

int main(){

    struct student stud;
    struct student *ptr;
    ptr=&stud;

    ptr=(struct student*)malloc(sizeof(struct student));
    printf("enter the name:\n");
	scanf("%s",ptr->name);
    printf("enter the rno:\n");
	scanf("%d",&ptr->rno);
	printf("enter the marks:\n");
	scanf("%f",&ptr->marks);

    printf("name:%s\n",ptr->name);
	printf("rno:%d\n",ptr->rno);
	printf("marks:%f\n",ptr->marks);
    
    free(ptr);
    ptr=NULL;

 return 0;
}