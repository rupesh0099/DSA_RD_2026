/*  
    Write a c program which demonstrate a nested structure 
	- define a structure employee inside a structure person.
    - structure person data: 
                        Name, Age, Date of birth, blood group.
    - structure employee data:
                        Company name, Emp id, salary, years of experiance.
						
	- create objects of structure and display the all details of a person.

*/

#include<stdio.h>
struct Person{
    char Name[10];
    int Age;
    int Date_of_birth;
    char blood_group;
    struct Employee{
       char Company_name[10];
       int Emp_id;
       float salary;
       int years_of_experiance;
    }emp;
};

int main(){
    struct Person per;
    printf("*****Enter the Person Details*****");
    printf("\nEnter the person Name:\n");
    scanf(" %s",&per.Name);
    printf("\nEnter the Person Age:\n");
    scanf("%d",&per.Age);
    printf("\nEnter the Person Date of Birth:\n");
    scanf("%d",&per.Date_of_birth);
    printf("\n*****Enter the Employee Details*****\n");
    printf("\nEnter the Employee Name:\n");
    scanf(" %s",&per.emp.Company_name);
    printf("\nEnter the Employee id:\n");
    scanf("%d",&per.emp.Emp_id);
    printf("\nEnter the Employee salary:\n");
    scanf("%f",&per.emp.salary);
    printf("\nEnter the Employee's Year of experiance:\n");
    scanf("%d",&per.emp.years_of_experiance);
    printf("-------------------------------------\n");
    printf("\n********Person Details*********\n");
    printf("\nPerson Name is:%s\n",per.Name);
    printf("\nPerson Age is:%d\n",per.Age);
    printf("\nPerson Date of Birth is:%d\n",per.Date_of_birth);
    printf("\n********Employee Details*********\n");
    printf("\nEmployee's Company name is:%s\n",per.emp.Company_name);
    printf("\nEmployee's Company id is:%d\n",per.emp.Emp_id);
    printf("\nEmployee's Company salary is:%f\n",per.emp.salary);
    printf("\nEmployee's Company experiance is:%f\n",per.emp.years_of_experiance);
return 0;
}