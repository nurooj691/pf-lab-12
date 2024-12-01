#include<stdio.h>
#include<Stdlib.h>
int main(){
	int rows, cols;
	int **arr;
	printf("enter the number of rows:\n");
	scanf("%d", &rows);
	printf("enter the number of colums:\n");
	scanf("%d", &cols);
	arr = (int**)malloc(rows*sizeof(int*));
	if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
	for(int i=0; i<rows; i++){
		arr[i] = (int*)malloc(cols*sizeof(int*));
		if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
	}
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (i + 1) * (j + 1); 
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
	int r, c, newvalue;
	printf("enter the row number of value to change:\n");
	scanf("%d", &r);
	printf("enter the column number of value to change:\n");
	scanf("%d", &c);
	printf("enter new value:\n");
	scanf("%d", &newvalue);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(arr[i][j]==arr[r][c]){
			arr[i][j]=newvalue;
			}
		}
	}
	printf("Updated array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        free(arr[i]); 
    }
    free(arr); 
    printf("Memory freed successfully.\n");

    return 0;

	
	
}