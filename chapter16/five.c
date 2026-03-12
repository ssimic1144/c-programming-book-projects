#include <stdio.h>

struct dep_arr{
    int departure;
    int arrival;
};

int main(void){
    struct dep_arr arr[] = {
        {8*60, 10*60+16}, {9*60+43, 11*60+52}, {11*60+19,13*60+31},
        {12*60+47,15*60}, {14*60,16*60+8}, {15*60+45,17*60+55},
        {19*60,21*60+20}, {21*60+45,23*60+58}
    };

    int hours, minutes;

    printf("Enter a 24-hour time : ");
    scanf("%d:%d", &hours, &minutes);

    int u_minutes_since_midnight;

    u_minutes_since_midnight = hours * 60 + minutes;

    int first_dep_h, second_dep_h, first_dep_m, second_dep_m;
    int first_arr_h, second_arr_h, first_arr_m, second_arr_m; 

    for(int i=0; i < (sizeof(arr) / sizeof(arr[0]));i++){
        first_dep_h = arr[i].departure / 60;
        first_dep_m = arr[i].departure % 60;
        first_arr_h = arr[i].arrival / 60;
        first_arr_m = arr[i].arrival % 60;

        if(u_minutes_since_midnight <= arr[i].departure){
            printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", first_dep_h, first_dep_m, first_arr_h, first_arr_m);
            break;
        }

        if ( i + 1 >= (sizeof(arr) / sizeof(arr[0]))){
            printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", first_dep_h, first_dep_m, first_arr_h, first_arr_m);
            break;
        }

        if(u_minutes_since_midnight < arr[i].departure && u_minutes_since_midnight > arr[i].departure) {
            second_dep_h = arr[i].departure / 60;
            second_dep_m = arr[i].departure % 60;
            second_arr_h = arr[i].arrival / 60;
            second_arr_m = arr[i].arrival % 60;
            if(u_minutes_since_midnight - arr[i].departure  < arr[i].departure - u_minutes_since_midnight){
                printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", first_dep_h, first_dep_m, first_arr_h, first_arr_m);
                break;
            } else {
                printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", second_dep_h, second_dep_m, second_arr_h, second_arr_m);
                break;
            }
        }
    }
    return 0;
}
