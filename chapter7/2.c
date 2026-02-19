#include <stdio.h>

int main(void){

    int n;
    char c;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table : ");
    scanf("%d", &n);
    c = getchar();

    int product;
    for (int i = 1, j = 1; i <= n; i++, j++){
        if (j == 24){
            printf("Press Enter to continue...");
            c = getchar();
            j = 0;
        }
        product = i*i;
        printf("%20d%20d\n", i, product);
    }

    return 0;
}
