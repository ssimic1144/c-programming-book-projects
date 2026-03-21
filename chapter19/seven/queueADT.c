#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node{
    int data;
    struct node *next;
};

struct queue_type{
    int num_of_items;
    struct node *first;
    struct node  *last;
};

static void terminate(const char *message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(){
    struct queue_type *q = malloc(sizeof(struct queue_type));
    if(q == NULL){
        terminate("Can not create queue.");
    }

    q->first = NULL;
    q->last = NULL;

    return q;
}

void insert(Queue q, int i){
    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL){
        terminate("Can not create new node.\n");
    }

    new_node->data = i;
    new_node->next = NULL;

    if(is_empty(q)){
        q->first = new_node;
        q->last = new_node;
    } else {
        q->last->next = new_node;
        q->last = new_node;
    }

    q->num_of_items++;
}

int remove_item(Queue q){
    int i;
    struct node *temp;

    if(!is_empty(q)){
        i = q->first->data;

        temp = q->first;

        q->first = q->first->next;

        free(temp);

        q->num_of_items--;
        return i;
    } else {
        terminate("Queue is empty! Can't remove.");
    }
}

int return_first(Queue q){
    return q->first->data;
}

int return_last(Queue q){
    return q->last->data;
}

bool is_empty(Queue q){
    return q->num_of_items == 0;
}

void destroy(Queue q){
    while(!is_empty(q)){
        remove_item(q);
    }
    free(q);
}

