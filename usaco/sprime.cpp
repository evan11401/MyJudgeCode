/*
ID: evan11401
TASK: sprime
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
#define MAX 10000000

using namespace std;

bool sieve[MAX];
 
void eratosthenes()
{
    int sqrt_11 = sqrt(MAX);
    sieve[0] = sieve[1] = true;
    for (int i=2; i<=sqrt_11; i++)
        if (!sieve[i])
            for (int k=(MAX-1)/i, j=i*k; k>=i; k--, j-=i)
                if (!sieve[k])
                    sieve[j] = true;
}


int main (){
	ofstream fout ("sprime.out");
        ifstream fin ("sprime.in");
	int a;
	fin>>a;
	eratosthenes();
	int ma=1;
	for(int i=0;i<a;i++)
		ma*=10;
	for(int i=ma/10;i<ma;i++){
		int num = i;
		bool chk=true;
		for(int j=0;j<a;j++){
			if(sieve[num]){
				chk = false;
				break;
			}
			//fout<<i<<":"<<num<<endl;
			num/=10;
		}
		if(chk)fout<<i<<endl;

	}

	return 0;
}
