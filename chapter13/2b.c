/* This project took way more then I'd like to admit */
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void){
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, num_remind = 0;

    int hours, minutes;
    char hours_str[3], minutes_str[3];

    for(;;){
        if( num_remind == MAX_REMIND ){
            printf("--No space left --\n");
            break;
        }

        printf("Enter day, 24-hour time and reminder : ");
        scanf("%2d", &day);
        if(day == 0){
            break;
        }
        sprintf(day_str, "%2d", day);
        /* read time */
        scanf("%2d:%2d", &hours, &minutes);
        sprintf(hours_str, "%2d", hours);
        sprintf(minutes_str, "%2d", minutes);

        read_line(msg_str, MSG_LEN);

        for(i = 0; i < num_remind; i++){
            if(strcmp(day_str, reminders[i]) < 0){
                break;
            }
        }
        
        for(j = num_remind; j > i; j--){
            strcpy(reminders[j], reminders[j-1]);
        }

        strcpy(reminders[i], day_str);
        strcat(reminders[i], " ");
        strcat(reminders[i], hours_str);
        strcat(reminders[i], ":");
        strcat(reminders[i], minutes_str);
        strcat(reminders[i], msg_str);

        char temp[MSG_LEN+3];
        int original_position = i;
        /* Default algorith will put reminder on the first spot sorted by day.
         * If it's the lowest value by time we don't have to do anything.
         * If it's not:
         * First we need to look if current is > then the next.
         * Here we check so we don't go over to the next day.
         * If it's the same day, i is > only if the second number is >, 
         * since we have standardize input and strcmp() checks char by char.
         * Later we just position ourselfs on begining of hours and we replace
         * bigger value with smaller value.
         * */
        for(i; i < num_remind; i++){
            if(strcmp(reminders[i], reminders[i+1]) > 0){
                if(strcmp(hours_str, reminders[i+1]+3) > 0){
                    strcpy(temp, reminders[i]);
                    strcpy(reminders[i], reminders[i+1]);
                    strcpy(reminders[i+1], temp);
                }
            }
        }

        /* We need to reset i to original position */
        i =  original_position;
        for(i; i < num_remind; i++){
            if(strcmp(reminders[i], reminders[i+1]) > 0){
                if(strcmp(reminders[i]+3, reminders[i+1]+3) > 0){
                    if(strcmp(minutes_str, reminders[i+1]+6) > 0){
                        strcpy(temp, reminders[i]);
                        strcpy(reminders[i], reminders[i+1]);
                        strcpy(reminders[i+1], temp);
                    }
                }
            }
        }

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for(i = 0; i < num_remind; i++){
        printf(" %s\n", reminders[i]);
    }

    return 0;
}

int read_line(char str[], int n){
    int ch, i = 0;

    while( (ch=getchar()) != '\n' ){
        if( i < n ){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
