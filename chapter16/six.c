#include <stdio.h>

struct date{
    int day;
    int month;
    int year;
};

int compare_dates(struct date d1, struct date d2);

int main(void){
    struct date d1, d2;
    printf("Enter first date (mm/dd/yy) : ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

    printf("Enter second date (mm/dd/yy) : ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

    if(compare_dates(d1,d2) < 0){
        printf("%d/%d/%d is earlier than %d/%d/%d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    } else {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
    }

    return 0;
}

int compare_dates(struct date d1, struct date d2){
    int to_days_one, to_days_two;

    to_days_one = d1.year * 366 + d1.month * 30 + d1.day;
    to_days_two = d2.year * 366 + d2.month * 30 + d2.day;

    if(to_days_one < to_days_two){
        return -1;
    } else {
        return 1;
    }
}
