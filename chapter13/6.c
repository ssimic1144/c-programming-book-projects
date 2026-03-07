#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define NUM_PLANETS 9

bool equal_strings(char s[], char t[]);

int main(int argc, char *argv[]){
    int i,j;
    char *planets[] = {
        "Mercury",
        "Venus",
        "Earth",
        "Mars",
        "Jupiter",
        "Saturn",
        "Uranus",
        "Neptune",
        "Pluto"
    };

    for(i = 1; i < argc; i++){
        for(j=0; j < NUM_PLANETS; j++){
            if(equal_strings(argv[i], planets[j])){
                printf("%s is planet %d\n", argv[i], j+1);
                break;
            }
        }
        if( j == NUM_PLANETS ){
            printf("%s is not a planet\n", argv[i]);
        }
    }
    
    return 0;
}

bool equal_strings(char s1[], char s2[]){
    for(int i=0; toupper(s1[i]) == toupper(s2[i]); i++){
        if(s1[i] == '\0'){
            return true;
        }
    }
    return false;
}
