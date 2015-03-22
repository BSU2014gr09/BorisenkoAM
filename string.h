#ifndef STRINSSS_H_INCLUDED
#define STRINSSS_H_INCLUDED

struct Nodes
{
    char data;
    Nodes *next, *previous;
};

struct String
{
    Nodes *begin;
};

int str_length(String *s);

bool str_cmp(String *s1, String *s2);
void str_concat(String *s1, String *s2);
void str_push(String *s, char data);
void str_copy(String *str1, String *str2);
void str_clear(String *s);
void str_print(String *s);
String *str_init(const char *c);
void str_free(String *s);

#endif // STRINSSS_H_INCLUDED
