#include <stdio.h>

int power(int number, int n);

int main(void){
    int number, p;
    printf("Enter a number : ");
    scanf("%d", &number);

    printf("Enter power of : ");
    scanf("%d", &p);

    printf("%d to the power of %d : %d\n", number,p,power(number,p));

    return 0;
}

int power(int number, int n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return power(number,n/2) * power(number,n/2);
    } else {
        return number * power(number, n-1);
    }
}
