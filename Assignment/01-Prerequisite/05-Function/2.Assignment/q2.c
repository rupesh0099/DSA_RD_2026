#include<stdio.h>
void lenght(char*,int);
int main(){
	char arr[10];
	int count=0;
	printf("Enter the String:\n");
	scanf("%s",arr);
	lenght(arr,count);
	return 0;
}
void lenght(char *ptr,int count){
	for(int i=0;ptr[i]!='\0';i++){
		count++;
	}
	printf("Lenght of string is:%d",count);
}