#include <stdio.h>

int main(void){
    char c, last_c, name, surname; 

    name = 0;
    surname = 0;

    printf("Enter a first and last name : ");
    while ( (c=getchar()) != '\n'){
        if (c == ' '){
            last_c = c;
            continue;
        }
        if ( c != ' ' && name == 0){
            name  = c;
            last_c = c;
            continue;
        }
        if ( c != ' ' && last_c == ' ' && surname == 0){
            surname = 1;
            printf("%c", c);
            continue;
        }
        if (surname){
            printf("%c", c);
        }
    }

    printf(", %c.\n", name);
    return 0;
}
