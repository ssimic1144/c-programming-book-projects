#include <stdio.h>

#define SIZE 5

int main(void){
    int matrix[SIZE][SIZE];
    int n[SIZE];

    for(int i=0; i < SIZE; i++){
        printf("Enter five quiz grades for student %d : ", i+1);
        scanf("%d%d%d%d%d", &n[0],&n[1],&n[2],&n[3],&n[4]);
        for(int j=0; j<SIZE; j++){
            matrix[i][j] = n[j];
        }
    }

    int student_t_score[SIZE] = {0};
    float student_a_score[SIZE] = {0};

    for(int i=0; i <SIZE; i++){
        for(int j=0; j < SIZE; j++){
            student_t_score[i] += matrix[i][j];
            student_a_score[i] += (matrix[i][j] / (float) SIZE);
        }
    }

    for(int i=0; i < SIZE; i++){
        printf("Student %d total score : %d\n", i+1, student_t_score[i]);
        printf("Student %d average score : %.2f\n", i+1, student_a_score[i]);
    }

    float quiz_a_score[SIZE] = {0};
    int quiz_high_score = 0;
    int quiz_low_score = 100; 

    for(int i= 0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            quiz_a_score[i] += (matrix[j][i] / (float) SIZE);
            if(matrix[j][i] < quiz_low_score){
                quiz_low_score = matrix[j][i];
            }
            if(matrix[j][i] > quiz_high_score){
                quiz_high_score = matrix[j][i];
            }
        }
    }

    for(int i=0; i < SIZE; i++){
        printf("Quiz %d average score : %f\n", i+1, quiz_a_score[i]);
    }

    printf("Quiz high score : %d\n", quiz_high_score);
    printf("Quiz low score : %d\n", quiz_low_score);

    return 0;
}
