/*
ID: evan11401
TASK: preface
LANG: C++                 
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


int main (){
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int n,n1000,n100,n10,n1;
	fin>>n;
    int num[7]={};
    for(int i=1;i<=n;i++){
        int number=i;
        if(number>=1000){
            n1000 = number/1000;
            number%=1000;
            num[6]+=n1000;
        }
        if(number>=100){
            n100 = number/100;
            number%=100;
            if(n100<4){
                num[4]+=n100;
            }
            else if(n100>=9){
                num[6]++;
                num[4]++;
            }
            else{
                num[5]++;
                num[4]+=abs(n100-5);
            }
        }
        if(number>=10){
            n10 = number/10;
            number%=10;
            if(n10<4){
                num[2]+=n10;
            }
            else if(n10>=9){
                num[4]++;
                num[2]++;
            }
            else{
                num[3]++;
                num[2]+=abs(n10-5);
            }
        }
        n1 = number;
        if(n1<4){
            num[0]+=n1;
        }
        else if(n1>=9){
            num[2]++;
            num[0]++;
        }
        else{
            num[1]++;
            num[0]+=abs(n1-5);
        }
        fout<<i<<" "<<n1000<<" "<<n100<<" "<<n10<<" "<<n1<<endl;
    }

    for(int i=0;i<7;i++){
        if(num[i]!=0){
            if(i==0)fout<<"I "<<num[i]<<endl;
            if(i==1)fout<<"V "<<num[i]<<endl;
            if(i==2)fout<<"X "<<num[i]<<endl;
            if(i==3)fout<<"L "<<num[i]<<endl;
            if(i==4)fout<<"C "<<num[i]<<endl;
            if(i==5)fout<<"D "<<num[i]<<endl;
            if(i==6)fout<<"M "<<num[i]<<endl;
        }
    }



	return 0;
}
