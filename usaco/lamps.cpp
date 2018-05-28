/*
ID: evan11401
TASK: lamps
LANG: C++11            
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
ofstream fout ("lamps.out");
ifstream fin ("lamps.in");
int n,c,x;
int a[150],b[150],d[150];
long long q[150];
int t=0;
void init()
{
    fin>>n>>c;
    while((fin>>x)&&(x!=-1))
        a[x]=1;
    while((fin>>x)&&(x!=-1))
        b[x]=1;
}
void haha()
{
    for(int i=1;i<=n;i++)
        d[i]=1;
}
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if((a[i])&&(!d[i])) return 0;
        if((b[i])&&(d[i]))  return 0;
    }
    return 1;
}
void print()
{
    for(int i=1;i<=n;i++)
        fout<<d[i];
    fout<<endl; t++;
}
void doit1()
{
    for(int i=1;i<=n;i++)
        d[i]=(d[i])?0:1;
}
void doit2()
{
    for(int i=1;i<=n;i+=2)
        d[i]=(d[i])?0:1;
}
void doit3()
{
    for(int i=2;i<=n;i+=2)
        d[i]=(d[i])?0:1;
}
void doit4()
{
    for(int i=1;i<=n;i+=3)
        d[i]=(d[i])?0:1;
}
int main()
{
    init();
    haha();
    switch(c)
    {
        case 0:
            if(check()) print();
            break;
        case 1:
            haha(); doit1();
            if(check()) print();
            haha(); doit2();
            if(check()) print();
            haha(); doit3();
            if(check()) print();
            haha(); doit4();
            if(check()) print();
            break;
        case 2:
            haha(); doit1();
            if(check()) print();
            haha(); doit3(); doit4();
            if(check()) print();
            haha(); doit2();
            if(check()) print();
            haha(); doit1(); doit4();
            if(check()) print();
            haha(); doit3();
            if(check()) print();
            haha(); doit2(); doit4();
            if(check()) print();
            haha();
            if(check()) print();
            break;
        default:
            haha(); doit1();
            if(check()) print();
            haha(); doit3(); doit4();
            if(check()) print();
            haha(); doit2();
            if(check()) print();
            haha();doit4();
            if(check()) print();
            haha(); doit1(); doit4();
            if(check()) print();
            haha(); doit3();
            if(check()) print();
            haha(); doit2(); doit4();
            if(check()) print();
            haha();
            if(check()) print();
            break;
    }
    if(t==0){
        fout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
