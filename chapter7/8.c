#include <stdio.h>

int main(void){
    int hours, minutes;
    char pre, post;

    printf("Enter a 12-hour time : ");
    scanf("%d:%d %c%c", &hours, &minutes, &pre, &post);

    int u_minutes_since_midnight;

    if (pre == 'p' || pre == 'P'){
        u_minutes_since_midnight = 12 * 60 + hours * 60 + minutes;
    } else {
        u_minutes_since_midnight = hours * 60 + minutes;
    }

    int dep1, dep2, dep3, dep4, dep5, dep6, dep7, dep8;

    dep1 = 8 * 60;
    dep2 = 9 * 60 + 43;
    dep3 = 11 * 60 + 19;
    dep4 = 12 * 60 + 47;
    dep5 = 14 * 60;
    dep6 = 15 * 60 + 45;
    dep7 = 19 * 60;
    dep8 = 21 * 60 + 45;
    
    if( u_minutes_since_midnight < dep1 ){
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
        return 0;
    }

    if( u_minutes_since_midnight < dep2) {
        if(u_minutes_since_midnight - dep1 < dep2 - u_minutes_since_midnight){
            printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
        } else {
            printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
        }
    }

    if( u_minutes_since_midnight < dep3 && u_minutes_since_midnight > dep2) {
        if(u_minutes_since_midnight - dep2 < dep3 - u_minutes_since_midnight){
            printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
        } else {
            printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
        }
    }

    if( u_minutes_since_midnight < dep4 && u_minutes_since_midnight > dep3) {
        if(u_minutes_since_midnight - dep3 < dep4 - u_minutes_since_midnight){
            printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
        } else {
            printf("Closest departure time is 12:47 p.m., arriving at 15:00 p.m.\n");
        }
    }

    if( u_minutes_since_midnight < dep5 && u_minutes_since_midnight > dep4) {
        if(u_minutes_since_midnight - dep4 < dep5 - u_minutes_since_midnight){
            printf("Closest departure time is 12:47 p.m., arriving at 15:00 p.m.\n");
        } else {
            printf("Closest departure time is 14:00 p.m., arriving at 16:08 p.m.\n");
        }
    }

    if( u_minutes_since_midnight < dep6 && u_minutes_since_midnight > dep5) {
        if(u_minutes_since_midnight - dep5 < dep6 - u_minutes_since_midnight){
            printf("Closest departure time is 14:00 p.m., arriving at 16:08 p.m.\n");
        } else {
            printf("Closest departure time is 15:45 p.m., arriving at 17:55 p.m.\n");
        }
    }
    
    if( u_minutes_since_midnight < dep7 && u_minutes_since_midnight > dep6) {
        if(u_minutes_since_midnight - dep6 < dep7 - u_minutes_since_midnight){
            printf("Closest departure time is 15:45 p.m., arriving at 17:55 p.m.\n");
        } else {
            printf("Closest departure time is 19:00 p.m., arriving at 21:20 p.m.\n");
        }
    }

    if( u_minutes_since_midnight < dep8 && u_minutes_since_midnight > dep7) {
        if(u_minutes_since_midnight - dep7 < dep8 - u_minutes_since_midnight){
            printf("Closest departure time is 19:00 p.m., arriving at 21:20 p.m.\n");
        } else {
            printf("Closest departure time is 21:45 p.m., arriving at 23:58 p.m.\n");
        }
    }

    return 0;
}
