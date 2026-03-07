#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int compute_vowel_count(const char *sentence);

int main(void){
    char c;
    char sentence[SIZE];
    int i = 0;

    printf("Enter a sentence : ");
    while ( (c=getchar()) != '\n' ){
        sentence[i++] = toupper(c);
    }
    sentence[i] = '\0';

    printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));
    return 0;
}

int compute_vowel_count(const char *sentence){
    int counter = 0;
    while(*sentence){
        if( *sentence == 'A' || *sentence == 'E' || *sentence == 'I' || *sentence == 'O' || *sentence == 'U' ){
            counter++;
        }
        sentence++;
    }
    return counter;
}
