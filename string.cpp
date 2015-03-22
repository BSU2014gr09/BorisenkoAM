#include <iostream>
using namespace std;
#include "string.h"

bool str_cmp(String *s1, String *s2)
{
    Nodes *i=s1->begin, *j=s2->begin;

    while(i && j)
    {
        if(i->data!=j->data)
            return false;
        i=i->next;
        j=j->next;
    }

    if(i!=j)
        return false;

    return true;
}

void str_push(String *s, char data)
{
    Nodes *count=s->begin, *alloc;

    if(count==0)
    {
        count=new Nodes;
        count->data=data;
        count->next=0;
        count->previous=0;
        s->begin=count;

        return;
    }

    while(count->next)
        count=count->next;

    alloc=new Nodes;
    alloc->data=data;
    alloc->next=0;
    alloc->previous=count;

    count->next=alloc;
}

String *str_init(const char *c)
{
    int i=1;
    String *s=new String;
    Nodes *count;

    s->begin=0;

    if(c[0])
    {
        count=new Nodes;
        count->data=c[0];
        count->next=0;
        count->previous=0;
        s->begin=count;
    }
    else return s;

    while(c[i])
    {
        count->next=new Nodes;
        count->next->data=c[i];
        count->next->previous=count;
        count=count->next;

        i++;
    }

    if(s->begin)
        count->next=0;

    return s;
}

void str_clear(String *s)
{
    Nodes *count=s->begin, *tmp;

    while(count)
    {
        tmp=count->next;
        delete count;
        count=tmp;
    }

    s->begin=0;
}

void str_copy(String *str1, String *str2)
{
    Nodes *count=str2->begin, *i=0;

    if(str1==str2)
        return;
    str_clear(str1);

    if(count)
    {
        i=new Nodes;
        i->data=count->data;
        i->next=0;
        i->previous=0;
        str1->begin=i;
        count=count->next;
    }

    while(count)
    {
        i->next=new Nodes;
        i->next->previous=i;
        i->next->data=count->data;
        i=i->next;

        count=count->next;
    }

    if(i)
        i->next=0;
}

void str_concat(String *s1, String *s2)
{
    Nodes *i=s1->begin, *count=s2->begin;
    int j, k;

    if(s1!=s2)
    {
        if(i)
        {
            while(i->next)
                i=i->next;
        }
        else
            str_copy(s1, s2);

        while(count)
        {
            i->next=new Nodes;
            i->next->previous=i;
            i->next->data=count->data;
            i=i->next;

            count=count->next;
        }

        if(i)
            i->next=0;
    }
    else if(i)
    {
        k=0;
        while(i->next)
        {
            i=i->next;
            k++;
        }

        for(j=0; j<=k; j++)
        {
            i->next=new Nodes;
            i->next->previous=i;
            i->next->data=count->data;
            i=i->next;

            count=count->next;
        }

        i->next=0;
    }
}

int str_length(String *s)
{
    int i=0;
    Nodes *count=s->begin;

    while(count)
    {
        count=count->next;
        i++;
    }

    return i;
}

void str_print(String *s)
{
    Nodes *i=s->begin;

    while(i)
    {
        cout<<(i->data);
        i=i->next;
    }
}

void str_free(String *s)
{
    Nodes *count=s->begin, *tmp;

    while(count)
    {
        tmp=count->next;
        delete count;
        count=tmp;
    }

    delete s;
}
