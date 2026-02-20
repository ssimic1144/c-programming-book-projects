#include <stdio.h>

int main(void){

    long n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table : ");
    scanf("%ld", &n);

    int product;
    for (int i = 1; i <= n; i++){
        product = i*i;
        if (product < 0){
            printf("The smallest value of n that causes failure for int is %d\n", i);
            break;
        }
    }

    short s_product;
    for (short i = 1; i <= n; i++){
        s_product = i*i;
        if (s_product < 0){
            printf("The smallest value of n that causes failure for short is %hd\n", i);
            break;
        }
    }

    long l_product;
    for (long i = 1; i <= n; i++){
        l_product = i*i;
        if (l_product < 0){
            printf("The smallest value of n that causes failure for long is %ld\n", i);
            break;
        }
    }

    return 0;
}
