#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct line{
    char *word;
    struct line *next;
};

struct line *line_p = NULL; 

int line_len = 0;
int num_words = 0;

void clear_line(void){
    struct line *cur, *prev;

    cur = line_p;

    while(cur != NULL){
        prev = cur;
        cur = cur->next;
        //Word was allocated with calloc.
        //We need to deallocated it also.
        free(prev->word); 
        free(prev);
    }

    line_p = NULL;

    line_len = 0;
    num_words = 0;
}

void add_word(const char *word){
    struct line *new_node, *cur;
    char *temp;

    int word_len = strlen(word);

    new_node = malloc(sizeof(struct line));

    if(new_node == NULL){
        printf("Out of memory. Can't allocate memory for new node.");
        exit(EXIT_FAILURE);
    }

    // We use calloc here because malloc gives corrupted data after second pass
    // It's still unknown to me why, probably because of clear_line(void)
    new_node->word = calloc(word_len, sizeof(char));
    if(new_node->word == NULL){
        printf("Out of memory. Can't allocate memory for new word.");
        exit(EXIT_FAILURE);
    }

    if(num_words > 0){
        temp = realloc(new_node->word, word_len+1);
        if(temp == NULL){
            printf("Out of memory. Can't allocate memory for space in new word.");
            exit(EXIT_FAILURE);
        }
        new_node->word = temp;
        new_node->word[0] = ' ';
        line_len++;
    }

    strcat(new_node->word, word);
    new_node->next = NULL;

    if(line_p == NULL){
        line_p = new_node;
    } else {
        for(cur=line_p; cur->next != NULL; cur=cur->next);
        cur->next = new_node;
    }



    line_len += word_len;
    num_words++;
}

int space_remaining(void){
    return MAX_LINE_LEN - line_len;
}

void write_line(void){
    int extra_spaces, spaces_to_insert, i, j, k;
    struct line *p = line_p;

    extra_spaces = MAX_LINE_LEN - line_len;

    for(i = 0; i < line_len; i++){
        for(k = 0; k < strlen(p->word); k++){
            if(p->word[k] != ' '){
                putchar(p->word[k]);
            } else {
                spaces_to_insert = extra_spaces / (num_words - 1);
                for(j = 1; j <= spaces_to_insert + 1; j++){
                    putchar(' ');
                }
                extra_spaces -= spaces_to_insert;
                num_words--;
            }
        }
        p = p->next;
        if(p == NULL){
            break;
        }
        // We need to decrease k by 1 because last k is actually a null char
        i += k - 1;
    }
    putchar('\n');
}

void flush_line(void){
    struct line *p = line_p;

    if(line_len > 0){
        for(p; p !=NULL; p = p->next){
            for(int i = 0; i < strlen(p->word); i++){
                putchar(p->word[i]);
            }
        }
    }
    putchar('\n');
}
