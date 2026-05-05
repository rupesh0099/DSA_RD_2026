/*Create a structure "Students" with below member variables:
    - Name of student,
    - Roll no. Of Student,
    - array of 5 Subject marks,
    - Total Percentage

- Calculate the Percentage for "N" number of students,
- Display all details for all students,
- Display the details of topper.
(use array of structure)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[20];
    int rno;
    int marks[5];
    float percentage;
};

void accept(struct student *, int);
void TopperList(struct student *, int);
void display(struct student *, int);

int main()
{
    int n=0;

    printf("\nEnter the n number of students:\n");
    scanf("%d",&n);

    struct student *stud = (struct student *)malloc(sizeof(struct student) * n);

    accept(stud, n);
    display(stud, n);
    TopperList(stud, n);

    free(stud);
    stud=NULL;
    return 0;
}

void accept(struct student *ptr, int n)
{
    printf("\n***Enter the Details***\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d) Student name: ", i + 1);
        scanf(" %[^\n]s", ptr[i].name);

        printf("Student roll number: ");
        scanf("%d", &ptr[i].rno);

        int total = 0;

        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < 5; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &ptr[i].marks[j]);
            total += ptr[i].marks[j];
        }
        ptr[i].percentage = total / 5.0;
    }
}

void display(struct student *ptr, int n)
{
    printf("\n****Students Details****\n");

    for (int i = 0; i < n; i++)
    {
        printf("\n%d) Name: %s", i + 1, ptr[i].name);
        printf("\n   Roll No: %d", ptr[i].rno);
        printf("\n   Marks: ");

        for (int j = 0; j < 5; j++)
        {
            printf(" %d", ptr[i].marks[j]);
        }
        printf("\n   Percentage: %f\n", ptr[i].percentage);
        printf("\n**********************\n");
    }
}

void TopperList(struct student *ptr, int n)
{
    printf("\n****Topper Students List****\n");

    for (int i = 0; i < n; i++)
    {
        if (ptr[i].percentage >= 90.0)
        {
            printf("\n%d) Name: %s", i + 1, ptr[i].name);
            printf("\n   Roll No: %d", ptr[i].rno);
            printf("\n   Percentage: %f\n", ptr[i].percentage);
            printf("\n**********************\n");
        }else{
            printf("\n%d) Name: %s is not a topper student.\n", i + 1, ptr[i].name);
        }
    }
}
