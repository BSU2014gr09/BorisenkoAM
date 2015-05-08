#include "list.h"

List *list_init()
{
    List *l=new List;

    l->begin=0;
    l->end=0;

    return l;
}

void list_push(List *l, Coord data)
{
    ListNode *alloc=new ListNode;

    alloc->data[0]=data[0];
    alloc->data[1]=data[1];
    alloc->next=0;

    if(l->begin==0)
    {
        l->begin=alloc;
        l->end=alloc;
        return;
    }

    l->end->next=alloc;
    l->end=alloc;
}

void list_copy(List *a, List *b)
{
    ListNode *i=b->begin;

    while(i)
    {
        list_push(a, i->data);
        i=i->next;
    }
}

void list_free(List *l)
{
    ListNode *del, *i=l->begin;

    while(i)
    {
        del=i;
        i=i->next;
        delete del;
    }

    delete l;
}
