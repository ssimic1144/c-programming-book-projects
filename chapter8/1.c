#include <stdio.h>
#include <stdbool.h>

int main(void){
    bool digit_seen[10] = {false};
    int repeated_digits[10] = {0};
    int digit;
    long n;

    printf("Enter a number : ");
    scanf("%ld", &n);

    while( n > 0 ){
        digit = n % 10;
        if ( digit_seen[digit] ){
            repeated_digits[digit]++;
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    printf("Repeated digit (s) : ");
    for(int i = 0; i < 10; i++){
        if( repeated_digits[i] > 0 ){
            printf("%d ", i); 
        }
    }

    printf("\n");


    return 0;
}

