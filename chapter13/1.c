#include <stdio.h>
#include <string.h>

#define WORD_LEN 20

int read_line(char str[], int n);

int main(void){
    char word[WORD_LEN], smallest_word[WORD_LEN], largest_word[WORD_LEN];

    while(1){

        printf("Enter word : ");
        read_line(word, WORD_LEN);

        if(strlen(word) == 4){
            break;
        }

        if( !strlen(smallest_word) && !strlen(largest_word) ){
            strcpy(smallest_word, word);
            strcpy(largest_word, word);
            continue;
        } 

        if( strcmp(word, smallest_word) <= 0 ){
            strcpy(smallest_word, word);
        }

        if(strcmp(word, largest_word) > 0){
            strcpy(largest_word, word);
        }
    }
    printf("Smallest word : %s\n", smallest_word);
    printf("Largest word : %s\n", largest_word);

    return 0;
}

int read_line(char str[], int n){
    int ch, i = 0;
    while( (ch=getchar()) != '\n' ){
        if(i < n){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
