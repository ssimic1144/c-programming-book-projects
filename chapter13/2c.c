#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void){
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, num_remind = 0;

    int month;
    char month_str[3];

    for(;;){
        if( num_remind == MAX_REMIND ){
            printf("--No space left --\n");
            break;
        }

        printf("Enter month/day and reminder : ");
        scanf("%2d/%2d", &month, &day);

        if(day == 0 && month == 0){
            break;
        }

        sprintf(month_str, "%2d", month);
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for(i = 0; i < num_remind; i++){
            if(strcmp(month_str, reminders[i]) < 0){
                break;
            }
        }
        for(j = num_remind; j > i; j--){
            strcpy(reminders[j], reminders[j-1]);
        }

        strcpy(reminders[i], month_str);
        strcat(reminders[i], "/");
        strcat(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        char temp[MSG_LEN+3];
        /* This is now same problem as 2b.c */
        for(i; i < num_remind; i++){
            if(strcmp(reminders[i], reminders[i+1]) > 0){
                if(strcmp(day_str, reminders[i+1]+3) > 0){
                    strcpy(temp, reminders[i]);
                    strcpy(reminders[i], reminders[i+1]);
                    strcpy(reminders[i+1], temp);
                }
            }
        }

        num_remind++;
    }

    printf("\nMonth/Day Reminder\n");
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

