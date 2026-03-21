#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type{
    int empty_slot;
    int pos_next_to_remove;
    int num_of_items;
    int *queue_arr;
};

static void terminate(const char *message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(int len){
    struct queue_type *q = malloc(sizeof(struct queue_type));
    if(q == NULL){
        terminate("Can not create queue.");
    }
    q->empty_slot = 0;
    q->pos_next_to_remove = 0;
    q->num_of_items = 0;
    q->queue_arr = malloc(sizeof(int)*len);

    if(q->queue_arr == NULL){
        terminate("Can not allocate memory for queue array");
    }

    return q;
}

void insert(Queue q, int i){
    q->queue_arr[q->empty_slot++] = i;
    q->num_of_items++;
}

int remove_item(Queue q){
    int i;
    if(!is_empty(q)){
        i = q->queue_arr[q->pos_next_to_remove++];
        q->num_of_items--;
        return i;
    } else {
        terminate("Queue is empty! Can't remove.");
    }
}

int return_first(Queue q){
    return q->queue_arr[q->pos_next_to_remove];
}

int return_last(Queue q){
    return q->queue_arr[q->empty_slot-1];
}

bool is_empty(Queue q){
    return q->num_of_items == 0;
}

void destroy(Queue q){
    free(q->queue_arr);
    free(q);
}
