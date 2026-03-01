#include <stdio.h>

#define SIZE 5

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void){
    int array[SIZE];
    int *start = array, *end = &array[SIZE - 1];

    printf("Enter %d number to be sorted : ", SIZE);
    for(int i=0; i < SIZE; i++){
        scanf("%d", &array[i]);
    }

    quicksort(array, start, end);

    printf("In sorted order : ");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
    return 0;
}

void quicksort(int a[], int *low, int *high){
    int *middle;

    if(low >= high){
        return;
    }
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle+1, high);
}

int *split(int a[], int *low, int *high){
    int part_element = *low;
    for(;;){
        while( low < high && part_element <= *high){
            high--;
        }
        if(low >= high){
            break;
        }
        *low++ = *high;

        while( low < high && *low <= part_element){
            low++;
        }
        if( low >= high ){
            break;
        }
        *high-- = *low;
    }
    *high = part_element;
    return high;
}
