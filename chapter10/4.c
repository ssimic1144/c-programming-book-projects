#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 5

int hand[NUM_CARDS][2];
bool royal, straight, flush, four, three;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);
bool in_hand(int rank, int suit);
void empty_hand(void);
/* we need to somehow sort hand to check straight */
void selection_sort(int length, int matrix[][2]);

int main(void){
    for(;;){
        empty_hand();
        read_cards();
        analyze_hand();
        print_result();
    }

    return 0;
}

void read_cards(){
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    while ( cards_read < NUM_CARDS ){
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        
        switch(rank_ch){
            case '0':
                exit(EXIT_SUCCESS);
            case '2':
                rank = 0; break;
            case '3':
                rank = 1; break;
            case '4':
                rank = 2; break;
            case '5':
                rank = 3; break;
            case '6':
                rank = 4; break;
            case '7':
                rank = 5; break;
            case '8':
                rank = 6; break;
            case '9':
                rank = 7; break;
            case 't': case 'T':
                rank = 8; break;
            case 'j': case 'J':
                rank = 9; break;
            case 'q': case 'Q':
                rank = 10; break;
            case 'k': case 'K':
                rank = 11; break;
            case 'a': case 'A':
                rank = 12; break;
            default:
                bad_card = true;
        }

        suit_ch = getchar();

        switch(suit_ch){
            case 'c': case 'C':
                suit = 0; break;
            case 'd': case 'D':
                suit = 1; break;
            case 'h': case 'H':
                suit = 2; break;
            case 's': case 'S':
                suit = 3; break;
            default:
                bad_card = true;
        }

        while ((ch = getchar()) != '\n'){
            if(ch != ' '){
                bad_card = true;
            }
        }

        if(bad_card){
            printf("Bad card; Ignored.\n");
        } else if(in_hand(rank,suit)){
            printf("Duplicate card; Ignored.\n");
        } else {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

void analyze_hand(){
    royal = false;
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    /* sort hand */
    selection_sort(NUM_CARDS, hand);

    int first_suit_for_flush = hand[0][1];
    int flush_counter = 1;
    for( int card = 1; card < NUM_CARDS; card++ ){
        if(hand[card][1] == first_suit_for_flush){
            flush_counter++;
        }
    }
    if(flush_counter == NUM_CARDS){
        flush = true;
    }

    int value_for_straight = hand[0][0];
    /* since cards are sorted we need to check if first rank is T(or value 8) */
    bool potential_royal;
    if (value_for_straight == 8){
        potential_royal = true;
    } else {
        potential_royal = false;
    }
    int num_consec = 1;
    for(int card = 1; card < NUM_CARDS; card++){
        if(hand[card][0] == value_for_straight + 1){
            num_consec++;
            value_for_straight = hand[card][0];
        }
    }
    if(num_consec == NUM_CARDS){
        if(flush && potential_royal){
            royal = true;
        }
        straight = true;
        return;
    }

    int seen_ranks[13] = {0};
    for(int card = 0; card < NUM_CARDS; card++){
        seen_ranks[hand[card][0]]++;
    }
    for(int rank = 0; rank < 13; rank++){
        if (seen_ranks[rank] == 4){
            four = true;
        }
        if (seen_ranks[rank] == 3){
            three = true;
        }
        if (seen_ranks[rank] == 2){
            pairs++;
        }
    }

}

void print_result(void){
    if (royal){
        printf("Royal flush");
        printf("\n\n");
        return;
    }
    if (straight && flush){
        printf("Straight flush");
    } else if(four){
        printf("Four of a kind");
    } else if(three && pairs == 1){
        printf("Full house");
    } else if(flush){
        printf("Flush");
    } else if(straight){
        printf("Straight");
    } else if(three){
        printf("Three of a kind");
    } else if(pairs == 2){
        printf("Two pairs");
    } else if(pairs == 1){
        printf("Pair");
    } else {
        printf("High card");
    }
    printf("\n\n");
}

bool in_hand(int rank, int suit){
    for(int card=0; card<NUM_CARDS; card++){
        if(hand[card][0] == rank && hand[card][1] == suit){
            return true;
        }
    }
    return false;
}

void empty_hand(void){
    for(int card=0; card<NUM_CARDS; card++){
        hand[card][0] = -1;
        hand[card][1] = -1;
    }
}

void selection_sort(int length, int matrix[][2]){
    if(length == 0){
        return;
    }

    int max = matrix[0][0];
    /* we also need to remeber suit for this sort */
    int max_suit = matrix[0][1];
    
    for(int i=0; i < length; i++){
        if(matrix[i][0] >= max){
            max = matrix[i][0];
            max_suit = matrix[i][1];
        }
    }

    for(int i=0; i < NUM_CARDS; i++){
        if(matrix[i][0] == max){
            matrix[i][0] = matrix[length-1][0];
            matrix[i][1] = matrix[length-1][1];
            matrix[length-1][0] = max;
            matrix[length-1][1] = max_suit;
        }
    }

    selection_sort(length-1, matrix);

}
