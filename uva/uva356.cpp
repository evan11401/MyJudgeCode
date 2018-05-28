#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    bool fir=true;
    while(cin>>n){
        double r=n-0.5;
        int all=0,part=0;
        for(int x=0;x<n;x++)
            for(int y=0;y<n;y++){
                double d1 = sqrt(x*x+y*y);
                double d2 = sqrt((x+1)*(x+1)+(y+1)*(y+1));
                if(d2<=r) all++;
                else if(d1<r) part++;
            }
        if(fir) fir=false;
        else cout<<endl;
        cout<<"In the case n = "<<n<<", "<<part*4<<" cells contain segments of the circle.\nThere are "<<all*4<<" cells completely contained in the circle.\n";
    }
}