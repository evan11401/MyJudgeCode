#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int a[1000005];
int main(){
    int x;
    while(cin>>x){
        getchar();
        string s;
        int n=0;
        getline(cin,s);
        stringstream ss(s);
        while(ss>>a[n]){n++;}
        long long int sum=0;
        long long int exp=1;
        //cout<<n<<endl;
        for(int i=1;i<n;i++){
            sum+=(i*a[n-i-1]*exp);
            exp*=x;
        }
        int ans = sum;
        cout<<ans<<endl;
    }
}