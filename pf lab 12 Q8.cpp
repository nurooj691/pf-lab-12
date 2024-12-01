#include <stdio.h>
#include <stdlib.h>
int main(){
  int points;
  printf("enter the number of points:\n");
  scanf("%d", &points);
  int sum=0;
  int *arr = (int*)malloc(points*sizeof(int));
  if (arr == NULL) {
        printf("Memory allocation failed. Program terminated.\n");
        return 1;
    }
  for (int i = 0; i < points; i++)
  {
   printf("enter the fee for point: %d\n", i+1);
   scanf("%d", &arr[i]);
   if (arr[i]<0)
   {
    printf("invalid fee. please enter correct fee\n");
    i--;
    continue;
   }
   sum +=arr[i];
  }
  printf("total profit: %d", sum);
  free(arr);
}