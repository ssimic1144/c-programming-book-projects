#include <stdio.h>

int main(void){
    
    int hours, minutes;

    printf("Enter a 24-hour time : ");
    scanf("%d:%d", &hours, &minutes);

    int u_minutes_since_midnight;

    u_minutes_since_midnight = hours * 60 + minutes;

    int dep[] = {
        8 * 60,
        9 * 60 + 43,
        11 * 60 + 19,
        12 * 60 + 47,
        14 * 60, 
        15 * 60 + 45,
        19 * 60,
        21 * 60 + 45,
    };
    int arrival[]={
        10*60+16,
        11*60+52,
        13*60+31,
        15*60,
        16*60+8,
        17*60+55,
        21*60+20,
        23*60+58,
    };

    int first_dep_h, second_dep_h, first_dep_m, second_dep_m;
    int first_arr_h, second_arr_h, first_arr_m, second_arr_m; 
    
    for(int i = 0; i < 8; i++){
        first_dep_h = dep[i] / 60;
        first_dep_m = dep[i] % 60;
        first_arr_h = arrival[i] / 60;
        first_arr_m = arrival[i] % 60;

        if(u_minutes_since_midnight <= dep[i]){
            printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", first_dep_h, first_dep_m, first_arr_h, first_arr_m);
            break;
        }

        if ( i + 1 >= 8 ){
            printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", first_dep_h, first_dep_m, first_arr_h, first_arr_m);
            break;
        }

        if(u_minutes_since_midnight < dep[i+1] && u_minutes_since_midnight > dep[i]) {
            second_dep_h = dep[i+1] / 60;
            second_dep_m = dep[i+1] % 60;
            second_arr_h = arrival[i+1] / 60;
            second_arr_m = arrival[i+1] % 60;
            if(u_minutes_since_midnight - dep[i]  < dep[i+1] - u_minutes_since_midnight){
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
