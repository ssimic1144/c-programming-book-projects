#include <stdio.h>

int main(void){

    float number, max;

    max = 0.0f;

    do{
        printf("Enter a number : ");
        scanf("%f", &number);
        if (number > max){
            max = number;
        }
    }while(number != 0);

    printf("The largest number entered was %.2f\n", max);
    return 0;
}
