#include <stdio.h>

int main(void){
    int number;
    
    printf("Enter a two-digit number : ");
    scanf("%d", &number);

    int d1,d2;
    d1 = number / 10;
    d2 = number % 10;

    printf("The reversal is : %d%d\n", d2,d1);

    return 0;
}