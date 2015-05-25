﻿#ifndef CVATERNION_H_INCLUDED
#define CVATERNION_H_INCLUDED

typedef float Type;

class Cvaternion
{
private:
    Type real, i, j, k;

public:
    void input();
    void print();

    void conjugation();
    Type module();

    const Cvaternion operator+(const Cvaternion &a);
    const Cvaternion operator-(const Cvaternion &a);
    const Cvaternion operator*(const Cvaternion &a);
    const Cvaternion operator*(const Type &a);
    const Cvaternion operator/(const Type &a);
    const Cvaternion operator=(const Cvaternion &a);

    void set_real(Type real);
    void set_i(Type i);
    void set_j(Type j);
    void set_k(Type k);

    Type get_real();
    Type get_i();
    Type get_j();
    Type get_k();

    Cvaternion(const Cvaternion &a);
    Cvaternion();
};



#endif // CVATERNION_H_INCLUDED
