#include<stdio.h>
#include<stdlib.h>

struct student 
{
    char name[20];
    int rno;
    int marks;
};

void accept(struct student*, int);
void display(struct student*, int);

int main()
{
    struct student *s = NULL;
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    s = (struct student*)malloc(sizeof(struct student) * n);

    if (s == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    accept(s, n);
    display(s, n);

    free(s);

    return 0;
}

void accept(struct student *ptr, int n)
{
    printf("\n--- Enter Student Details ---\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        scanf(" %19[^\n]", ptr[i].name); 

        printf("Roll No: ");
        scanf("%d", &ptr[i].rno);

        printf("Marks: ");
        scanf("%d", &ptr[i].marks);
    }
}

void display(struct student *ptr, int n)
{
    printf("\n--- Student Details ---\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Name   : %s\n", ptr[i].name);
        printf("Roll No: %d\n", ptr[i].rno);
        printf("Marks  : %d\n", ptr[i].marks);
        printf("----------------------\n");
    }
}