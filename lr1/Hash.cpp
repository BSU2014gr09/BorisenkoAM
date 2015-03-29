#include <iostream>
#include <cstring>
using namespace std;

#include "Hash.h"

Hash* hash_init()
{
    Hash *h=new Hash;
    h->begin=0;
}

void hash_add(Hash *h, String *data)
{
    Node *i=h->begin, *tmp;

    if(i==0)
    {
        i=new Node;

        i->data.data=str_init("");
        str_copy(i->data.data, data);

        i->data.count=1;
        i->next=0;
        h->begin=i;
        return;
    }

    if(str_cmp(data, i->data.data)==true)
    {
        i->data.count++;
        return;
    }

    while(i->next)
    {
        i=i->next;
        if(str_cmp(data, i->data.data)==true)
        {
            i->data.count++;
            return;
        }
    }

    tmp=new Node;
    tmp->data.data=str_init("");
    str_copy(tmp->data.data, data);
    tmp->data.count=1;
    tmp->next=0;
    i->next=tmp;
}

void hash_print(Hash *h)
{
    Node *i=h->begin;

    while(i)
    {
        str_print(i->data.data);
        cout<<' '<<i->data.count<<endl;
        i=i->next;
    }
}

void hash_free(Hash *h)
{
    Node *i=h->begin, *del;

    while(i)
    {
        del=i;
        i=i->next;
        delete del;
    }

    delete h;
} 
