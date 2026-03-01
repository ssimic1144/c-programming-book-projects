/* This program is the same 2b.c since I used array name as a pointer.
 * Project 2b didn't specify what kind of pointer to use instead of 
 * integer.
 * I haven't read all projects before starting.*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int main(void){
    char message[SIZE];
    char *position = message, *reversed_position = message;
    char *message_length;
    char c;

    printf("Enter a message : ");
    while((c=getchar()) != '\n' && position < message + SIZE){
        c = tolower(c);
        if(isalpha(c)){
             *position++ = c;
        }
    }

    position--;

    while( position >= message ){
        if(*position-- != *reversed_position++){
            printf("Not a palindrome.\n");
            return 0;
        }
    }
    printf("Palindrome.\n");

    return 0;
}
