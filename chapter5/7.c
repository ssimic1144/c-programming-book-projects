#include <stdio.h>

int main(void){

    int a,b,c,d;

    printf("Enter four integers : ");
    scanf("%d%d%d%d", &a,&b,&c,&d);

    int min, max;

    min = a;
    max = a;

    if(b > a){
        max = b;
    } else {
        min = b;
    }

    if(c > a && c > b){
        max = c;
    } else {
        if(c < a && c < b){
            min = c;
        }
    }

    if(d > a && d > b && d > c){
        max = d;
    } else {
        if(d < a && d < b && d < c){
            min = d;
        }
    }

    printf("Largest : %d\n", max);
    printf("Smallest : %d\n", min);

    return 0;
}
