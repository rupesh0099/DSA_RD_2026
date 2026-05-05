#include<stdio.h>
void add(int*,int);
int main(){
	int arr[5],sum=0;
	printf("Enter the array elements:\n");
	for(int i=0;i<5;i++){
	scanf("%d",&arr[i]);
	}
	add(arr,sum);
	return 0;
}

void add(int *arr,int sum){
    for(int i=0;i<5;i++){
        sum=sum+arr[i];
       }
    printf("Sum of all Element is:%d",sum);
}