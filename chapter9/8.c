#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void){
    bool result;
    char decision;
    int wins = 0;
    int losses = 0;
    srand( (unsigned) time(NULL) );
    while(1){
       result = play_game();
       if(result){
           printf("You win!\n");
           wins++;
       } else{
           printf("You lose!\n");
           losses++;
       }
       printf("Play again? ");
       scanf("%c", &decision);
       if(tolower(decision) != 'y'){
           break;
       }
       /* clear new line from scanf */
       getchar();
    }
    printf("Wins : %d\tLosses : %d\n", wins, losses);
    return 0;
}

int roll_dice(void){
    int first_dice_roll = rand() % 6;
    int second_dice_roll = rand() % 6;
    return first_dice_roll + second_dice_roll;
}

bool play_game(void){
    int result;
    int point = 0;
    bool first_roll = true;
    while(1){
        printf("You rolled : ");
        result = roll_dice();
        printf("%d\n", result);

        if(first_roll){
            first_roll = false;
            switch(result){
                case 7: case 11:
                    return true;
                case 2: case 3: case 12:
                    return false;
                default:
                    point = result;
            }
        } else {
            if (result == point ){
                return true;;
            }
            if (result == 7){
                return false;
            }
        }


    }
}
