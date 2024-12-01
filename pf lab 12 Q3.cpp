#include <stdio.h>
#include <stdlib.h>
int main()
{
  float *arr;
  int capacity = 4;
  int i = 0;
  arr = (float*)malloc(capacity * sizeof(float));
  int choice;
  do
  {
    printf("1. add a new number:\n");
    printf("2. display all the numbers:\n");
    printf("3. remove the last number from the array:\n");
    printf("4. reduce the memory size:\n");
    printf("5. exit\n");
    printf("enter a choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
     if (i == capacity) {
                capacity *= 2;
                arr = (float *)realloc(arr, capacity * sizeof(float));
                if (arr == NULL) {
                    printf("Memory reallocation failed\n");
                    return 1;
                }
                printf("Array capacity doubled to %d\n", capacity);
            }
            printf("Enter a number to add: ");
          scanf("%f", &arr[i]); 
            i++;
            break;
    case 2:
      if (i == 0)
      {
        printf("no elements to display\n");
      }
      else
      {
      	printf("elements in the array:\n");
        for (int j = 0; j < i; j++)
        {
          printf("%f", arr[j]);
        }
      }
      break;
    case 3:
      if (i == 0)
      {
        printf("no elements to remove\n");
      }
      else
      {
        i--;
        printf("last element removed\n");
      }
      break;
    case 4:
    if (i > 0) {
                capacity = i;
                arr = (float *)realloc(arr, capacity * sizeof(float));
                if (arr == NULL) {
                    printf("Memory reallocation failed\n");
                    return 1;
                }
                printf("Array size reduced to fit %d elements.\n", i);
            } else {
                printf("The array is empty, no need to reduce memory.\n");
            }
            break;
    case 5:
      free(arr);
      printf("Memory freed, exiting program.\n");
      return 0;
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 5);
}