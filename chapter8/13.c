#include <stdio.h>

int main(void){
    char c, last_c, name_flag, surname_flag; 
    char surname[20] = {0};
    int counter = 0;

    name_flag = 0;
    surname_flag = 0;

    printf("Enter a first and last name : ");
    while ( (c=getchar()) != '\n'){
        if (c == ' '){
            last_c = c;
            continue;
        }
        if ( c != ' ' && name_flag == 0){
            name_flag  = c;
            last_c = c;
            continue;
        }
        if ( c != ' ' && last_c == ' ' && surname_flag == 0){
            surname_flag = 1;
            surname[counter++] = c;
            continue;
        }
        if (surname_flag){
            surname[counter++] = c;
        }
    }

    counter = 0;

    while( surname[counter] != 0){
        printf("%c", surname[counter++]);
    }
    printf(", %c.\n", name_flag);
    return 0;
}
