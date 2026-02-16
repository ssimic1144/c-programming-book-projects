#include <stdio.h>

int main(void){

    int month_one, day_one, year_one;
    int month_two, day_two, year_two;

    printf("Enter first date (mm/dd/yy) : ");
    scanf("%d/%d/%d", &month_one, &day_one, &year_one);

    printf("Enter second date (mm/dd/yy) : ");
    scanf("%d/%d/%d", &month_two, &day_two, &year_two);

    int to_days_one, to_days_two;

    to_days_one = year_one * 365 + month_one * 30 + day_one;
    to_days_two = year_two * 365 + month_two * 30 + day_two;

    if(to_days_one > to_days_two){
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month_two, day_two, year_two, month_one,day_one,year_one);
    } else {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month_one, day_one, year_one, month_two,day_two,year_two);
    }

    return 0;
}
