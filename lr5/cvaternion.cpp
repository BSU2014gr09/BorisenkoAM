#include <iostream>
using namespace std;
#include "cvaternion.h"
#include <math.h>

void Cvaternion::input()
{
    cout<<"вещественная часть "; cin>>real;
    cout<<"i "; cin>>i;
    cout<<"j "; cin>>j;
    cout<<"k "; cin>>k;
}

void Cvaternion::print()
{
    if(real)
        cout<<real;

    if(i)
    {
        if(real)
        {
            if(i==1)
                cout<<"+i";
            else if(i==-1)
                cout<<"-i";
            else if(i>0)
                cout<<"+"<<i<<'i';
        }
        else
        {
            if(i==1)
                cout<<"i";
            else if(i==-1)
                cout<<"-i";
            else
                cout<<i<<'i';
        }
    }

    if(j)
    {
        if(real || i)
        {
            if(j==1)
                cout<<"+j";
            else if(j==-1)
                cout<<"-j";
            else if(j>0)
                cout<<"+"<<j<<'j';
        }
        else
        {
            if(j==1)
                cout<<"j";
            else if(j==-1)
                cout<<"-j";
            else
                cout<<j<<'j';
        }
    }

    if(k)
    {
        if(real || i || j)
        {
            if(k==1)
                cout<<"+k";
            else if(k==-1)
                cout<<"-k";
            else if(k>0)
                cout<<"+"<<k<<'k';
        }
        else
        {
            if(k==1)
                cout<<"k";
            else if(k==-1)
                cout<<"-k";
            else
                cout<<k<<'k';
        }
    }

    if(real==0 && i==0 && j==0 && k==0)
        cout<<'0';
}

void Cvaternion::conjugation()
{
    i=-i;
    j=-j;
    k=-k;
}

Type Cvaternion::module()
{
    return sqrt(i*i+j*j+k*k+real*real);
}

Cvaternion::Cvaternion(const Cvaternion &a)
{
    real=a.real;
    i=a.i;
    j=a.j;
    k=a.k;
}

Cvaternion::Cvaternion()
{
    real=i=j=k=0;
}

const Cvaternion Cvaternion::operator+(const Cvaternion &a)
{
    Cvaternion c;

    c.real=a.real+real;
    c.i=a.i+i;
    c.j=a.j+j;
    c.k=a.k+k;

    return c;
}

const Cvaternion Cvaternion::operator-(const Cvaternion &a)
{
    Cvaternion c;

    c.real=real-a.real;
    c.i=i-a.i;
    c.j=j-a.j;
    c.k=k-a.k;

    return c;
}

const Cvaternion Cvaternion::operator*(const Cvaternion &a)
{
    Cvaternion c;

    c.real=a.real*real-a.i*i-a.j*j-a.k*k;
    c.i=a.real*i+real*a.i + a.j*k-a.k*j;
    c.j=a.real*j+real*a.j + a.k*i-a.i*k;
    c.k=a.real*k+real*a.k + a.i*j-a.j*i;

    return c;
}

const Cvaternion Cvaternion::operator*(const Type &a)
{
    Cvaternion c;

    c.real=a*real;
    c.i=a*i;
    c.j=a*j;
    c.k=a*k;

    return c;
}

const Cvaternion Cvaternion::operator/(const Type &a)
{
    Cvaternion c;

    c.real=real/a;
    c.i=i/a;
    c.j=j/a;
    c.k=k/a;

    return c;
}

const Cvaternion Cvaternion::operator=(const Cvaternion &a)
{
    Cvaternion c;

    real=c.real=a.real;
    i=c.i=a.i;
    j=c.j=a.j;
    k=c.k=a.k;

    return c;
}

void Cvaternion::set_real(Type real)
{
    this->real=real;
}

void Cvaternion::set_i(Type i)
{
    this->i=i;
}

void Cvaternion::set_j(Type j)
{
    this->j=j;
}

void Cvaternion::set_k(Type k)
{
    this->k=k;
}

Type Cvaternion::get_real()
{
    return real;
}

Type Cvaternion::get_i()
{
    return i;
}

Type Cvaternion::get_j()
{
    return j;
}

Type Cvaternion::get_k()
{
    return k;
}
