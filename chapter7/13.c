#include <stdio.h>

int main(void){
    char c;
    int len = 0;
    int word_counter = 1;

    printf("Enter a sentence : ");
    while((c=getchar()) != '\n'){
        if (c != ' '){
            len++;
        }else{
            word_counter++;
        } 
    }

    printf("Average word length : %.1f\n", (len / (float) word_counter));

    return 0;
}
