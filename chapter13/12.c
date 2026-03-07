#include <stdio.h>
#include <ctype.h>

#define SENTENCE_SIZE 30
#define WORD_SIZE 20

int main(void){
    char sentence[SENTENCE_SIZE][WORD_SIZE];
    char c;
    int word_counter = 0;
    int i = 0;
    char terminating_c;

    printf("Enter a sentence : ");
    while(1){
        c = getchar();
        if((c == '.') || (c == '?') || (c == '!')){
            sentence[word_counter][i] = '\0';
            break;
        } else if( c == ' ' ){
            sentence[word_counter][i] = '\0';
            word_counter++;
            i = 0;
        } else {
            sentence[word_counter][i++] = c;
        }
    }

    terminating_c = c;

    printf("Reversal of sentence : ");
    for(word_counter; word_counter >= 0; word_counter--){
        if(word_counter != 0){
            printf("%s ", sentence[word_counter]);
        } else{
            printf("%s", sentence[word_counter]);
        }
    }
    printf("%c\n", terminating_c);

    return 0;
}
