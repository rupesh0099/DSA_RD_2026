#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr1=NULL,i=0;
    char *ptr2=NULL;
    float *ptr3=NULL;
    ptr1=(int*)malloc(sizeof(int));
    ptr2=(char*)malloc(sizeof(char));
    ptr3=(float*)malloc(sizeof(float));
    printf("\nEnter the integer value:\n");
    scanf("%d",ptr1);
    printf("\nEnter the char value:\n");
    scanf(" %c",ptr2);
    printf("\nEnter the float value:\n");
    scanf("%f",ptr3);
    printf("\nFree Allocated memory for integer..\n");
    free(ptr1);
    ptr1=NULL;
    printf("\nFree Allocated memory for character:..\n");
    free(ptr2);
    ptr2=NULL;
    printf("\nFree Allocated memory for float...\n");
    free(ptr3);
    ptr3=NULL;
    return 0;
}