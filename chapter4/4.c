#include <stdio.h>

int main(void){
    int number;

    printf("Enter a number between 0 and 32767 : ");
    scanf("%d", &number);

    int octal;
    octal = number % 8;
    number /= 8;

    octal += (number % 8) * 10;
    number /= 8;

    octal += (number % 8) * 100;
    number /= 8;

    octal += (number % 8) * 1000;
    number /= 8;

    octal += (number % 8) * 10000;

    printf("In octal, your number is %.5d\n", octal);

    return 0;
}