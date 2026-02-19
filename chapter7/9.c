#include <stdio.h>

int main(void){
    int hours, minutes;
    char pre, post;

    printf("Enter a 12-hour time : ");
    scanf("%d:%d %c%c", &hours, &minutes, &pre, &post);

    int e_hours = 0;

    
    if (pre == 'p' || pre == 'P'){
        if ( hours == 12){
            e_hours = hours;
        } else {
            e_hours = hours + 12;
        }
    } else{
        if (hours != 12){
            e_hours = hours;
        }
    }

    printf("Equivalent 24-hour time : %d:%d\n", e_hours, minutes);
    return 0;
}
