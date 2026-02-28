#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void){
    int numerator, denominator, reduced_numerator, reduced_denominator;
    
    printf("Enter a fraction : ");
    scanf("%d/%d", &numerator, &denominator);

    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);

    printf("In lowest terms : %d/%d\n", reduced_numerator, reduced_denominator);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator){
    int remainder;
    int m,n;

    m = numerator;
    n = denominator;

    for(;;){
        if(n == 0){
            remainder = m;
            break;
        }

        remainder = m % n;
        m = n;
        n = remainder;

    }

    *reduced_numerator = numerator / remainder;
    *reduced_denominator = denominator / remainder;
}

