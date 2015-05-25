#include <iostream>
using namespace std;

#include <conio.h>
#include "cvaternion.h"

int main()
{
    Cvaternion a, b;
    Type alfa;
    char choise=0;

    setlocale(LC_ALL, "rus");

    while(choise!=27)
    {
        choise=0;

        cout<<"1-сложить кватернионы\n";
        cout<<"2-умножить кватернионы\n";
        cout<<"3-умножить кватернион на число\n";
        cout<<"4-модуль кватерниона\n";
        cout<<"ESC-выход\n";

        choise=getch();

        switch(choise)
        {
        case '1':
            {
                cout<<endl;
                cout<<"введите первый кватернион:\n";
                a.input();
                cout<<endl;
                cout<<"введите второй кватернион:\n";
                b.input();

                cout<<endl<<endl;
                a.print();
                cout<<" + ";
                b.print();
                cout<<" = ";
                Cvaternion c=a+b;
                c.print();
                break;
            }
        case '2':
            {
                cout<<endl;
                cout<<"введите первый кватернион:\n";
                a.input();
                cout<<endl;
                cout<<"введите второй кватернион:\n";
                b.input();

                cout<<endl<<endl;
                a.print();
                cout<<" * ";
                b.print();
                cout<<" = ";
                Cvaternion c=a*b;
                c.print();
                break;
            }
        case '3':
            {
                cout<<endl;
                cout<<"введите кватернион:\n";
                a.input();
                cout<<endl;
                cout<<"введите альфа:\n";
                cin>>alfa;

                cout<<endl<<endl;
                a.print();
                cout<<" * "<<alfa;
                cout<<" = ";
                Cvaternion c=a*alfa;
                c.print();
                break;
            }
        case '4':
            {
                cout<<endl;
                cout<<"введите кватернион:\n";
                a.input();

                cout<<endl<<endl;
                cout<<"| ";
                a.print();
                cout<<" | = "<<a.module();
                break;
            }
        }

        cout<<endl<<endl;
    }

    return 0;
}
