#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	printf("enter the total number of elements:\n");
	scanf("%d", &n);
	int *arr = (int*)malloc(n*sizeof(int));
	printf("enter the values for each input:\n");
	for(int i=0;i <n; i++){
		scanf("%d", &arr[i]);
	}
	int largest = arr[0];
	for(int i=0; i<n; i++){
		if(arr[i]>largest){
			largest = arr[i];
		}
	}
	printf("the largest value is: %d", largest);
}