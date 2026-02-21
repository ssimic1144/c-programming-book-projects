#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void){
    char matrix[SIZE][SIZE];
    srand( (unsigned) time(NULL) );

    for(int i=0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            matrix[i][j] = '.';
        }
    }

    char letters[26];
    for(char i = 'A', j=0; i <= 'Z'; i++, j++){
       letters[j] = i; 
    }

    int position;
    int possibilities[] = {0,1,2,3};
    bool found = false;
    int current_row = 0;
    int current_column = 0;

    matrix[current_row][current_column] = letters[0];

    for(int l=1; l < 26; l++){
        position = rand() % 4;
        found = false;
        switch(position){
            case 0:
                /*up*/
                if( current_row - 1 >= 0 && matrix[current_row-1][current_column] == '.' ){
                    current_row--;
                    matrix[current_row][current_column] = letters[l];
                    found = true;
                }
                break;
            case 1:
                /*down*/
                if( current_row + 1 < 10 && matrix[current_row+1][current_column] == '.' ){
                    current_row++;
                    matrix[current_row][current_column] = letters[l];
                    found = true;
                }
                break;
            case 2:
                /*left*/
                if( current_column - 1 >= 0 && matrix[current_row][current_column-1] == '.' ){
                    current_column--;
                    matrix[current_row][current_column] = letters[l];
                    found = true;
                }
                break;
            case 3:
                /*right*/
                if( current_column + 1 < 10 && matrix[current_row][current_column+1] == '.' ){
                    current_column++;
                    matrix[current_row][current_column] = letters[l];
                    found = true;
                }
                break;
        }
        if(!found){
            for(int p=0; p < 4; p++){
                if(p == position){
                    continue;
                } 
                switch(p){
                    case 0:
                        /*up*/
                        if( current_row - 1 >= 0 && matrix[current_row-1][current_column] == '.' ){
                            current_row--;
                            matrix[current_row][current_column] = letters[l];
                            found = true;
                        }
                        break;
                    case 1:
                        /*down*/
                        if( current_row + 1 < 10 && matrix[current_row+1][current_column] == '.' ){
                            current_row++;
                            matrix[current_row][current_column] = letters[l];
                            found = true;
                        }
                        break;
                    case 2:
                        /*left*/
                        if( current_column - 1 >= 0 && matrix[current_row][current_column-1] == '.' ){
                            current_column--;
                            matrix[current_row][current_column] = letters[l];
                            found = true;
                        }
                        break;
                    case 3:
                        /*right*/
                        if( current_column + 1 < 10 && matrix[current_row][current_column+1] == '.' ){
                            current_column++;
                            matrix[current_row][current_column] = letters[l];
                            found = true;
                        }
                        break;
                }
                if(found){
                    break;
                }
            }
        }
        if(!found){
            break;
        }
    }

    for(int i=0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            printf("%c ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
