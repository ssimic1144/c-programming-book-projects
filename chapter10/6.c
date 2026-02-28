/* Program assume single digit number and will not work
 * properly with multiple digits numbers.
 *
 * Programming project from the book 
 * didn't require to write multiple digit numbers.
 *
 * To implement multple digits numbers this program requires
 * additional work.
 ************************************************* */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

int main(void){
    int result, top_operand, bottom_operand;

    while(1){
        char c = 0;
        printf("Enter an RPN expression : ");
        while(c != '='){
            scanf(" %c", &c);
            switch(c){
                case '0': case '1': case '2':
                case '3': case '4': case '5':
                case '6': case '7': case '8': case '9':
                    push((c-'0'));
                    break;
                case '+':
                    top_operand = pop();
                    bottom_operand = pop();
                    result = bottom_operand + top_operand;
                    push(result);
                    break;
                case '-':
                    top_operand = pop();
                    bottom_operand = pop();
                    result = bottom_operand - top_operand;
                    push(result);
                    break;
                case '*':
                    top_operand = pop();
                    bottom_operand = pop();
                    result = bottom_operand * top_operand;
                    push(result);
                    break;
                case '/':
                    top_operand = pop();
                    bottom_operand = pop();
                    result = bottom_operand / top_operand;
                    push(result);
                    break;
                case 'q': case 'Q':
                    exit(EXIT_SUCCESS);
            }
        }
        printf("Value of expression : %d\n", pop());
        make_empty();
    }
    return 0;
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

void push(int i){
    if(is_full()){
        printf("Expression is too complex.\n");
        exit(EXIT_FAILURE);
    } else {
        contents[top++] = i;
    }
}

int pop(void){
    if(is_empty()){
        printf("Not enough operands in expression.\n");
        exit(EXIT_FAILURE);
    } else {
        return contents[--top];
    }
}
