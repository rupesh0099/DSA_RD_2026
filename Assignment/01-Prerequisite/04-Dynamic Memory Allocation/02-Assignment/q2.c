#include<stdio.h>
#include<stdlib.h>

int main(){

    char *ptr=NULL;
    int size,i,j;

    printf("\nEnter the string size:\n");
    scanf("%d",&size);

    ptr=(char*)malloc(sizeof(char)*(size+1));

    printf("\nEnter the string:\n");
    for( i=0;i<size+1;i++){
      scanf("%c",&ptr[i]);
    }
    ptr[i+1]='\0';

    printf("String is:%s\n",ptr);
    
    free(ptr);
    ptr=NULL;
    
    return 0;
}