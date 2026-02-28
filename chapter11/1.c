#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void){
    int dollars;
    int twenty,ten,five,one;
    printf("Enter a dollar amount : ");
    scanf("%d", &dollars);

    pay_amount(dollars, &twenty, &ten, &five, &one);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){
    *twenties = dollars / 20;
    printf("$20 bills : %d\n", *twenties);
    *tens = (dollars - *twenties * 20) / 10;
    printf("$10 bills : %d\n", *tens);
    *fives = (dollars - *twenties * 20 - *tens * 10) / 5;
    printf("$5 bills : %d\n", *fives);
    *ones = dollars - *twenties * 20 - *tens * 10 - *fives * 5;
    printf("$1 bills : %d\n", *ones);
}
