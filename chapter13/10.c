#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 50

void reverse_name(char *name);

int main(void){
    char c;
    char name[SIZE];
    int i = 0;

    printf("Enter a first and last name : ");
    while ( (c=getchar()) != '\n'){
        name[i++] = c;
    }
    name[i] = '\0';

    reverse_name(name);

    printf("%s\n", name);
    return 0;
}

void reverse_name(char *name){
    char first_name[3];
    char last_name[SIZE];
    bool first = true;
    bool last = false;
    int i = 0;
    char *c = name;

    while(*c){
        if(isalpha(*c) && first){
            first_name[0] = *c;
            first_name[1] = '.';
            first_name[2] = '\0';
            first = false;
        }
        if(!isalpha(*c) && !first){
            last = true;
        }
        if(isalpha(*c) && last){
            last_name[i++] = *c;
        }
        c++;
    }
    last_name[i++] = ',';
    last_name[i++] = ' ';
    last_name[i]= '\0';

    strcpy(name, last_name);
    strcat(name, first_name);

}
