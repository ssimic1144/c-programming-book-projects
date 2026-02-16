#include <stdio.h>

int main(void){
    int hours, minutes;

    printf("Enter a 24-hour time : ");
    scanf("%d:%d", &hours, &minutes);

    int alternative_hours;

    if ( hours > 12 ) {
        alternative_hours = hours % 12;
        printf("Equivalent 12-hour time : %d:%d PM\n", alternative_hours, minutes);
    } else if ( hours == 0) {
        alternative_hours = 12;
        printf("Equivalent 12-hour time : %d:%d PM\n", alternative_hours, minutes);
    } else {
        alternative_hours = hours;
        printf("Equivalent 12-hour time : %d:%d AM\n", alternative_hours, minutes);
    }

    return 0;
}