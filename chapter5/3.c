#include <stdio.h>

int main(void){
    float rival_commission, commission, value, price_per_share;
    int n_shares;

    printf("Enter the number of shares : ");
    scanf("%d", &n_shares);
    printf("Enter the price per share : ");
    scanf("%f", &price_per_share);

    value = n_shares * price_per_share;

    if(value < 2500.00f){
        commission = 30 + 0.017f * value;
    } else if (value < 6250.00f){
        commission = 56 + 0.0066f * value;
    } else if (value < 20000.00f){
        commission = 76 + 0.0034f * value;
    } else if (value < 50000.00f){
        commission = 100 + 0.0022f * value;
    } else if (value < 500000.00f){
        commission = 155 + 0.0011f * value;
    } else {
        commission = 255 + 0.0009f * value;
    }

    printf("Commission : $%.2f\n", commission);


    if (n_shares  < 2000){
        rival_commission = 33 + 0.03 * n_shares;
    } else {
        rival_commission = 33 + 0.02 * n_shares;
    }

    printf("Rival commission : $%.2f\n", rival_commission);

    return 0;
}
