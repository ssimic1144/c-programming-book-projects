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
        digit_seen[digit] = true;
        if ( digit_seen[digit] ){
            repeated_digits[digit]++;
        }
        n /= 10;
    }

    printf("Digit : \t");
    for(int i=0; i<10; i++){
        printf("%d ", i);
    }
    printf("\n");

    printf("Occurrences : \t");
    for(int i = 0; i < 10; i++){
        printf("%d ", repeated_digits[i]); 
    }

    printf("\n");


    return 0;
}
