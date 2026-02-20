#include <stdio.h>
#include <math.h>

int main(void){
    double x;

    printf("Enter a positive number : ");
    scanf("%lf", &x);

    double new_y = 0;
    double y = 1.0;
    
    while(1){
        new_y = (y + x/y)/2;
        if(fabs(y - new_y) < (0.00001 * y)){
            break;
        }
        y = new_y;
    }

    printf("Square root : %.8lf\n", y);


    return 0;
}
