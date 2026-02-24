#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


void print_array(char walk[10][10]);
void generate_random_walk(char walk[10][10]);

int main(void){
    char matrix[10][10];
    srand( (unsigned) time(NULL) );

    generate_random_walk(matrix);
    print_array(matrix);

    return 0;
}

void generate_random_walk(char walk[10][10]){
    for(int i=0; i < 10; i++){
        for(int j=0; j < 10; j++){
            walk[i][j] = '.';
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

    walk[current_row][current_column] = letters[0];

    for(int l=1; l < 26; l++){
        position = rand() % 4;
        found = false;
        switch(position){
            case 0:
                /*up*/
                if( current_row - 1 >= 0 && walk[current_row-1][current_column] == '.' ){
                    current_row--;
                    walk[current_row][current_column] = letters[l];
                    found = true;
                }
                break;
            case 1:
                /*down*/
                if( current_row + 1 < 10 && walk[current_row+1][current_column] == '.' ){
                    current_row++;
                    walk[current_row][current_column] = letters[l];
                    found = true;
                }
                break;
            case 2:
                /*left*/
                if( current_column - 1 >= 0 && walk[current_row][current_column-1] == '.' ){
                    current_column--;
                    walk[current_row][current_column] = letters[l];
                    found = true;
                }
                break;
            case 3:
                /*right*/
                if( current_column + 1 < 10 && walk[current_row][current_column+1] == '.' ){
                    current_column++;
                    walk[current_row][current_column] = letters[l];
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
                        if( current_row - 1 >= 0 && walk[current_row-1][current_column] == '.' ){
                            current_row--;
                            walk[current_row][current_column] = letters[l];
                            found = true;
                        }
                        break;
                    case 1:
                        /*down*/
                        if( current_row + 1 < 10 && walk[current_row+1][current_column] == '.' ){
                            current_row++;
                            walk[current_row][current_column] = letters[l];
                            found = true;
                        }
                        break;
                    case 2:
                        /*left*/
                        if( current_column - 1 >= 0 && walk[current_row][current_column-1] == '.' ){
                            current_column--;
                            walk[current_row][current_column] = letters[l];
                            found = true;
                        }
                        break;
                    case 3:
                        /*right*/
                        if( current_column + 1 < 10 && walk[current_row][current_column+1] == '.' ){
                            current_column++;
                            walk[current_row][current_column] = letters[l];
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
}

void print_array(char walk[10][10]){
    for(int i=0; i < 10; i++){
        for(int j=0; j < 10; j++){
            printf("%c ",walk[i][j]);
        }
        printf("\n");
    }
}
