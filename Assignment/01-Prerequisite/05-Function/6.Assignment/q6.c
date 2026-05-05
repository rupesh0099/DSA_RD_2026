#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student 
{
    char name[20];
    int rno;
    int marks;
};
void accept(struct student*,int);
void display(struct student*,int);
int main()
{
    struct student *s=NULL;
    int n=0;
    printf("\nEnter the N number of Students:\n");
    scanf("%d",&n);
    s=(struct student*)malloc(sizeof(struct student)*n);
    accept(s,n);
    display(s,n);
    free(s);
    s=NULL;
    return 0;
}

void accept(struct student *ptr,int n)
{   
    printf("\n***Enter the Details:***\n");
    for(int i=0;i<n;i++)
    {
    printf("\n%d)Student name:",i+1);
    scanf(" %[^\n]s",ptr[i].name);
    printf("\n Student rno:");
    scanf("%d",&ptr[i].rno);
    printf("\n Student marks:");
    scanf("%d",&ptr[i].marks);
    }
        
}
void display(struct student *ptrs,int n)
{
    printf("\n****Students Details****\n");
    for(int i=0;i<n;i++)
    {
    printf("\n%d) Stduents name is: %s\n",i+1,ptrs[i].name);
    printf("\n   Students rno is:%d\n",ptrs[i].rno);
    printf("\n   Students marks is:%d\n",ptrs[i].marks);
	printf("\n**********************\n");
    }
}
