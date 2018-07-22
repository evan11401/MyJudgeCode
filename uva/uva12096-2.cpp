
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>//set_union函?在???文件里面；
using namespace std;//set vector等需要使用命名空?才能使用；
typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;
 
int ID(Set x)
{
    if(IDcache.count(x)) return IDcache[x];//map.count(r)是查找元素x出?的次?；
    Setcache.push_back(x);
    return IDcache[x]=Setcache.size()-1;
}
 
#define ALL(x) x.begin(),x.end() // 表示 所有?容
#define INS(x) inserter(x,x.begin()) //表示 插入迭代器
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        stack<int> s;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            string op;
            cin>>op;
            if(op=="PUSH")
            {
                s.push(ID(Set()));
            }
            else if(op=="DUP") s.push(s.top());
            else
            {
                Set x1=Setcache[s.top()];
                s.pop();
                Set x2=Setcache[s.top()];
                s.pop();
                Set x;
                if(op=="UNION") set_union (x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                if(op=="INTERSECT") set_intersection (x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                if(op=="ADD")
                {
                    x=x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout<<Setcache[s.top()].size()<<endl;
        }
        printf("***\n");
    }
    return 0;
}
