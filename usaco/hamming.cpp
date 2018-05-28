/*
ID: evan11401
TASK: hamming
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int check(int a,int b)  
{  
     int k=0;  
     while (a || b)  
     {  
          if (a%2!=b%2) k++;  
          a/=2;  
          b/=2;               
     }  
     return k;  
}   
int n,b,d;
int main (){
	ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");	
	fin >>n>>b>>d;
	int ans[100]={};
    int anss = 1;
    int last=0;
    for(int i=1;i<n;i++){
        int now = last+1;
        while(1){
            bool chk = false;
            for(int j=0;j<i;j++)
                if(check(now,ans[j])<d){
                    chk = true;
                    break;
                }
            if(!chk){
                ans[i] = now;
                last = now;
                break;
            }
            else
                now++;
        }
    }

    for(int i=0;i<n;i++){
        if(i%10==0&&i>0)fout<<endl;
        if(i%10!=0)fout<<" ";
        fout<<ans[i];
    }
    fout<<endl;
	return 0;
}
