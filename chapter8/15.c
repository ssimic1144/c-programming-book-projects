#include <stdio.h>

#define SIZE 80

int main(void){
    char message[SIZE] = {0};
    char encrypted[SIZE] = {0};
    int shift; 
    char c;
    int counter = 0;

    printf("Enter message to be encrypted : ");
    while( (c=getchar()) != '\n' ){
        message[counter++] = c;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    
    printf("Encrypted message : ");
    for(counter = 0; message[counter] != 0; counter++){
        if(message[counter] >= 'a' && message[counter] <= 'z'){
            printf("%c", ((message[counter] - 'a') + shift) % 26 + 'a');
        } else if(message[counter] >= 'A' && message[counter] <= 'Z'){
            printf("%c", ((message[counter] - 'A') + shift) % 26 + 'A');
        }else{
            printf("%c", message[counter]);
        }
    }
    printf("\n");


    return 0;
}
