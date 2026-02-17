#include <stdio.h>

int main(void){

    int month, day, year;
    int e_month, e_day, e_year;
    int to_days;
    int min = 0;

    for(;;){
        printf("Enter first date (mm/dd/yy) : ");
        scanf("%d/%d/%d", &month, &day, &year);
        
        to_days = year * 365 + month * 30 + day;

        if (to_days == 0){
            break;
        }

        if (min == 0){
            min = to_days;
            e_month = month;
            e_day = day;
            e_year = year;
        }
        
        if (to_days < min){
            min = to_days;
            e_month = month;
            e_day = day;
            e_year = year;
        }
    }

    printf("%d/%d/%d is the earliest date.\n", e_month, e_day, e_year);
    return 0;
}
