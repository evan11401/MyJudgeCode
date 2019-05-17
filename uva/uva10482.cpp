#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int coinmaxn = 35;
const int maxn = 650;
int coinNum, sum, coin[coinmaxn];
int value[maxn][maxn];
int searchMin(int a,int b,int c){
    return max(max(a,b),c) - min(min(a,b),c);
}
int main(){
    int n;
    cin>>n;
    //cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cin>>coinNum;
        sum=0;
        for(int j=1;j<=coinNum;j++){
            cin>>coin[j];
            sum+=coin[j];
        }
        //cout<<sum<<endl;
        memset(value,0,sizeof(value));
        int minAns = 999999;
        value[0][0]=1;
        for(int j=1;j<=coinNum;j++){
            for(int k=sum;k>=0;k--){
                for(int m=sum;m>=0;m--){
                    if(value[k][m]){
                        value[k+coin[j]][m]=1;
                        value[k][m+coin[j]]=1;
                    }
                }
            }
        }
        for(int j=0;j<=sum;j++){
            for(int k=0;k<=sum;k++){
                if(value[j][k]==1){
                    minAns = min(minAns, searchMin(j,k,sum-j-k));
                }
            }
        }
        cout<<"Case "<<i<<": "<<minAns<<endl;
    }
}