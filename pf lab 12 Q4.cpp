#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 10001

int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N;
        printf("Enter the number of elements: ");
        scanf("%d", &N);

        int *A = (int *)malloc(N * sizeof(int));
        if (A == NULL) {
            printf("Memory allocation failed. Program terminated.\n");
            return 1;
        }

        int freq[MAX_VALUE + 1] = {0};

        printf("Enter the elements of the sequence: ");
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            freq[A[i]]++;
        }

        int maxFrequency = 0;
        int result = MAX_VALUE + 1;

        for (int i = 1; i <= MAX_VALUE; i++) {
            if (freq[i] > maxFrequency || (freq[i] == maxFrequency && i < result)) {
                maxFrequency = freq[i];
                result = i;
            }
        }

        printf("Number with highest frequency: %d\n", result);

        free(A);
    }

    return 0;
}
