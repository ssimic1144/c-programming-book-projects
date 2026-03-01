#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int main(void){
    char reversed_message[SIZE];
    int message_length;
    char message[SIZE];
    char c;
    int position = 0;

    printf("Enter a message : ");
    while((c=getchar()) != '\n' && position < SIZE){
        c = tolower(c);
        if(isalpha(c)){
            message[position++] = c;
        }
    }
    position--;
    message_length = position;

    for(int i = 0; i <= message_length; position--,i++){
        reversed_message[i] = message[position];
    }

    while(message_length >= 0){
        if(message[message_length] != reversed_message[message_length]){
            printf("Not a palindrome.\n");
            return 0;
        }
        message_length--;
    }
    printf("Palindrome.\n");

    return 0;
}
