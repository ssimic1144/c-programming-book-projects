#include <stdio.h>

#define SIZE 100

int main(void){
    char message[SIZE];
    char c;
    int position = 0;

    printf("Enter a message : ");
    while((c=getchar()) != '\n' && position < SIZE){
        message[position++] = c;
    }

    position--;

    printf("Reversal is : ");
    while(position >=0){
        printf("%c", message[position--]);
    }
    printf("\n");

    return 0;
}
