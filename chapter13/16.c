#include <stdio.h>

#define SIZE 100

void reverse(char *message);

int main(void){
    char message[SIZE];
    char c;
    int position = 0;

    printf("Enter a message : ");
    while((c=getchar()) != '\n' && position < SIZE){
        message[position++] = c;
    }
    message[position] = '\0';

    reverse(message);
    printf("Reversal is : %s\n", message);

    return 0;
}

void reverse(char *message){
    char *end = message;
    char *start = message;
    char temp; 
    
    while(*end){
        end++;
    }
    //After while loop it points to null char, so we need to move
    //one position before null char.
    end--;

    while(end > start){
        temp = *end;
        *end = *start;
        *start = temp;
        end--;
        start++;
    }

}
