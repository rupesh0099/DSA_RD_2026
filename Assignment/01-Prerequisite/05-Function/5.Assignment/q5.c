#include<stdio.h>
#include<string.h>
void reverse(char*);
int main(){
	char ch[10];
	printf("Enter the String:\n");
	scanf("%s",ch);
	reverse(ch);
	return 0;
}
void reverse(char*ch){
    int lenght=strlen(ch);
    for(int i=0,j=lenght-1;i<j;i++,j--){
        int temp=ch[i];
        ch[i]=ch[j];
        ch[j]=temp;
    }
    
   printf("Reverse string is: %s",ch);
}