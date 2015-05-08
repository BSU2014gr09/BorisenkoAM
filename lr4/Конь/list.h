#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Math.h"

struct ListNode
{
    Coord data;
    ListNode *next;
};

struct List
{
    ListNode *begin, *end;
};

List *list_init();
void list_push(List *l, Coord data);
void list_copy(List *a, List *b);
void list_free(List *l);

#endif // LIST_H_INCLUDED
