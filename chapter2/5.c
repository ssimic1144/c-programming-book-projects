#include <stdio.h>

int main(void){
    int x;

    printf("Enter value for X : ");
    scanf("%d", &x);

    int result = 3*(x*x*x*x*x) + 2*(x*x*x*x) - 5*(x*x*x) - (x*x) + 7*x - 6;

    printf("Result of polynomial 3x^5+2x^4-5x^3-x^2+7x-6 = %d\n", result);
    return 0;
}