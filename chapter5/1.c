#include <stdio.h>

int main(void){
    int number;

    printf("Enter a number : ");
    scanf("%d", &number);

    int n;

    if ( number <= 9 ){
        n = 1;
    } else if ( number <= 99 ){
        n = 2;
    } else if ( number <= 999 ){
        n = 3;
    } else {
        n = 4;
    }

    printf("The number %d has %d digits.\n", number, n);

    return 0;
}