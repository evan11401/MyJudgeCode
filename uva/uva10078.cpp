#include <iostream>

using namespace std;

struct point{
    int x,y;
};
point p[1005];
int cross(point o, point a, point b) {
    return (a.x - o.x)*(b.y - o.y) -
        (a.y - o.y)*(b.x - o.x);
}
int main(){

    int a;
    while(cin>>a&&a!=0){
        for(int i=0;i<a;i++){
            cin>>p[i].x>>p[i].y;
        }
        p[a] = p[0];
        p[a+1] = p[1];
        int i;
        if(cross(p[0],p[1],p[2])>=0){
            for(i=0;i<a;i++)
                if(cross(p[i],p[i+1],p[i+2])<0)
                    break;
        }else{
            for(i=0;i<a;i++)
                if(cross(p[i],p[i+1],p[i+2])>=0)
                    break;
        }

        if(i==a){
            cout<<"No"<<endl;
        }else
            cout<<"Yes"<<endl;
    }
}