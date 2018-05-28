/*
ID: evan11401
TASK: runround
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

int main (){
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    int n;
    bool find = false;
	fin>>n;
    while(!find){
        string next = to_string(++n);
        int chk[10]={};
        char start = next[0];
        int nn = 0;
        int i;
        bool isZe = false;
        for(i=0;i<next.size()-1;i++){
            
            int j;
            for(j=i+1;j<next.size();j++){
                if(next[i]==next[j])break;
            }
            if(j!=next.size())break;
        }
        for(int ii=0;ii<next.size();ii++){
            if(next[ii]-'0'==0){
                isZe = true;
                break;
            }
        }
        //fout<<next<<" "<<i<<" "<<isZe<<endl;
        if(i!=next.size()-1)continue;
        if(isZe)continue;
        //fout<<"1"<<endl;
        do{
            //fout<<next[nn]<<" ";
            nn=(nn+(next[nn]-'0'))%next.size();
            //fout<<next[nn]<<endl;
            if(chk[next[nn]-'0']){
                find = false;
                break;
            }else{
                chk[next[nn]-'0']++;
                find = true;
            }
        }while(start!=next[nn]);
        for(i=0;i<next.size();i++){
            if(!chk[next[i]-'0']){
                find = false;
                break;
            }
        }
        if(find){
            fout<<n<<endl;
        }
    }

	return 0;
}
