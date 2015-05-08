#include <memory>
#include <iostream>
using namespace std;
#include "queue.h"

Queue *queue_init()
{
    Queue *q=new Queue;

    q->begin=0;
    q->end=0;

    return q;
}

void queue_push(Queue *q, Data data)
{
    Node *alloc;

    alloc=new (std::nothrow) Node;
    if(alloc==0)
    {
        cout<<"out of memory\n";
        return;
    }

    alloc->next=0;
    alloc->data=data;

    if(q->end==0)
    {
        q->end=q->begin=alloc;
        return;
    }

    q->end->next=alloc;
    q->end=alloc;
}

Data queue_pop(Queue *q)
{
    Data data;
    Node *i;

    if(q->begin==q->end)
    {
        q->end=0;
        data=q->begin->data;
        delete q->begin;
        q->begin=0;
        return data;
    }

    i=q->begin;
    data=i->data;
    q->begin=q->begin->next;
    delete i;

    return data;
}

void queue_free(Queue *q)
{
    Node *i=q->begin, *del;

    while(i)
    {
        del=i;
        i=i->next;
        delete del;
    }

    delete q;
}
