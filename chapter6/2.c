#include <stdio.h>

int main(void){

    int a,b;

    printf("Enter two integers : ");
    scanf("%d%d", &a,&b);

    int remainder;


    for(;;){
        if(b == 0){
            remainder = a;
            break;
        }
        remainder = a % b;

        a = b;
        b = remainder;
    }

    printf("Greatest common divisor : %d\n", remainder);

    return 0;
}
