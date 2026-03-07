#include <stdio.h>

#define SIZE 80

void encrypt(char *message, int shift);

int main(void){
    char message[SIZE];
    int shift; 
    char c;
    int counter = 0;

    printf("Enter message to be encrypted : ");
    while( (c=getchar()) != '\n' ){
        message[counter++] = c;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    
    encrypt(message, shift);
    printf("Encrypted message : %s\n", message);



    return 0;
}

void encrypt(char *message, int shift){
    while(*message){
        if(*message >= 'a' && *message <= 'z'){
            *message = ((*message - 'a') + shift) % 26 + 'a' ;
        } else if(*message >= 'A' && *message <= 'Z'){
            *message = ((*message - 'A') + shift) % 26 + 'A';
        }
        message++;
    }
}
