#include <stdio.h>

int main(void){

    float e = 1.0f;
    int n;
    float factorial = 1.0f;

    printf("Enter an integer : ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        factorial *= i;
        e += (1.0/factorial);
    }

    printf("Approximation of e is %f\n", e);
    return 0;
}
