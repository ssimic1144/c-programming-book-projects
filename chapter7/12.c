#include <stdio.h>

int main(void){
    float a, b, c; 
    char op1, op2;

    printf("Enter an expression : ");
    scanf("%f%c%f%c%f", &a, &op1, &b, &op2, &c);

    float result;

    switch(op1){
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    }

    switch(op2){
        case '+':
            result += c;
            break;
        case '-':
            result -= c;
            break;
        case '*':
            result *= c;
            break;
        case '/':
            result /= c;
            break;
    }

    printf("Value of expression : %.1f\n", result);
    return 0;
}
