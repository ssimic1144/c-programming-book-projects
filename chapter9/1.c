#include <stdio.h>

#define SIZE 5

void selection_sort(int length, int array[]);

int main(void){
    int array[SIZE];

    printf("Enter a series of integers : ");
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &array[i]);
    }

    selection_sort(SIZE, array);

    printf("Sorted integers : ");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int length, int array[]){
    if(length == 0){
        return;
    }

    int max = array[0];
    
    for(int i=0; i < length; i++){
        if(array[i] >= max){
            max = array[i];
        }
    }

    for(int i=0; i < SIZE; i++){
        if(array[i] == max){
            array[i] = array[length-1];
            array[length-1] = max;
        }
    }

    selection_sort(length-1, array);

}
