/*
ID: evan11401
TASK: pprime
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
	ofstream fout ("pprime.out");
        ifstream fin ("pprime.in");
	int a,b;
	fin>>a>>b;
	bool chk=true;
	eratosthenes();
	
	//for(int i=2;i<1000;i++)
	//	if(!sieve[i])
	//		fout<<i<<endl;
	for(int i=1;i<=9;i++){
		if(i<a)continue;
		if(i>b) break;
		if(!sieve[i])
			fout<<i<<endl;
	}
	for(int i=1;i<=9;i++){
		int x=i*10+i;
		if(x<a)continue;
                if(x>b) break;
                if(!sieve[x])
                        fout<<x<<endl;
	}
	for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
       		 for (int d3 = 0; d3 <= 9; d3++) {
	   		int palindrome = 100*d1 + 10*d3 + d1;
			if(palindrome<a) continue;
                        if(palindrome>b){
                                chk = false;
                                break;
                        }
                        if(!sieve[palindrome])
                                fout << palindrome<<endl;
		 }
	}
 
	for (int d1 = 1; d1 <= 9&&chk; d1+=2) {	/* only odd; evens aren't so prime */
 	   for (int d2 = 0; d2 <= 9&&chk; d2++) {
       		 for (int d3 = 0; d3 <= 9&&chk; d3++) {
		    int palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
		    if(palindrome<a) continue;
		    if(palindrome>b){
			    chk = false;
			    break;
		    }
		    if(!sieve[palindrome])
			    fout << palindrome<<endl;
		 }
   	   }
	}
	for(int d0=1;d0<=9&&chk;d0+=2){
	for (int d1 = 0; d1 <= 9&&chk; d1++) { /* only odd; evens aren't so prime */
             for (int d2 = 0; d2 <= 9&&chk; d2++) {
                   for (int d3 = 0; d3 <= 9&&chk; d3++) {
                      int palindrome = 1000000*d0+100000*d1 + 10000*d2 +1000*d3 + 100*d2 + 10*d1+d0;
                      if(palindrome<a) continue;
                      if(palindrome>b){
                              chk = false;
                              break;
                      }
                      if(!sieve[palindrome])
                              fout << palindrome<<endl;
                   }
             }
          }
	}

	return 0;
}
