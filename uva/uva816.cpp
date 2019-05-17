#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LL long long
const int MAXN = 10+5;

struct Node{
	int r,c,dir;
	Node(int rr=0,int cc=0,int dirr=0):r(rr),c(cc),dir(dirr){}
};
const char* dirs = "NESW";
const char* turns = "FLR";
string name,s;
int dir_id(char c){return strchr(dirs, c) - dirs;}
int turn_id(char c){return strchr(dirs, c) - turns;}
int has_edge[MAXN][MAXN][4][4];
const int dr[]={-1,0,1,0};
const int dc[]={0,1,0,-1};
Node walk(const Node& u,int turn){
	int dir = u.dir;
	if(turn==1)dir = (dir+3)%4;
	if(turn==2)dir = (dir+1)%4;
	return Node(u.r+dr[dir],u.c+dc[dir],dir);
}
int d[MAXN][MAXN][4],rx,cx,r0,c0,r1,c1,r2,c2,dir,dirx,turnx;
Node p[MAXN][MAXN][4];
bool inside(int x,int y){
    return (x>0&&x<10&&y>0&&y<10);
}
void print_ans(Node u){
	vector<Node> nodes;
	for(;;){
		nodes.pb(u);
		if(d[u.r][u.c][u.dir]==0)break;
		u=p[u.r][u.c][u.dir];
	}
	nodes.pb(Node(r0,c0,dir));
	int cnt =0;
	for(int i=nodes.size()-1;i>=0;i--){
		if(cnt%10==0)cout<<" ";
		printf(" (%d,%d)",nodes[i].r,nodes[i].c);
		if(++cnt%10==0)cout<<"\n";
	}
	if(nodes.size() %10 !=0)cout<<endl;
}
void solve(){
	queue<Node> q;
	memset(d,-1,sizeof(d));
	Node u(r1,c1,dir);
	d[u.r][u.c][u.dir]=0;
	q.push(u);
	while(!q.empty()){
		Node u = q.front();q.pop();
		if(u.r==r2 && u.c==c2){
			print_ans(u);return;
		}
		for(int i=0;i<3;i++){
			Node v = walk(u,i);
			if(has_edge[u.r][u.c][u.dir][i] && inside(v.r,v.c) &&d[v.r][v.c][v.dir]<0){
				d[v.r][v.c][v.dir]=d[u.r][u.c][u.dir]+1;
				p[v.r][v.c][v.dir]=u;
				q.push(v);
			}
		}
	}
	cout<<"  No Solution Possible\n";
}

bool read(){
	cin>>name;
	if(name=="END")return false;
	cout<<name<<endl;
	memset(has_edge,0,sizeof(has_edge));
    memset(p,0,sizeof(p));
    cin>>r0>>c0>>s>>r2>>c2;
    for(int i=0;i<4;i++)
        if(s[0]==dirs[i]){
            dir=i;
            break;
        }
    r1=r0+dr[dir];
    c1=c0+dc[dir];
    while(cin>>rx&&rx){
    	cin>>cx;
    	while(cin>>s){
    		if(s=="*")break;
    		for(int i=0;i<4;i++)
                if(s[0]==dirs[i]){
                    dirx=i;
                    break;
                }
            for(int i=1;i<s.size();i++){
                for(int j=0;j<3;j++)
                    if(s[i]==turns[j]){
                        turnx=j;
                        break;
                    }
                has_edge[rx][cx][dirx][turnx]=true;
            }
		}
	}
	return true;
}
int main(){
	while(read()){
		solve();
	}
}
