#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;

Queue create(void);
void insert(Queue q, int i);
int remove_item(Queue q);
int return_first(Queue q);
int return_last(Queue q);
bool is_empty(Queue q);
void destroy(Queue q);

#endif
