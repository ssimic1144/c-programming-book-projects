#include <stdio.h>

float calculate_total_tax(float income);

int main(void){

    float income;

    printf("Enter the amount of taxable income : ");
    scanf("%f", &income);

    float total_tax = calculate_total_tax(income);

    printf("Total tax due is : %.2f\n", total_tax);

    return 0;
}

float calculate_total_tax(float income){
    float total;
    if (income < 750){
        total = income * 0.01;
    } else if (income < 2250){
        total = 7.50f + 0.02 * income;
    } else if (income < 3750){
        total = 37.50f + 0.03 * income;
    } else if (income < 5250){
        total = 82.50f + 0.04 * income;
    } else if (income < 7000){
        total = 142.50f + 0.05 * income;
    } else {
        total = 230.00f + 0.06 * income;
    }
    return total;
}
