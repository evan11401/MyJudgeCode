
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>//set_union��?�b???��󨽭��F
using namespace std;//set vector���ݭn�ϥΩR�W��?�~��ϥΡF
typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;
 
int ID(Set x)
{
    if(IDcache.count(x)) return IDcache[x];//map.count(r)�O�d�䤸��x�X?����?�F
    Setcache.push_back(x);
    return IDcache[x]=Setcache.size()-1;
}
 
#define ALL(x) x.begin(),x.end() // ��� �Ҧ�?�e
#define INS(x) inserter(x,x.begin()) //��� ���J���N��
 
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
