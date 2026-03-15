#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part{
    int number;
    char name[NAME_LEN+1];
    int on_hand;
};

struct part *inventory;
int num_parts = 0;

int find_part(int number);
void insert(int *current_parts);
void search(void);
void update(void);
void print(void);

int main(void){
    char code;

    int current_parts = 10;

    inventory = malloc(current_parts * sizeof(struct part));
    if(inventory == NULL){
        printf("Initial memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for(;;){
        printf("Enter operation code : ");
        scanf(" %c", &code);
        while(getchar() != '\n');

        switch(code){
            case 'i':
                insert(&current_parts);
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code.\n");
        }
        printf("\n");
    }
}

int find_part(int number){
    for(int i = 0; i < num_parts; i++){
        if(inventory[i].number == number){
            return i;
        }
    }
    return -1;
}

void insert(int *current_parts){
    int part_number;

    // We need temporary pointer in case realloc return NULL.
    // If we don't put it in NULL, we may lose the whole database.
    struct part *temp;
    if( num_parts == *current_parts ){
        printf("Database is full; Reallocating space. \n");
        
        *current_parts *= 2;

        temp = realloc(inventory, *current_parts * sizeof(struct part));
        if(temp == NULL){
            printf("No more memory for reallocating space.\n");
            return;
        }
        inventory = temp;
    }
    printf("Enter part number : ");
    scanf("%d", &part_number);

    if( find_part(part_number) >= 0 ){
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name : ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand : ");
    scanf("%d", &inventory[num_parts].on_hand);

    num_parts++;
}

void search(void){
    int i, number;

    printf("Enter part number : ");
    scanf("%d", &number);

    i = find_part(number);
    if(i >= 0){
        printf("Part name : %s\n", inventory[i].name);
        printf("Quantity on hand : %d\n", inventory[i].on_hand);
    } else{
        printf("Part not found.\n");
    }
}

void update(void){
    int i, number, change;

    printf("Enter part number : ");
    scanf("%d", &number);

    i = find_part(number);
    if(i >= 0){
        printf("Enter change in quantity on hand : ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

void print(void){
    printf("Part Number\tPart Name\t\tQuantity on Hand\n");
    for(int i = 0; i < num_parts; i++){
        printf("%7d\t\t%-25s\t%11d", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
}
