#include <stdio.h>

#define SIZE 100

int main(void){
    char word[SIZE];
    char c;
    int counter = 0;
    char terminating_c;

    printf("Enter a sentence : ");
    while(1){
        c = getchar();
        if((c == '.') || (c == '?') || (c == '!')){
            break;
        }
        word[counter++] = c;
    }

    terminating_c = c;

    int letter_counter = 0;
    printf("Reversal of sentence : ");
    for( counter; counter >= 0; counter--){
        if(word[counter] == ' '){
            for(int i=counter+1; i <= counter+letter_counter; i++){
                /*print reversed word*/
                printf("%c", word[i]);
            }
            /*print space*/ 
            printf("%c", word[counter]);
            letter_counter = 0;
        } else {
            letter_counter++;
        }
        if(counter == 0){
            for(int i=counter; i <= counter+letter_counter-1; i++){
                printf("%c", word[i]);
            }
            printf("%c\n", terminating_c);
            break;
        }
    }
    return 0;
}
