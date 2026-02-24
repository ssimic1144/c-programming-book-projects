#include <stdio.h>

int compute_polynomial(int number);
int power(int number, int to);

int main(void){
    int number;

    printf("Enter a number : ");
    scanf("%d", &number);

    printf("Computed polynomial : %d\n", compute_polynomial(number));
    return 0;
}

int compute_polynomial(int number){
    return 3*power(number,5)+2*power(number,4)-5*power(number,3)-power(number,2)+7*number-6;
}

int power(int number, int to){
    int total = 1;
    for(int i = 1; i <= to; i++){
        total *= number;
    }
    return total;

}
