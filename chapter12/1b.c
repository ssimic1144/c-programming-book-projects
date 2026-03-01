#include <stdio.h>

#define SIZE 100

int main(void){
    char message[SIZE];
    char c;
    char *position = message;

    printf("Enter a message : ");
    while( (c=getchar()) != '\n' && position < message + SIZE){
        *position++ = c;
    }

    /* we need to decrement position because of last ++ in while loop
     * it's pointing to "empty" address position*/
    position--;

    printf("Reversal is : ");
    while(position >= message){
        printf("%c", *position--);
    }
    printf("\n");
    return 0;
}
