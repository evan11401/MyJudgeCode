#include<iostream>
#include<string>
using namespace std;
int main(){
    int num=1;
    int n,m;
    while(cin>>n&&n!=0){
        string stdans,in,stuans;
        getchar();
        while(n--){
            getline(cin,in);
            stdans+=in;
            stdans+="\n";
        }
        cin>>m;
        getchar();
        while(m--){
            getline(cin,in);
            stuans+=in;
            stuans+="\n";
        }
        if(stdans==stuans)cout<<"Run #"<<num++<<": Accepted"<<endl;
        else{
            string stdnum;
            string stunum;
            for(int i=0;i<stdans.size();i++){
                if(stdans[i]>='0'&&stdans[i]<='9')stdnum+=stdans[i];
            }
            for(int i=0;i<stuans.size();i++){
                if(stuans[i]>='0'&&stuans[i]<='9')stunum+=stuans[i];
            }
            //cout<<stdnum<<" "<<stunum<<endl;
            if(stdnum==stunum)cout<<"Run #"<<num++<<": Presentation Error"<<endl;
            else cout<<"Run #"<<num++<<": Wrong Answer"<<endl;
        }
    }
}