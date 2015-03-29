#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "string.h"

struct Data
{
    String *data;
    int count;
};

struct Node
{
    Data data;
    Node *next;
};

struct Hash
{
    Node *begin;
};

Hash* hash_init();
void hash_free(Hash *h);
void hash_add(Hash *h, String *data);
void hash_print(Hash *h);

#endif // HASH_H_INCLUDED 
