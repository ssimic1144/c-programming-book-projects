#include <stdio.h>
#include <ctype.h>

#define SIZE 50

int compute_scrabble_value(const char *word);

int main(void){
    char c;
    char word[SIZE];
    int i = 0;

    printf("Enter a word: ");

    while ( (c=getchar()) != '\n' ){
        word[i++] = toupper(c);
    }
    word[i] = '\0';

    printf("Scrabble value : %d\n", compute_scrabble_value(word));

    return 0;
}

int compute_scrabble_value(const char *word){
    int sum = 0;
    while(*word){
        switch(*word){
            case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': 
            case 'R': case 'S': case 'T': case 'U':
                sum++;
                break;
            case 'D': case 'G':
                sum += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                sum += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                sum += 4;
                break;
            case 'K':
                sum += 5;
                break;
            case 'J': case 'X':
                sum += 8;
                break;
            case 'Q': case 'Z':
                sum += 10;
                break;
        }
        word++;
    }
    return sum;
}
