#include "string_sort.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

bool sort_criteria(char *a, char *b)
{
    int sz, n1=0, n2=0;
    char *s, *p;

    sz=strlen(a);
    s=new char[sz+1];
    s[sz]=0;
    strcpy(s,a);
    p=strtok(s, " !@#$%^&*()+");

    while(p)
    {
        for(int i=0; i<strlen(p); i++)
        {
            if(isdigit(p[i]))
            {
                n1++;
                break;
            }
        }
        p=strtok(0, " !@#$%^&*()+");
    }

    delete [] s;

    sz=strlen(b);
    s=new char[sz+1];
    s[sz]=0;
    strcpy(s,b);
    p=strtok(s, " !@#$%^&*()+");

    while(p)
    {
        for(int i=0; i<strlen(p); i++)
        {
            if(isdigit(p[i]))
            {
                n2++;
                break;
            }
        }
        p=strtok(0, " !@#$%^&*()+");
    }

    delete [] s;

    if(n1>n2)
        return true;
    return false;
}

void string_sort(const char *file_name)
{
    ifstream fin(file_name);
    char **a=new char*[128];
    char buf[128];
    int n=0;
    int l;

    if(!fin.is_open())
        return;

    while(!fin.eof())
    {
        fin.getline(buf, 128);
        l=strlen(buf);
        a[n]=new char[l+1];
        a[n][l]=0;
        strcpy(a[n], buf);
        n++;
    }

    fin.close();

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(sort_criteria(a[i], a[j]))
            {
                char *tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }

    ofstream fout(file_name);

    for(int i=0; i<n; i++)
        fout<<a[i]<<endl;

    for(int i=0; i<n; i++)
        delete[]a[i];
    delete[]a;

    fout.close();
}
