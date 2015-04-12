#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

#include <conio.h>
#include <time.h>

typedef int Arr;

Arr **alloc(int sz)
{
    Arr **a=new (std::nothrow) Arr*[sz];

    if(a==0)
        return 0;

    for(int i=0; i<sz; i++)
    {
        a[i]=new (std::nothrow) Arr[i+1];
        if(a[i]==0)
        {
            for(int j=i-1; j>=0; j--)
                delete[]a[j];
            delete[]a;

            return 0;
        }
    }

    return a;
}

void init(Arr **a, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            a[i][j]=rand()%10;
        }
    }
}

void print(Arr **a, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
            cout<<a[i][j]<<' ';
        for(int k=i+1; k<n; k++)
            cout<<a[k][i]<<' ';
        cout<<'\n';
    }
}

void print_mul(const Arr **a, const Arr **b, int n)
{
    Arr s;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            s=0;

            for(int k=0; k<=i; k++)
            {
                if(k<j)
                    s+=a[i][k]*b[j][k];
                else
                    s+=a[i][k]*b[k][j];
            }
            for(int k=i+1; k<n; k++)
            {
                if(k<j)
                    s+=a[k][i]*b[j][k];
                else
                    s+=a[k][i]*b[k][j];
            }
            cout<<s<<' ';
        }
        cout<<endl;
    }
}

void free(Arr **a, int n)
{
    for(int i=0; i<n; i++)
        free(a[i]);
    free(a);
}

int main()
{
    int  n=4;
    char choise=0;
    Arr **a=alloc(n), **b=alloc(n);

    srand(time(NULL));
    init(a, n);
    init(b, n);

    setlocale(LC_ALL, "rus");

    while(choise!=27)
    {
        cout<<"1-ввод размера матрицы\n";
        cout<<"2-вывод первой матрицы\n";
        cout<<"3-вывод второй матрицы\n";
        cout<<"4-вывод произведения матриц\n";
        cout<<"5-разделитель\n";
        cout<<"ESC-выход\n\n";

        choise=getch();

        switch(choise)
        {
        case '1':
            {
                while(1)
                {
                    do
                    {
                        cout<<"введите размер матрицы: ";
                        cin>>n;
                    }
                    while(n<=0);

                    free(a);
                    free(b);
                    a=alloc(n);
                    b=alloc(n);

                    if(a && b)
                    {
                        srand(time(NULL));
                        init(a, n);
                        init(b, n);
                        break;
                    }

                    cout<<"не удалось выделить память под матрицы такого размера\n";
                }

                break;
            }

        case '2':
            {
                print(a, n);
                cout<<endl;
                break;
            }
        case '3':
            {
                print(b, n);
                cout<<endl;
                break;
            }
        case '4':
            {
                print(a, n);
                cout<<endl<<'*'<<endl;
                print(b, n);
                cout<<endl<<'='<<endl;
                print_mul((const Arr**)a, (const Arr**)b, n);
                cout<<endl;
                break;
            }
        case '5':
            cout<<'\n';
            break;
        }

        cout<<'\n';
    }

    free(a);
    free(b);

    return 0;
}
