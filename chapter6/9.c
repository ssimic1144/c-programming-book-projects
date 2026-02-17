#include <stdio.h>

int main(void){

    float loan, rate, payment;

    printf("Enter amount of loan : ");
    scanf("%f", &loan);

    printf("Enter interest rate : ");
    scanf("%f", &rate);

    float monthly_rate = (rate/100) / 12;

    printf("Enter monthly payment : ");
    scanf("%f", &payment);

    int number;

    printf("Enter number of payments : ");
    scanf("%d", &number);

    for(int i = 1; i <= number; i++){
        loan = loan + (loan * monthly_rate) - payment;
        printf("Balance remaining after payment number %d : $%.2f\n", i, loan);
    }


    return 0;
}
