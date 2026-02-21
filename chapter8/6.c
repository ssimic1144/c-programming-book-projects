#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int main(void){
    char c_array[SIZE] = {0};
    char c;
    int counter=0;

    printf("Enter message : ");
    while( (c=getchar()) != '\n' ){
       c_array[counter] = toupper(c); 
       counter++;
    }

    printf("In B1FF-speak : ");
    for(int i=0; c_array[i] != 0; i++){
        switch(c_array[i]){
            case 'A':
                printf("4");
                break;
            case 'B':
                printf("8");
                break;
            case 'E':
                printf("3");
                break;
            case 'I':
                printf("1");
                break;
            case 'O':
                printf("0");
                break;
            case 'S':
                printf("5");
                break;
            default:
                printf("%c", c_array[i]);
                break;
        }
    }
    printf("!!!!!!!!!!\n");


    return 0;
}
