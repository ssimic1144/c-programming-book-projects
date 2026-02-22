#include <stdio.h>
#include <ctype.h>

int main(void){
    int letter_seen[26] = {0};
    char c;
    int index;

    printf("Enter first word : ");
    while( (c=getchar()) != '\n' ){
        if(isalpha(c)){
            c = tolower(c);
            index = c - 'a';
            letter_seen[index]++;
        }
    }

    printf("Enter second word : ");
    while( (c=getchar()) != '\n' ){
        if(isalpha(c)){
            c = tolower(c);
            index = c - 'a';
            letter_seen[index]--;
        }
    }

    for(int i=0; i < 26; i++){
        if( letter_seen[i] != 0 ){
            printf("The words are not anagrams.\n");
            return 0;
        }
    }

    printf("The words are anagrams.\n");

    return 0;
}
