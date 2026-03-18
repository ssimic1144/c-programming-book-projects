#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void){
    char c, popped;
    Stack s;

    s = create();

    printf("Enter parentheses and/or braces : ");
    while( (c=getchar()) != '\n' ){
        switch(c){
            case '(': case '{': case '[':
                push(s, c);
                break;
            case ')':
                popped = pop(s);
                if(popped != '('){
                    printf("Parentheses/braces aren't nested properly\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case '}':
                popped = pop(s);
                if(popped != '{'){
                    printf("Parentheses/braces aren't nested properly\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case ']':
                popped = pop(s);
                if(popped != '['){
                    printf("Parentheses/braces aren't nested properly\n");
                    exit(EXIT_FAILURE);
                }
                break;

        }
    }

    if(is_empty(s)){
        printf("Parentheses/braces are nested properly\n");
        exit(EXIT_SUCCESS);

    }else{
        printf("Parentheses/braces aren't nested properly\n");
        exit(EXIT_FAILURE);
    }
}
