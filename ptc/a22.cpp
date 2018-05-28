#include<iostream>
#include<vector>
using namespace std;

struct num{
    int next;
    int ind;
    num(int n,int i){
        next = n;
        ind = i;
    }
};

int main(){
    int n;
    cin>>n;
    while(n--){
        vector<num> numbers[505];
        int p,q,r;
        cin>>p>>q>>r;
        int x,y;
        cin>>x>>y;
        int i=0,j;
        num new_num(y,i);
        numbers[x].push_back(new_num);
        i=2;
        bool find = false;
        while(!find){
            int nextt = (q*x+r*(x-y)*(x-y)+y)%p;
            for(int ii=0;ii<numbers[y].size();ii++){
                if(numbers[y][ii].next==nextt){
                    j = numbers[y][ii].ind;
                    find = true;
                    break;
                }
            }
            if(find)break;
            num neww_num(nextt,i);
            numbers[y].push_back(neww_num);
            x = y;
            y = nextt;
            i++;
        }
        if(j==0)i--;
        cout<<i-j<<endl;
    }

}