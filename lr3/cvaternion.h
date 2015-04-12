#ifndef CVATERNION_H_INCLUDED
#define CVATERNION_H_INCLUDED

typedef float Type;

struct Cvaternion
{
    Type real,
         i,
         j,
         k;
};

void cvaternion_input(Cvaternion &a);
void cvaternion_print(Cvaternion a);
Cvaternion cvaternion_plus(Cvaternion a, Cvaternion b);
Cvaternion cvaternion_mul(Cvaternion a, Cvaternion b);
Cvaternion cvaternion_mul(Cvaternion a, Type alfa);
void cvaternion_conjugation(Cvaternion &a);
Type cvaternion_module(Cvaternion a);

#endif // CVATERNION_H_INCLUDED
