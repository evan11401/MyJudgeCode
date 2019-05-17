#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
using namespace std;
const int MAX = 46341;
int prime_num=0;
int prime[80000],primeNUM[80000];
void findPirme(){

    for(int i=2;i<216;i++){
        for(int j=i*i;j<MAX;j+=i){
            prime[j]=1;
        }
    }
    prime[0]=prime[1]=1;
    for(int i=2;i<MAX;i++){
        if(prime[i]==0){
            primeNUM[prime_num++]=i;
            //cout<<i<<endl;
        }
    }
    //for(int i=0;i<prime_num;i++)cout<<primeNUM[i]<<endl;
}
bool isPrime(int in){
    //return true;
    if(in<MAX){
        if(prime[in]==0)return true;
        else return false;
    }
    for(int i=0;i<prime_num;i++){
        if(in%primeNUM[i]==0)return false;
    }
    return true;
}
LL l,u,minD,maxD,mina,minb,maxa,maxb,lastp;
int main(){
    findPirme();
    while(cin>>l>>u){
        minD=2147483647;
        maxD=0;
        mina=minb=maxa=maxb=lastp=-1;
        for(LL i=l;i<=u;i++){
            if(isPrime(i)){
                
                if(lastp==-1){
                    lastp=i;
                }else{
                    
                    if(i-lastp<minD){
                        
                        mina=lastp;
                        minb=i;
                        minD=i-lastp;
                    }
                    if(i-lastp>maxD){
                        maxa=lastp;
                        maxb=i;
                        maxD=i-lastp;
                    }
                    lastp=i;
                }
            }
        }
        
        if(mina==-1){
            cout<<"There are no adjacent primes.\n";
        }else{
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",mina,minb,maxa,maxb);
        }
    }
}