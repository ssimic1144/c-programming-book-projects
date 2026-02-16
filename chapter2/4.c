#include <stdio.h>

#define TAX 0.05

int main(void){
    float value;
    printf("Enter an amount : ");
    scanf("%f", &value);

    printf("With tax added : $%.2f\n", value + (value * TAX));

    return 0;
}