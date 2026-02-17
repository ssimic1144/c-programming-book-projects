#include <stdio.h>

int main(void){
    int number;

    printf("Enter a number : ");
    scanf("%d", &number);

    printf("Reversed number is : ");

    int last_digit;
    
    do{
        last_digit = number % 10;
        printf("%d", last_digit);
        number /= 10;
    }while(number!=0);

    printf("\n");

    return 0;
}
