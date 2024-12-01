#include<stdio.h>
#include<stdlib.h>
int main(){
	int *arr;
	arr = (int*)malloc(5*sizeof(int));
	printf("enter the elements of arry:\n");
	for(int i=0; i<5; i++){
		scanf(" %d", &arr[i]);
		}
	for(int i=0; i<5; i++){
		if(arr[i]%2!=0){
			arr[i]-=1;
		}
	}
	for(int i=0; i<5; i++){
		printf(" %d", arr[i]);
}
}