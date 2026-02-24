#include <stdio.h>

int main(void){

    float income;

    printf("Enter the amount of taxable income : ");
    scanf("%f", &income);

    float total_tax;

    if (income < 750){
        total_tax = income * 0.01;
    } else if (income < 2250){
        total_tax = 7.50f + 0.02 * income;
    } else if (income < 3750){
        total_tax = 37.50f + 0.03 * income;
    } else if (income < 5250){
        total_tax = 82.50f + 0.04 * income;
    } else if (income < 7000){
        total_tax = 142.50f + 0.05 * income;
    } else {
        total_tax = 230.00f + 0.06 * income;
    }

    printf("Total tax due is : %.2f\n", total_tax);

    return 0;
}
