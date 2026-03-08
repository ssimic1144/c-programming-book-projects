#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

bool is_palindrome(const char *message);

int main(void){
    char message[SIZE];
    char c;
    int position = 0;

    printf("Enter a message : ");
    while((c=getchar()) != '\n' ){
        if( position == SIZE ){
            printf("Message is too large\n");
            exit(EXIT_FAILURE);
        }
        c = tolower(c);
        if(isalpha(c)){
            message[position++] = c;
        }
    }
    message[position] = '\0';

    if(is_palindrome(message)){
        printf("Palindrome.\n");
    } else{
        printf("Not a palindrome.\n");
    }

    return 0;
}

bool is_palindrome(const char *message){
    int i = 0;
    char temp[SIZE];
    while(*message){
        temp[i++] = *message;
        message++;
    }
    message--;
    i = 0;
    while(*message){
        if(*message != temp[i]){
            return 0;
        }
        message--;
        i++;
    }
    return 1;

}
