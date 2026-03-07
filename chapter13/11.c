#include <stdio.h>
#include <ctype.h>

#define SIZE 100

double compute_average_word_length(const char *sentence);

int main(void){
    char sentence[SIZE];
    char c;
    int i = 0;

    printf("Enter a sentence : ");
    while((c=getchar()) != '\n'){
        sentence[i++] = c;
    }
    sentence[i] = '\0';

    printf("Average word length: %.1f\n",compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence){
    int words_counter=1, letters_counter=0;
    while(*sentence){
        if (*sentence != ' '){
            letters_counter++;
        }else{
            words_counter++;
        } 
        sentence++;
    }
    return letters_counter / (double) words_counter;
}
