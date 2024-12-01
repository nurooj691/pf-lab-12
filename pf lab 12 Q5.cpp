#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *size, int *capacity, int x, int p) {
    if (*size == *capacity) {
        *capacity *= 2;
        *arr = (int *)realloc(*arr, *capacity * sizeof(int));
        if (*arr == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    for (int i = *size; i >= p; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    (*arr)[p - 1] = x;
    (*size)++;
}

void deletee(int **arr, int *size, int p) {
    if (p < 1 || p > *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = p - 1; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    (*size)--;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int *arr = (int *)malloc(N * sizeof(int));
        int size = N, capacity = N;

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        char operation[20];
        while (1) {
            scanf(" %[^\n]", operation);  
            if (operation[0] == '\0') break;  

            int x, p;
            if (operation[0] == 'I') {
                sscanf(operation, "I %d %d", &x, &p);
                if (p < 1 || p > size + 1) {
                    printf("Invalid position for insertion!\n");
                    continue;
                }
                insert(&arr, &size, &capacity, x, p);
            } else if (operation[0] == 'D') {
                sscanf(operation, "D %d", &p);
                if (p < 1 || p > size) {
                    printf("Invalid position for deletion!\n");
                    continue;
                }
                deletee(&arr, &size, p);
            } else {
                printf("Invalid operation!\n");
            }
        }

        printArray(arr, size);
        free(arr);
    }

    return 0;
}
