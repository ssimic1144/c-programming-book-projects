#include <stdio.h>

int main(void){
    int number;
    
    printf("Enter a three-digit number : ");
    scanf("%d", &number);

    int d1,d2,d3;
    d1 = number / 100;
    number %= 100;
    d2 = number / 10;
    d3 = number % 10;

    printf("The reversal is : %d%d%d\n", d3,d2,d1);

    return 0;
}