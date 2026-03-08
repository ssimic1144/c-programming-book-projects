#include <stdio.h>

int main(void){
    char *months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    int m,d,y;

    printf("Enter a date (mm/dd/yyyy) : ");
    scanf("%2d/%2d/%4d", &m,&d,&y);

    printf("You entered the date %s %d, %d\n", months[m-1], d, y);

    return 0;
}
