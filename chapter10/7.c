#include <stdio.h>

#define MAX_DIGITS 10

const char segments[10][7] = {
    {'_','|','|','_','|','|',' '}, /*0*/
    {' ','|','|',' ',' ',' ',' '}, /*1*/
    {'_','|',' ','_','|',' ','_'}, /*2*/
    {'_','|','|','_',' ',' ','_'}, /*3*/
    {' ','|','|',' ',' ','|','_'}, /*4*/
    {'_',' ','|','_',' ','|','_'}, /*5*/
    {'_',' ','|','_','|','|','_'}, /*6*/
    {'_','|','|',' ',' ',' ',' '}, /*7*/
    {'_','|','|','_','|','|','_'}, /*8*/
    {'_','|','|','_',' ','|','_'}, /*9*/
};
char digits[3][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void){
    char c;
    int digit;
    int position = 0;

    clear_digits_array();

    printf("Enter a number : ");
    while( c != '\n' ){
        scanf("%c", &c);
        switch(c){
            case '0': case '1': case '2':
            case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                if(position < MAX_DIGITS){
                    digit = c - '0';
                    process_digit(digit, position);
                    position++;
                }
                break;
        }
    }
    print_digits_array();
    return 0;
}

void clear_digits_array(void){
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < MAX_DIGITS * 4; column++){
            digits[row][column] = ' ';
        }
    }
}

void process_digit(int digit, int position){
    int starting_position = position * 4;

    digits[0][starting_position + 1] = segments[digit][0];

    digits[1][starting_position + 0] = segments[digit][5];
    digits[1][starting_position + 1] = segments[digit][6];
    digits[1][starting_position + 2] = segments[digit][1];

    digits[2][starting_position + 0] = segments[digit][4];
    digits[2][starting_position + 1] = segments[digit][3];
    digits[2][starting_position + 2] = segments[digit][2];
}

void print_digits_array(){
    for(int row = 0; row < 3; row++) {
        for(int column = 0; column < MAX_DIGITS * 4; column++){
            printf("%c",digits[row][column]);
        }
        printf("\n");
    }
}
