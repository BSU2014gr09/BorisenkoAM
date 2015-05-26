#include <iostream>
using namespace std;

#include <conio.h>
#include "cvaternion.h"

int main()
{
    Cvaternion a, b, c;
    Type alfa=4;
    char choise=0;

    setlocale(LC_ALL, "rus");

    a.set_realijk(0, 1, 0, 0);
    b.set_realijk(0, 0, 0, 1);

    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"alfa="<<alfa<<endl;

    cout<<"a+b="<<a+b<<endl;
    cout<<"a*b="<<a*b<<endl;
    cout<<"a*alfa="<<a*alfa<<endl;

    return 0;
}
