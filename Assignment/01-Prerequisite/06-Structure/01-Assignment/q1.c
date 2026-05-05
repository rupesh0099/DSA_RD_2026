#include<stdio.h>
struct Student{
    char name[10];
    int Roll_no;
    float Marks;
};

int main(){
    struct Student stud;
    printf("*****Enter the Students Details*****");
    printf("\nEnter the Name:\n");
    scanf("%s",&stud.name);
    printf("\nEnter the Roll No:\n");
    scanf("%d",&stud.Roll_no);
    printf("\nEnter the Marks:\n");
    scanf("%f",&stud.Marks);
    printf("-------------------------------------\n");
    printf("\n********Students Details*********\n");
    printf("\nStudent Name is:%s\n",stud.name);
    printf("\nStudent Roll NO is:%d\n",stud.Roll_no);
    printf("\nStudent Marks is:%f\n",stud.Marks);
    return 0;
}