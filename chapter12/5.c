#include <stdio.h>

#define SIZE 100

int main(void){
    char sentence[SIZE];
    char c, terminating_c;
    char *pointer = sentence;
    char *end_of_the_word, *writer_p;

    printf("Enter a sentence : ");
    while(1){
        c = getchar();
        if((c == '.') || (c == '?') || (c == '!')){
            break;
        }
        *pointer++ = c;
    }

    terminating_c = c;

    end_of_the_word = pointer;

    printf("Reversal of sentence : ");
    for(pointer; pointer >= sentence; pointer--){
        if(*pointer == ' '){
            writer_p = pointer+1;
            for(writer_p; writer_p < end_of_the_word; writer_p++){
                printf("%c", *writer_p);
            }
            /* we need to print space */
            printf("%c", *pointer);
            end_of_the_word = pointer;
        }
        if(pointer == sentence){
            writer_p = pointer;
            for(writer_p; writer_p < end_of_the_word; writer_p++){
                printf("%c", *writer_p);
            }
        }
    }
    printf("%c\n", terminating_c);
    return 0;
}
