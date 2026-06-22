/*
 * Name: ex-08.c
 * Author: Edoardo Paggi
 * Task: modify Programming Project 7 to print the scores of five students on 
         five quizzes. The program must then calculate the total and average 
         scores for each student. The average, maximum, and minimum scores for 
         each quiz must also be calculated.
*/

#include <stdio.h>

#define N 5

int main(void) {

    double scores[N][N] = {{0}};
    double sum = 0, average_student = 0, min = 999999, max = 0, 
           average_quiz = 0;

    for (int i = 0; i < N; i++) {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            scanf("%lf", &scores[i][j]);
        }
    }

    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("Student %d score: ", i + 1);
        for (int j = 0; j < N; j++) {
            sum += scores[i][j];
        }
        average_student = (double) sum / N;
        printf("%lg %lg\n", sum, average_student);
        sum = 0;
    }

    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("Quiz %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            if (scores[j][i] < min)
                min = scores[j][i];

            if (scores[j][i] > max)
                max = scores[j][i];

            sum += scores[j][i];
        }
        average_quiz = (double) sum / N;
        printf("%lg %lg %lg\n", min, max, average_quiz);
        sum = 0;
        min = 99999;
        max = 0;
    }
    printf("\n");

    return 0;
}