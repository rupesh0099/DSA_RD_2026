#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char *p=NULL;
	int size=0;
	printf("enter the size:");
	scanf("%d",&size);
	p=(char*)malloc(sizeof(char)*size+1);
	printf("enter the string:\n");
	for(int i=0;i<=size;i++)
	{
		scanf("%c",p+i);
	}
	printf("string is:\n");
	for(int i=0;p[i]!='\0';i++)
	{
		printf("%c",*(p+i));
	}
return 0;
}