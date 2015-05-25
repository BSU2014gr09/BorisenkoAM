#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class CarBase
{
private:
    struct Car
    {
        char data[11];
        char marka[50];
        int year;
        char color[10];
        int number;
    };
    int sz;
    Car *arr;

public:
    void load(char *name);
    void save(char *name);
    void print();
    void init(int n);
    void replace(int pos);
    void print_search(int year);
    void sort_by_year_produced();
    void add();
    bool remove(int pos);

    CarBase()
    {
        sz=0;
        arr=new Car[100];
    }
};

void CarBase::load(char *name)
{
    ifstream f(name);

    if(!f.is_open())
        return;

    f.read((char*)&sz, sizeof(int));

    for(int i=0; i<sz; i++)
    {
        f.read(arr[i].data, 10);
        f.read(arr[i].marka, 50);
        f.read((char*)&arr[i].year, sizeof(int));
        f.read(arr[i].color, 10);
        f.read((char*)&arr[i].number, sizeof(int));
    }

    f.close();
}

void CarBase::save(char *name)
{
    ofstream f(name);

    f.write((char*)&sz, sizeof(int));

    for(int i=0; i<sz; i++)
    {
        f.write(arr[i].data, 10);
        f.write(arr[i].marka, 50);
        f.write((char*)&arr[i].year, sizeof(int));
        f.write(arr[i].color, 10);
        f.write((char*)&arr[i].number, sizeof(int));
    }

    f.close();
}

void CarBase::print()
{
    for(int i=0; i<sz; i++)
    {
        cout<<"дата "<<arr[i].data<<" ";
        cout<<"марка "<<arr[i].marka<<" ";
        cout<<"год "<<arr[i].year<<" ";
        cout<<"цвет "<<arr[i].color<<" ";
        cout<<"номер "<<arr[i].number<<" ";

        cout<<endl;
    }
}

void CarBase::init(int n)
{
    sz=n;
    arr=new Car[sz];

    for(int i=0; i<n; i++)
    {
        cout<<"введите дату ";
        cin>>arr[i].data;
        cout<<"введите марку ";
        cin>>arr[i].marka;
        cout<<"введите год ";
        cin>>arr[i].year;
        cout<<"введите цвет ";
        cin>>arr[i].color;
        cout<<"введите номер ";
        cin>>arr[i].number;
        cout<<endl;
    }
}

void CarBase::replace(int pos)
{
    cout<<"введите дату ";
    cin>>arr[pos].data;
    cout<<"введите марку ";
    cin>>arr[pos].marka;
    cout<<"введите год ";
    cin>>arr[pos].year;
    cout<<"введите цвет ";
    cin>>arr[pos].color;
    cout<<"введите номер ";
    cin>>arr[pos].number;
    cout<<endl;
}

void CarBase::print_search(int year)
{
    for(int i=0; i<sz; i++)
    {
        if(arr[i].year>=year)
        {
            cout<<"дата "<<arr[i].data<<" ";
            cout<<"марка "<<arr[i].marka<<" ";
            cout<<"год "<<arr[i].year<<" ";
            cout<<"цвет "<<arr[i].color<<" ";
            cout<<"номер "<<arr[i].number<<" ";

            cout<<endl;
        }
    }
}

void CarBase::sort_by_year_produced()
{
    for(int i=0; i<sz; i++)
    {
        for(int j=i; j<sz; j++)
        {
            if(arr[i].year<arr[j].year)
            {
                Car tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}

void CarBase::add()
{
    cout<<"введите дату ";
    cin>>arr[sz].data;
    cout<<"введите марку ";
    cin>>arr[sz].marka;
    cout<<"введите год ";
    cin>>arr[sz].year;
    cout<<"введите цвет ";
    cin>>arr[sz].color;
    cout<<"введите номер ";
    cin>>arr[sz].number;
    cout<<endl;

    sz++;
}

bool CarBase::remove(int pos)
{
    if(pos<sz)
    {
        for(int i=pos; i<sz; i++)
            arr[i]=arr[i+1];
        sz--;
    }
}


int main()
{
    CarBase base;

    setlocale(LC_ALL, "rus");

    char key=0;

    while(1)
    {
        cout<<"1-загрузить базу"<<endl;
        cout<<"2-сохранить базу"<<endl;
        cout<<"3-поиск машин не старше года"<<endl;
        cout<<"4-сортировка по году выпуска"<<endl;
        cout<<"5-добавление машины"<<endl;
        cout<<"6-удаление машины"<<endl;
        cout<<"7-выход"<<endl;

        cin>>key;

        switch(key)
        {
            case '1': base.load("a.base"); base.print(); break;
            case '2': base.save("a.base"); cout<<"ok\n"; break;
            case '3':
                int year;
                cout<<"введите год "; cin>>year;
                base.print_search(year);
                break;
            case '4': base.sort_by_year_produced(); base.print(); break;
            case '5': base.add(); break;
            case '6':
                int pos;
                cout<<"введите номер машины ";
                cin>>pos;
                if(base.remove(pos))
                    cout<<"удалён\n";
                else
                    cout<<"нет такого элемента";
                break;
            case '7': return 0; break;
        }
    }

    return 0;
}
