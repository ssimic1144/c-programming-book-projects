#include <stdio.h>

int main(void){
    int x;

    printf("Enter value for X : ");
    scanf("%d", &x);

    int result = ((((3*x+2)*x-5)*x-1)*x+7)*x-6;

    printf("Result of polynomial ((((3*x+2)*x-5)*x-1)*x+7)*x-6 = %d\n", result);
    return 0;
}