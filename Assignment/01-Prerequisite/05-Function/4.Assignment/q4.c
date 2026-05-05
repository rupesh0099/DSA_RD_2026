#include<stdio.h>
void concatenate(char*,char*);
int main(){
	char ch1[10];
	char ch2[15];
	int len=0;
	printf("Enter the 1st String:\n");
	scanf("%s",ch1);
	printf("Enter the 2nd String:\n");
	scanf("%s",ch2);
    concatenate(ch1,ch2);
	return 0;
}
void concatenate(char*ch1,char*ch2){
    int len=0;
	for(int i=0;ch2[i]!='\0';i++){
		len++;
	}
	for(int i=0,j=len;ch1[i]!='\0';i++,j++){
		ch1[j]=ch2[i];
    }
    printf("\nconcatenate string is:\n");
	for(int i=0;ch1[i]!='\0';i++){
      printf("%c",ch1[i]);
    }
}