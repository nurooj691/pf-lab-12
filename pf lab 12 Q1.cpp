#include <stdio.h>
#include <stdlib.h>
int main() {
    int numStudents, i, j;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    int *numGrades = (int *)malloc(numStudents * sizeof(int));
    if (numGrades == NULL) {
        printf("Memory allocation failed for numGrades.\n");
        return 1;
    }
    int **grades = (int **)malloc(numStudents * sizeof(int *));
    if (grades == NULL) {
        printf("Memory allocation failed for grades.\n");
        free(numGrades);
        return 1;
    }
    for (i = 0; i < numStudents; i++) {
        printf("Enter the number of grades for student %d: ", i + 1);
        scanf("%d", &numGrades[i]);
        grades[i] = (int *)malloc(numGrades[i] * sizeof(int));
        if (grades[i] == NULL) {
            printf("Memory allocation failed for student %d's grades.\n", i + 1);
            for (j = 0; j < i; j++) {
                free(grades[j]); 
            }
            free(grades);
            free(numGrades);
            return 1;
        }
        printf("Enter grades for student %d: ", i + 1);
        for (j = 0; j < numGrades[i]; j++) {
            scanf("%d", &grades[i][j]);
        }
    }
    printf("\nGrades of each student:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student %d: ", i + 1);
        for (j = 0; j < numGrades[i]; j++) {
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < numStudents; i++) {
        free(grades[i]);
    }
    free(grades);
    free(numGrades);

    return 0;
}
