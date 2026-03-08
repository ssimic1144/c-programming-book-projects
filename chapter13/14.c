#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 30

bool are_anagrams(const char *word1, const char *word2);
void enter_word(char *word);

int main(void){
    char word1[SIZE], word2[SIZE];

    printf("Enter first word : ");
    enter_word(word1);

    printf("Enter second word : ");
    enter_word(word2);


    if(are_anagrams(word1, word2)){
        printf("The words are anagrams.\n");
    } else{
        printf("The words are not anagrams.\n");
    }

    return 0;
}

bool are_anagrams(const char *word1, const char *word2){
    int letter_seen[26] = {0};
    int index;

    while(*word1){
        index = *word1 - 'a';
        letter_seen[index]++;
        word1++;
    }

    while(*word2){
        index = *word2 - 'a';
        letter_seen[index]--;
        word2++;
    }

    for(int i=0; i < 26; i++){
        if( letter_seen[i] != 0 ){
            return 0;
        }
    }
    return 1;

}

void enter_word(char *word){
    char c;
    while( (c=getchar()) != '\n' ){
        if(isalpha(c)){
            *word++ = tolower(c);
        }
    }
}
