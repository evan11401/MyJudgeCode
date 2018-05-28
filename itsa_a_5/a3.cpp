#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long num[50];
    while(n--){
        bool flag=true;
        long long nn;
        cin>>nn;
        for(long long i=0;i<nn;i++){
            cin>>num[i];
        }
        if(nn==2){
            cout<<num[0]+num[1]<<endl;
            continue;
        }
        sort(num,num+nn);
        long long a=0,b=0;
        for(long long i=0;i<nn;i++){
            if(num[i]==0){
                long long z=0;
                long long j;
                for(j=0;j<nn-2;j++){
                    if(num[j]==0)z++;
                    if(num[j])break;
                }
                a = num[j];
                b = num[j+1];
                if(a==0){
                    long long ten=1;
                    /*for(long long aa=0;aa<z;aa++)ten*=10ll;
                    b*=ten;*/
                    cout<<b<<string(z,'0')<<endl;
                    flag=false;
                    break;
                }else{
                    long long ten=1;
                    for(long long aa=0;aa<z/2;aa++)ten*=10ll;
                    if(z&1){
                        a = a*ten*10ll;
                        b = b*ten;
                    }else{
                        a*=ten;
                        b*=ten;
                    }
                }
                i=j+2;
            }
            if(i>=nn)break;
            if(a>=b){
                b = b*10ll+num[i];
            }else{
                a = a*10ll+num[i];
            }
        }
        if(flag)
            cout<<a+b<<endl;


        
    }
}