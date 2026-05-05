#include<stdio.h>
void copystring(char*,char*);
int main(){
	char ch1[10];
	char ch2[10];
	printf("\nEnter the String:\n");
	scanf("%s",ch1);
	copystring(ch1,ch2);
	return 0;
}
void copystring(char*ch1,char*ch2){
	printf("\nCopy String is:\n");
	for(int i=0;ch1[i]!='\0';i++){
		ch2[i]=ch1[i];
		printf("%c",ch2[i]);
	}
}