#include<stdio.h>
struct Employee{
    char Employee_name[10];
    int Employee_id;
    float Employee_salary;
};

int main(){
    struct Employee emp ;
    printf("*****Enter the Employee Details*****");
    printf("\nEnter the Name:\n");
    scanf("%s",&emp.Employee_name);
    printf("\nEnter the id:\n");
    scanf("%d",&emp.Employee_id);
    printf("\nEnter the salary:\n");
    scanf("%f",&emp.Employee_salary);
    printf("-------------------------------------\n");
    printf("\n********Employee Details*********\n");
    printf("\nEmployee Name is:%s\n",emp.Employee_name);
    printf("\nEmployee id is:%d\n",emp.Employee_id);
    printf("\nEmployee salary is:%f\n",emp.Employee_salary);
    return 0;
}