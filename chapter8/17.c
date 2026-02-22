#include <stdio.h>

int main(void){
    int size;

    printf("This program creates a magic square of specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square : ");
    scanf("%d", &size);

    int matrix[size][size];

    /* fill matrix with 0s */
    for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            matrix[i][j] = 0;
        }
    }

    int current_row, current_column;

    for(int i=1; i <= (size*size); i++){
        if(i == 1){
            current_row = 0;
            current_column = size / 2;
            matrix[current_row][current_column] = i;
            continue;
        }
        /* if first row*/
        if(current_row - 1 < 0){
            current_row = size-1; /* put on last row */
            /* if last column */
            if(current_column + 1 > size - 1){
                /* go to first column */
                current_column = 0;
                /* if position empty */
                if( matrix[current_row][current_column] == 0 ){
                    matrix[current_row][current_column] = i;
                } else{
                    /* special case of top right corner*/
                    /* we need to put it below starting point */
                    /* go back to last column */
                    current_column = size - 1;
                    /* it's 1 below first row */
                    current_row = 0 + 1;
                    matrix[current_row][current_column] = i;
                }
            } else {
                /* it's not last column */
                current_column++;
                /* check if empty */ 
                if( matrix[current_row][current_column] == 0 ){
                    matrix[current_row][current_column] = i;
                } else {
                    /* it's not empty */
                    /* go back to previous column */ 
                    current_column--;
                    /* go back to previous row */
                    current_row++;
                    /* we need to put it below starting point */
                    if( current_row + 1 > size - 1 ){
                        current_row = 0;
                        matrix[current_row][current_column] = i;
                    } else {
                        /* go down one row */
                        current_row++;
                        matrix[current_row][current_column] = i;
                    }
                }
            }
        } else{
            /* go one row up */
            current_row--;
            /* if last column */ 
            if(current_column + 1 > size - 1){
                /* go to first column */
                current_column = 0;
                /* if position empty */
                if( matrix[current_row][current_column] == 0 ){
                    matrix[current_row][current_column] = i;
                } else{
                    /* if not empty */
                    /* go back to last column */
                    current_column = size - 1;
                    /* check if last row */ 
                    if( current_row + 1 > size - 1 ){
                        current_row = 0;
                        matrix[current_row][current_column] = i;
                    } else {
                        current_row++;
                        matrix[current_row][current_column] = i;
                    }
                }
            } else {
                /* it's not last column */
                current_column++;
                /* check if empty */ 
                if( matrix[current_row][current_column] == 0 ){
                    matrix[current_row][current_column] = i;
                } else {
                    /* it's not empty */
                    /* go back to previous column */ 
                    current_column--;
                    /* go back to previous row */
                    current_row++;
                    /* we need to put it below starting point */
                    if( current_row + 1 > size - 1 ){
                        current_row = 0;
                        matrix[current_row][current_column] = i;
                    } else {
                        /* go down one row */
                        current_row++;
                        matrix[current_row][current_column] = i;
                    }
                }
            }
            
        }
    }

    for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            printf(" %2d ",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
