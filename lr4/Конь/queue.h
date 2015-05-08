#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "MoveSteed.h"

typedef Move Data;

struct Node
{
    Data data;
    Node *next, *previouse;
};

struct Queue
{
    Node *begin, *end;
};

void queue_push(Queue *q, Data data);
Data queue_pop(Queue *q);
Queue *queue_init();
void queue_free(Queue *q);

#endif // QUEUE_H_INCLUDED
