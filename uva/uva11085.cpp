#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int container[8];
int Queens[100][8];
int nofQ=0;
bool row[8]={0},lleft[15]={0},rightt[15]={0};
void eightQueen(int c){
    if(c==8){
        for(int i=0;i<8;i++){
            Queens[nofQ][i]=container[i]+1;
        }
        nofQ++;
        return;
    }
    for(int r=0;r<8;r++){
        int ld = c-r+7;
        int rd = c+r;
        if(!row[r]&&!rightt[rd]&&!lleft[ld]){
            row[r]=1;
            lleft[ld]=1;
            rightt[rd]=1;
            container[c]=r;
            eightQueen(c+1);
            row[r]=0;
            lleft[ld]=0;
            rightt[rd]=0;
        }
    }
    
}
int main(){
    eightQueen(0);
    int in[8],ccase=1;
    while(cin>>in[0]){
        for(int i=1;i<8;i++){
            cin>>in[i];
        }
        int minn = 99999999;
        
        for(int i=0;i<nofQ;i++){
            int sum=0;
            for(int j=0;j<8;j++){
                //cout<<sum<<endl;
                if(Queens[i][j]!=in[j])
                    sum++;
                    //sum+=(abs(Queens[i][j]-in[j]));

            }
            
            minn = min(sum,minn);
        }
        cout<<"Case "<<ccase++<<": "<<minn<<endl;
    }
}