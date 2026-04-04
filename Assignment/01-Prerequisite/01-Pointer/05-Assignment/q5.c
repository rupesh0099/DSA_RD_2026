#include <stdio.h>

int main()
{
    
    int *ptr1 ;
    float *ptr2 ;
    char *ptr3 ;
    double *ptr4 ;

    printf("\nSize of int pointer variable is: %d byte.\naddress of int pointer variable is: %p\n", sizeof(*ptr1), &ptr1);
    printf("\nSize of float pointer variable is: %d byte.\naddress of float pointer variable is: %p\n", sizeof(*ptr2), &ptr2);
    printf("\nSize of char pointer variable is: %d byte.\naddress of char pointer variable is: %p\n", sizeof(*ptr3), &ptr3);
    printf("\nSize of double pointer variable is: %d byte.\naddress of double pointer variable is: %p\n", sizeof(*ptr4), &ptr4);

    return 0;
}