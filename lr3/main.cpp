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
                cvaternion_input(a);
                cout<<endl;
                cout<<"введите второй кватернион:\n";
                cvaternion_input(b);

                cout<<endl<<endl;
                cvaternion_print(a);
                cout<<" + ";
                cvaternion_print(b);
                cout<<" = ";
                cvaternion_print(cvaternion_plus(a, b));
                break;
            }
        case '2':
            {
                cout<<endl;
                cout<<"введите первый кватернион:\n";
                cvaternion_input(a);
                cout<<endl;
                cout<<"введите второй кватернион:\n";
                cvaternion_input(b);

                cout<<endl<<endl;
                cvaternion_print(a);
                cout<<" * ";
                cvaternion_print(b);
                cout<<" = ";
                cvaternion_print(cvaternion_mul(a, b));
                break;
            }
        case '3':
            {
                cout<<endl;
                cout<<"введите кватернион:\n";
                cvaternion_input(a);
                cout<<endl;
                cout<<"введите альфа:\n";
                cin>>alfa;

                cout<<endl<<endl;
                cvaternion_print(a);
                cout<<" * "<<alfa;
                cout<<" = ";
                cvaternion_print(cvaternion_mul(a, alfa));
                break;
            }
        case '4':
            {
                cout<<endl;
                cout<<"введите кватернион:\n";
                cvaternion_input(a);

                cout<<endl<<endl;
                cout<<"| ";
                cvaternion_print(a);
                cout<<" | = "<<cvaternion_module(a);
                break;
            }
        }

        cout<<endl<<endl;
    }

    return 0;
}
