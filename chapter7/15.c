#include <stdio.h>
#include <math.h>

int main(void){
    int x;

    printf("Enter a positive integer : ");
    scanf("%d", &x);

    short result_s = 1;
    for(short i=1;i<=x;i++){
        result_s *= i;
    }
    printf("Factorial of %d: %hd\n", x,result_s);

    result_s = 1;
    for(short n = 1;;n++){
        result_s *= n;
        if (result_s < 0 || result_s == 0){
            printf("For short the largest value of n for which the program correctly prints factorial is %hd\n", n-1);
            break;
        }
    }

    int result_i = 1;
    for(int i=1;i<=x;i++){
        result_i *= i;
    }
    printf("Factorial of %d: %d\n", x,result_i);

    result_i = 1;
    for(int n = 1;;n++){
        result_i *= n;
        if (result_i < 0 || result_i == 0){
            printf("For int the largest value of n for which the program correctly prints factorial is %d\n", n-1);
            break;
        }
    }

    long result_l = 1;
    for(long i=1;i<=x;i++){
        result_l *= i;
    }
    printf("Factorial of %d: %ld\n", x,result_l);

    result_l = 1;
    for(long n = 1;;n++){
        result_l *= n;
        if (result_l < 0 || result_l == 0){
            printf("For long the largest value of n for which the program correctly prints factorial is %ld\n", n-1);
            break;
        }
    }

    long long result_ll = 1;
    for(long long i=1;i<=x;i++){
        result_ll *= i;
    }
    printf("Factorial of %d: %lld\n", x,result_ll);

    result_ll = 1;
    for(long long n = 1;;n++){
        result_ll *= n;
        if (result_ll < 0 || result_ll == 0){
            printf("For long long the largest value of n for which the program correctly prints factorial is %lld\n", n-1);
            break;
        }
    }

    float result_f = 1;
    for(float i=1;i<=x;i++){
        result_f *= i;
    }
    printf("Factorial of %d: %f\n", x,result_f);

    result_f = 1.0;
    for(float n = 1;;n++){
        result_f *= n;
        if (result_f < 0 || isinf(result_f) || result_f == 0){
            printf("For float the largest value of n for which the program correctly prints factorial is %f\n", n-1);
            break;
        }
    }

    double result_d = 1;
    for(double i=1;i<=x;i++){
        result_d *= i;
    }
    printf("Factorial of %d: %f\n", x,result_d);

    result_d = 1;
    for(double n = 1;;n++){
        result_d *= n;
        if (result_d < 0 || isinf(result_d) || result_d == 0){
            printf("For double the largest value of n for which the program correctly prints factorial is %f\n", n-1);
            break;
        }
    }

    long double result_ld = 1;
    for(long double i=1;i<=x;i++){
        result_ld *= i;
    }
    printf("Factorial of %d: %Lf\n", x,result_ld);

    result_ld = 1;
    for(long double n = 1;;n++){
        result_ld *= n;
        if (result_ld < 0 || isinf(result_ld) || result_ld == 0){
            printf("For long double the largest value of n for which the program correctly prints factorial is %Lf\n", n-1);
            break;
        }
    }
    return 0;
}
