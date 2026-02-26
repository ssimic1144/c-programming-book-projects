#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);

int main(void){
    char c, popped;
    printf("Enter parentheses and/or braces : ");
    while( (c=getchar()) != '\n' ){
        switch(c){
            case '(': case '{': case '[':
                push(c);
                break;
            case ')':
                popped = pop();
                if(popped != '('){
                    printf("Parentheses/braces aren't nested properly\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case '}':
                popped = pop();
                if(popped != '{'){
                    printf("Parentheses/braces aren't nested properly\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case ']':
                popped = pop();
                if(popped != '['){
                    printf("Parentheses/braces aren't nested properly\n");
                    exit(EXIT_FAILURE);
                }
                break;

        }
    }

    if(is_empty()){
        printf("Parentheses/braces are nested properly\n");
        exit(EXIT_SUCCESS);

    }else{
        printf("Parentheses/braces aren't nested properly\n");
        exit(EXIT_FAILURE);
    }
}

void make_empty(void){
    top = 0;
}

bool is_empty(void){
    return top == 0;
}

bool is_full(void){
    return top == STACK_SIZE;
}

void push(char i){
    if(is_full()){
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    } else {
        contents[top++] = i;
    }
}

char pop(void){
    if(is_empty()){
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    } else {
        return contents[--top];
    }
}
