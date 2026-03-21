#include <stdio.h>
#include "queueADT.h"

int main(void){
    Queue q1, q2;
    int n;

    q1 = create(10);
    q2 = create(10);

    insert(q1,1);
    printf("Inserted 1 in q1\n");
    insert(q1,2);
    printf("Inserted 2 in q1\n");

    n = return_first(q1);
    printf("First digit is %d in q1\n", n);
    n = return_last(q1);
    printf("Last digit is %d in q1\n", n);
    insert(q2,n);
    printf("Inserted %d in q2\n", n);

    n = remove_item(q1);
    printf("Removed %d from q1\n", n);
    insert(q2,n);
    printf("Inserted %d in q2\n", n);

    destroy(q1);

    while(!is_empty(q2)){
        printf("Removed %d from q2\n", remove_item(q2));
    }

    insert(q2,3);
    printf("Inserted 3 in q2\n");

    if(is_empty(q2)){
        printf("q2 is empty\n");
    } else {
        printf("q2 is not empty\n");
    }

    destroy(q2);

    return 0;
}
