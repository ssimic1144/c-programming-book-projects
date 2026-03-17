#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20
#define MAX_WORDS 50

int read_line(char str[], int n);
int compare_words(const void *w1, const void *w2);

int main(void){
    char *words[MAX_WORDS];
    int inserted_words = 0;
    char w[WORD_LEN];

    while(1){
        printf("Enter word : ");
        read_line(w, WORD_LEN);
        if(w[0] == '\0'){
            break;
        }
        words[inserted_words] = malloc(sizeof(char) * (strlen(w)+1));
        if(words[inserted_words] == NULL){
            printf("Can't allocate memory for word.\n");
            break;
        }
        strcpy(words[inserted_words], w);
        inserted_words++;
    }

    qsort(words, inserted_words, sizeof(words[0]), compare_words);

    printf("In sorted order : ");
    for(int i = 0; i < inserted_words; i++){
        printf("%s ", words[i]);
    }
    printf("\n");


    return 0;
}

int compare_words(const void *w1, const void *w2){
    const char *p1 = w1;
    const char *p2 = w2;

    return strcmp(*(char **)p1,*(char **)p2);
}

int read_line(char str[], int n){
    int ch, i = 0;

    while((ch=getchar()) != '\n'){
        if(i < n){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
