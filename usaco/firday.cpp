/*
ID: evan11401
TASK: friday
LANG: C++                 
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

int main (){
	ofstream fout ("friday.out");
    ifstream fin ("friday. in");
	
	int n,a,b;
	while(fin >> n){
		int year=1900;
		int day[7]={};
		int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		int q=6;
		for(int i=year;i<year+n;i++){
			
			for(int j=0;j<12;j++){	
				day[q]++;
				//fout << q<<endl;
				if(j==11&&i==year+n-1)break;							
				if(j==1&&i%4==0){	
					if(i%100==0){
						if(i%400==0){
							q+=(d[j]+1)%7;
							q%=7;
						}else{
							q+=d[j]%7;
							q%=7;
						}												
					}else{
						q+=(d[j]+1)%7;
						q%=7;
					}											
				}else{
					q+=d[j]%7;
					q%=7;
				}
			}
		}		
		fout << day[6] << " "<<day[0] << " "<<day[1] << " "<<day[2] << " "<<day[3] << " "<<day[4] << " "<<day[5] << endl;
		
		
	}
	
	
	return 0;
}
