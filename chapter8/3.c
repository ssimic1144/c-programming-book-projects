#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int main(void){
    bool digit_seen[10] = {false};
    int digit;
    long n;
    long array_of_n[SIZE];
    int counter = 0;

    for(;;){
        printf("Enter a number (if you enter number <= 0 program ends): ");
        scanf("%ld", &n);
        if( n <= 0){
            break;
        }
        array_of_n[counter] = n;
        counter++;
    }
    for(int i=0; i < counter; i++){
        while( array_of_n[i] > 0 ){
            digit = array_of_n[i] % 10;
            if ( digit_seen[digit] ){
                break;
            }
            digit_seen[digit] = true;
            array_of_n[i] /= 10;
        }
        if( array_of_n[i] > 0){
            printf("Repeated digit\n");
        }else{
            printf("No repeated digit\n");
        }
    }

    return 0;
}

