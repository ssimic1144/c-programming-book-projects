#include <stdio.h>
#include "stackADT.h"

int main(void){
    Stack s1, s2;
    char *n;

    s1 = create();
    s2 = create();

    push(s1,"1");
    push(s1,"word");

    n = pop(s1);
    printf("Popped %s from s1\n", n);
    push(s2,n);

    n = pop(s1);
    printf("Popped %s from s1\n", n);
    push(s2,n);

    destroy(s1);

    while(!is_empty(s2)){
        // we assigned pop value to n so we don't get compiler warning.
        // As %s expects char* and pop() is void*.
        n = pop(s2);
        printf("Popped %s from s2\n", n);
    }

    push(s2,"three");
    make_empty(s2);

    if(is_empty(s2)){
        printf("s2 is empty\n");
    } else {
        printf("s2 is not empty\n");
    }

    destroy(s2);

    return 0;
}
