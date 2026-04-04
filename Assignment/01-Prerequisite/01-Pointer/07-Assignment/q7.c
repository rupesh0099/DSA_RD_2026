#include <stdio.h>
#include <string.h>
struct Student
{
    int rno;
    char name[10];
    int id;
    float marks;
};

int main()
{
    struct Student s;
    struct Student *ptr;
    ptr = &s;

    printf("\n***Enter the Students Details***\n");

    printf("Enter the Students Roll Number:");
    scanf(" %d", &ptr->rno);

    printf("\nEnter the Students Name:");
    getchar();
    gets(ptr->name);

    printf("\nEnter the Students id:");
    scanf("%d", &ptr->id);
    
    printf("\nEnter the Students Marks:");
    scanf("%f", &ptr->marks);

    printf("Student Roll No is:%d\n", ptr->rno);
    printf("Student Name is:%s\n", ptr->name);
    printf("Student ID is:%d\n", ptr->id);
    printf("Student Marks is:%f\n", ptr->marks);

    return 0;

}