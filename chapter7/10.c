#include <stdio.h>
#include <ctype.h>

int main(void){
    char c;
    int counter = 0;

    printf("Enter a sentence : ");
    while ( (c=getchar()) != '\n' ){
        c = toupper(c);
        if( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ){
            counter++;
        }
    }

    printf("Your sentence contains %d vowels.\n", counter);
    return 0;
}
