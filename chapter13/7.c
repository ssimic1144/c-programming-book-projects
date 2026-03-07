#include <stdio.h>

int main(void){
    int number; 
    char *ten_to_nineteen[] = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    };
    char *twenty_to_ninety[] = {
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"
    };

    char *one_to_nine[] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    printf("Enter a two-digit number : ");
    scanf("%d", &number);
    
    printf("You entered the number ");

    if (number < 20) {
        printf("%s\n", ten_to_nineteen[number % 10]);
        return 0;
    }

    int part_one, part_two;

    part_one = number / 10;
    part_two = number % 10;

    printf("%s-", twenty_to_ninety[part_one - 2]);
    printf("%s\n", one_to_nine[part_two - 1]);

    return 0;
}
