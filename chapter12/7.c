#include <stdio.h>

#define SIZE 5

void max_min(int a[], int n, int *max, int *min);

int main(void){
    int b[SIZE], i, big, small;

    printf("Enter %d numbers : ", SIZE);
    for(i = 0; i < SIZE; i++){
        scanf("%d", &b[i]);
    }

    max_min(b, SIZE, &big, &small);

    printf("Largest : %d\n", big);
    printf("Smallest : %d\n", small);
    return 0;
}

void max_min(int a[], int n, int *max, int *min){
    int *position = a + 1;

    *max = *min = a[0];
    for(position; position < a + n; position++){
        if (*position > *max){
            *max = *position;
        } else if( *position < *min ){
            *min = *position;
        }
    }
}
