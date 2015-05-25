#include <iostream>
using namespace std;
#include "cvaternion.h"
#include <math.h>

void cvaternion_input(Cvaternion &a)
{
    cout<<"вещественная часть "; cin>>a.real;
    cout<<"i "; cin>>a.i;
    cout<<"j "; cin>>a.j;
    cout<<"k "; cin>>a.k;
}

void cvaternion_print(Cvaternion a)
{
    if(a.real)
        cout<<a.real;

    if(a.i)
    {
        if(a.real)
        {
            if(a.i==1)
                cout<<"+i";
            else if(a.i==-1)
                cout<<"-i";
            else if(a.i>0)
                cout<<"+"<<a.i<<'i';
        }
        else
        {
            if(a.i==1)
                cout<<"i";
            else if(a.i==-1)
                cout<<"-i";
            else
                cout<<a.i<<'i';
        }
    }

    if(a.j)
    {
        if(a.real || a.i)
        {
            if(a.j==1)
                cout<<"+j";
            else if(a.j==-1)
                cout<<"-j";
            else if(a.j>0)
                cout<<"+"<<a.j<<'j';
        }
        else
        {
            if(a.j==1)
                cout<<"j";
            else if(a.j==-1)
                cout<<"-j";
            else
                cout<<a.j<<'j';
        }
    }

    if(a.k)
    {
        if(a.real || a.i || a.j)
        {
            if(a.k==1)
                cout<<"+k";
            else if(a.k==-1)
                cout<<"-k";
            else if(a.k>0)
                cout<<"+"<<a.k<<'k';
        }
        else
        {
            if(a.k==1)
                cout<<"k";
            else if(a.k==-1)
                cout<<"-k";
            else
                cout<<a.k<<'k';
        }
    }

    if(a.real==0 && a.i==0 && a.j==0 && a.k==0)
        cout<<'0';
}

Cvaternion cvaternion_plus(Cvaternion a, Cvaternion b)
{
    Cvaternion c;

    c.i=a.i+b.i;
    c.j=a.j+b.j;
    c.k=a.k+b.k;
    c.real=a.real+b.real;

    return c;
}

Cvaternion cvaternion_mul(Cvaternion a, Type alfa)
{
    Cvaternion c;

    c.real=a.real*alfa;
    c.i=a.i*alfa;
    c.j=a.j*alfa;
    c.k=a.k*alfa;

    return c;
}

void cvaternion_conjugation(Cvaternion &a)
{
    a.i=-a.i;
    a.j=-a.j;
    a.k=-a.k;
}

Cvaternion cvaternion_mul(Cvaternion a, Cvaternion b)
{
    Cvaternion c;

    c.real=a.real*b.real-a.i*b.i-a.j*b.j-a.k*b.k;
    c.i=a.real*b.i+b.real*a.i + a.j*b.k-a.k*b.j;
    c.j=a.real*b.j+b.real*a.j + a.k*b.i-a.i*b.k;
    c.k=a.real*b.k+b.real*a.k + a.i*b.j-a.j*b.i;

    return c;
}

Type cvaternion_module(Cvaternion a)
{
    return sqrt(a.i*a.i+a.j*a.j+a.k*a.k+a.real*a.real);
}
