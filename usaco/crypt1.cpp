/*
ID: evan11401
TASK: crypt1
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

int set[10];

int can(int w,int p,int down,int up){
	if(w*p<down||w*p>up)return 0;
	for(int i=w*p;i;i/=10) if(!set[i%10]) return 0;
	return 1;
}

int main (){
	ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
	int a;
	fin >> a;
	while(a--){
		int b;
		fin >>b;
		set[b]=1;
	}
	int ans=0;
	for(int i=1;i<10;i++)
		if(set[i])
			for(int j=0;j<10;j++)
				if(set[j])
					for(int p=0;p<10;p++)
						if(set[p])
							for(int k=1;k<10;k++)
								if(set[k]&&can(100*i+10*j+p,k,100,1000))
									for(int q=0;q<10;q++)
										if(set[q]&&can(100*i+10*j+p,q,100,1000)&&can(100*i+10*j+p,10*k+q,1000,10000))
											ans++;											
						
	
	fout<<ans<<endl;
	return 0;
}
