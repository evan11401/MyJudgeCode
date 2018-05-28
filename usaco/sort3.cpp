/*
ID: evan11401
TASK: sort3
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

int main (){
	ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
	int n;
    int ans[1005]={};
    int num[4]={};
    int total=0;
	fin >>n;
	for(int i=0;i<n;i++){
        fin>>ans[i];
        num[ans[i]]++;
    }
    //  for(int q=0;q<n;q++)
    //     fout<<ans[q]<<" ";
    // fout<<endl;
    for(int i=0;i<num[1];i++){
        if(ans[i]==1)continue;
        else{
            int start = ans[i] == 2?num[1]:num[1]+num[2];
            int end = ans[i] == 2 ? num[1]+num[2] : n;
            int j;
            for (j = start; j < end; j++)
            {
                if (ans[j] == 1)
                {
                    ans[j] = ans[i];
                    ans[i] = 1;
                    total++;
                    break;
                }
            }        
            if (j == end)
            {
                if (ans[i] == 2)
                {
                    start =  num[1]+num[2]-1;
                    end = n;
                }
                else
                {
                    start = num[1]-1;
                    end = num[1]+num[2];
                }
                for (j = start; j < end; ++j)
                {
                    if (ans[j] == 1)
                    {
                        ans[j] = ans[i];
                        ans[i] = 1;
                        ++total;
                        break;
                    }
                }
            }  
        }        
    }
    // for(int q=0;q<n;q++)
    //     fout<<ans[q]<<" ";
    // fout<<total<<endl;
    for(int i=num[1]+num[2];i<=n;i++){
        if(ans[i]==2)
            total++;          
         
    }
 
    fout<<total<<endl;
    
	return 0;
}
