#include <stdio.h>

int main(void){
    int dollars;
    printf("Enter a dollar amount : ");
    scanf("%d", &dollars);

    int twenty,ten,five,one;
    twenty = dollars / 20;
    printf("$20 bills : %d\n", twenty);
    ten = (dollars - twenty * 20) / 10;
    printf("$10 bills : %d\n", ten);
    five = (dollars - twenty * 20 - ten * 10) / 5;
    printf("$5 bills : %d\n", five);
    one = dollars - twenty * 20 - ten * 10 - five * 5;
    printf("$1 bills : %d\n", one);
    return 0;
}