#include <stdio.h>

void find_closest_flight(int desired_time,int *departure_time,int*arrival_time);

int main(void){
    
    int hours, minutes;

    printf("Enter a 24-hour time : ");
    scanf("%d:%d", &hours, &minutes);

    int minutes_since_midnight, departure, arrival;

    minutes_since_midnight = hours * 60 + minutes;

    find_closest_flight(minutes_since_midnight, &departure, &arrival);

    printf("Desired time : %d\n", minutes_since_midnight);
    printf("Departure time : %d\n", departure);
    printf("Arrival time : %d\n", arrival);

    return 0;
}


void find_closest_flight(int desired_time,int *departure_time,int*arrival_time){
    int dep1, dep2, dep3, dep4, dep5, dep6, dep7, dep8;
    int arr;

    dep1 = 8 * 60;
    dep2 = 9 * 60 + 43;
    dep3 = 11 * 60 + 19;
    dep4 = 12 * 60 + 47;
    dep5 = 14 * 60;
    dep6 = 15 * 60 + 45;
    dep7 = 19 * 60;
    dep8 = 21 * 60 + 45;
    
    if( desired_time < dep1 ){
        arr = 10*60 + 16;
        *departure_time = dep1;
        *arrival_time = arr;
        return;
    }

    if( desired_time < dep2) {
        if(desired_time - dep1 < dep2 - desired_time){
            arr = 10*60 + 16;
            *departure_time = dep1;
            *arrival_time = arr;
        } else {
            arr = 11*60 + 52;
            *departure_time = dep2;
            *arrival_time = arr;
        }
    }

    if( desired_time < dep3 && desired_time > dep2) {
        if(desired_time - dep2 < dep3 - desired_time){
            arr = 11*60 + 52;
            *departure_time = dep2;
            *arrival_time = arr;
        } else {
            arr = 13*60 + 31;
            *departure_time = dep3;
            *arrival_time = arr;
        }
    }

    if( desired_time < dep4 && desired_time > dep3) {
        if(desired_time - dep3 < dep4 - desired_time){
            arr = 13*60 + 31;
            *departure_time = dep3;
            *arrival_time = arr;
        } else {
            arr = 15*60;
            *departure_time = dep4;
            *arrival_time = arr;
        }
    }

    if( desired_time < dep5 && desired_time > dep4) {
        if(desired_time - dep4 < dep5 - desired_time){
            arr = 15*60;
            *departure_time = dep4;
            *arrival_time = arr;
        } else {
            arr = 16*60 + 8;
            *departure_time = dep5;
            *arrival_time = arr;
        }
    }

    if( desired_time < dep6 && desired_time > dep5) {
        if(desired_time - dep5 < dep6 - desired_time){
            arr = 16*60 + 8;
            *departure_time = dep5;
            *arrival_time = arr;
        } else {
            arr = 17*60 + 55;
            *departure_time = dep6;
            *arrival_time = arr;
        }
    }
    
    if( desired_time < dep7 && desired_time > dep6) {
        if(desired_time - dep6 < dep7 - desired_time){
            arr = 17*60 + 55;
            *departure_time = dep6;
            *arrival_time = arr;
        } else {
            arr = 21*60 + 20;
            *departure_time = dep7;
            *arrival_time = arr;
        }
    }

    if( desired_time < dep8 && desired_time > dep7) {
        if(desired_time - dep7 < dep8 - desired_time){
            arr = 21*60 + 20;
            *departure_time = dep7;
            *arrival_time = arr;
        } else {
            arr = 23*60 + 58;
            *departure_time = dep8;
            *arrival_time = arr;
        }
    }
}
