#include <stdio.h>

int main(void){
    int a,b;
    
    printf("Enter a fraction : ");
    scanf("%d/%d", &a, &b);

    int remainder;
    int m,n;

    m = a;
    n = b;

    for(;;){
        if(n == 0){
            remainder = m;
            break;
        }

        remainder = m % n;
        m = n;
        n = remainder;

    }

    a /= remainder;
    b /= remainder;

    printf("In lowest terms : %d/%d\n", a,b);

    return 0;
}
