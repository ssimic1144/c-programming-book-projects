#include <stdio.h>

#define SIZE 5

int main(void){
    int matrix[SIZE][SIZE];
    int n[SIZE];

    for(int i=0; i < SIZE; i++){
        printf("Enter row %d : ", i+1);
        scanf("%d%d%d%d%d", &n[0],&n[1],&n[2],&n[3],&n[4]);
        for(int j=0; j<SIZE; j++){
            matrix[i][j] = n[j];
        }
    }

    int row_sum[SIZE] = {0};
    int column_sum[SIZE] = {0};

    for(int i = 0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            row_sum[i] += matrix[i][j];
        }
    }

    printf("Row totals : ");
    for(int i=0; i < SIZE; i++){
        printf("%d ", row_sum[i]);
    }
    printf("\n");

    for(int i = 0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            column_sum[i] += matrix[j][i];
        }
    }

    printf("Column totals : ");
    for(int i=0; i < SIZE; i++){
        printf("%d ", column_sum[i]);
    }
    printf("\n");

    return 0;
}
