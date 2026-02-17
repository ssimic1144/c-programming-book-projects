#include <stdio.h>

int main(void){

    float e = 1.0f;
    float factorial = 1.0f;
    float term, user_e;
    int i = 1;

    printf("Enter smal floating-point number : ");
    scanf("%f", &user_e);

    do{
        factorial *= i;
        term = (1.0/factorial);
        e += term;
        i++;
    }while(term > user_e);

    printf("%f is approximation of e\n%.10f is user input\n%.10f is term\n", e, user_e, term);

    return 0;
}
