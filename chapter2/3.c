#include <stdio.h>

#define PI 3.14

int main(void){
    float radius;

    printf("Enter radius of a sphere : ");
    scanf("%f", &radius);

    printf("Volume : %.2f\n", 4.0/3.0*PI*(radius*radius*radius));
    return 0;
}
