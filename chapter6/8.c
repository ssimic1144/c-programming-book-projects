#include <stdio.h>

int main(void){
    int days, start;

    printf("Enter number of days in month : ");
    scanf("%d", &days);

    printf("Enter starting day of the week (1=Sun, 7=Sat) : ");
    scanf("%d", &start);

    int day_of_the_week = 1;

    while(start > 1){
        printf("   ");
        start--;
        day_of_the_week++;
    }

    for(int i = 1; i <= days; i++, day_of_the_week++){
        printf("%2d ",i);
        if(day_of_the_week % 7 == 0){
            printf("\n");
            day_of_the_week = 0;
        }
    }
    printf("\n");
    

    return 0;
}
