#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void){
    int first_letters_seen[26] = {0};
    int second_letters_seen[26] = {0};

    printf("Enter first word : ");
    read_word(first_letters_seen);

    printf("Enter second word : ");
    read_word(second_letters_seen);

    if (equal_array(first_letters_seen, second_letters_seen)){
        printf("The words are anagrams.\n");
    } else{
        printf("The words are not anagrams.\n");
    }

    return 0;
}

void read_word(int counts[26]){
    int index;
    char c;
    while( (c=getchar()) != '\n' ){
        if(isalpha(c)){
            c = tolower(c);
            index = c - 'a';
            counts[index]++;
        }
    }
}

bool equal_array(int counts1[26], int counts2[26]){
    for(int i=0; i < 26; i++){
        if(counts1[i] != counts2[i]){
            return false;
        }
    }
    return true;
}
