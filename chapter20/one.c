#include <stdio.h>

//Order of declaration is important!
struct float_32{
    unsigned int fraction: 23;
    unsigned int exponent: 8;
    unsigned int sign: 1;
};

union number{
    float f;
    struct float_32 f_32;
};

int main(void){
    union number n;
    n.f_32.sign = 1;
    n.f_32.exponent = 128;
    n.f_32.fraction = 0;
    
    printf("%f\n", n.f);
    printf("%d\t%d\t%d\n", n.f_32.sign, n.f_32.exponent, n.f_32.fraction);

    return 0;
}
