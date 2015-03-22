/*специально для гитхаба все русские слова в кодировке UTF-8*/

#include <iostream>
#include <fstream>
using namespace std;
#include <conio.h>

#include "Hash.h"

bool is_symbol(char c)
{
    if((c>='A' && c<='Z')||(c>='a' && c<='z')||(c>='А' && c<='Я')||(c>='а' && c<='я')||c=='ё'||c=='Ё'||(c>='0' && c<='9'))
        return true;
    return false;
}

void print_words_list_from_file(ifstream *f)
{
    Hash *h=hash_init();
    char ch;
    String *s=str_init("");

    ch=f->get();

    while(!f->eof())
    {
        while(!is_symbol(ch) && !f->eof())
            ch=f->get();

        while(is_symbol(ch) && !f->eof())
        {
            str_push(s, ch);
            ch=f->get();
        }

        hash_add(h, s);
        str_clear(s);
    }

    hash_print(h);
    hash_free(h);
}

int main()
{
    ifstream f;
    char name[256], key;
    bool noexit=true;

    setlocale(LC_ALL, "rus");

    while(noexit)
    {
        cout<<"1-вывести все слова в файле, если повторяются-их количество\n";
        cout<<"ESC-выход\n\n";

        key=getch();

        switch(key)
        {
            case '1':
                {
                    cout<<"введите имя файла: ";
                    while(1)
                    {
                        cin.getline(name, 256);

                        f.open(name, ios::in);
                        if(f)
                        {
                            cout<<endl;
                            print_words_list_from_file(&f);
                            cout<<endl;
                            break;
                        }
                        else
                            cout<<"такого файла нет, попробуйте ещё раз: ";
                    }
                    f.close();
                    break;
                }
            case 27:
                {
                    noexit=false;
                    break;
                }
        }
        key=0;
    }

    return 0;
}
