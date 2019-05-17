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
const int MAXN = 20;
struct Node{
	bool have_value;
	int v;
	Node *left,*right;
	Node()
	:have_value(false),left(NULL),right(NULL){}
};
Node *root;

string s;
bool failed;
Node* newnode(){return new Node();}
void addnode(int v,string pos){
	Node *u = root;
	for(int i=0;i<pos.size();i++){
		if(pos[i]=='L'){
			if(u->left == NULL)u->left = newnode();
			u = u->left;
		}else if(pos[i]=='R'){
			if(u->right == NULL)u->right = newnode();
			u = u->right;
		}
	}
	if(u->have_value) failed = true;
	u->v = v;
	u->have_value=true;
}
bool bfs(vector<int>& ans){
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while(!q.empty()){
		Node *u = q.front();q.pop();
		if(!u->have_value)return false;
		ans.pb(u->v);
		if(u->left !=NULL)q.push(u->left);
		if(u->right != NULL)q.push(u->right);
	}
	return true;
}
void remove_tree(Node *u){
	if(u==NULL)return;
	remove_tree(u->left);
	remove_tree(u->right);
	delete u;
}
bool read_input(){
	failed = false;
	remove_tree(root);
	root = newnode();
	while(1){
		if(!(cin>>s))return false;
		if(s=="()")break;
		int v=0,i=1;
		for(;s[i]!=',';i++)v=10*v+s[i]-'0';
		i++;string pos="";
		for(;s[i]!=')';i++)pos+=s[i];
		addnode(v,pos);
	}
	return true;
}
int main(){
	while(read_input()){
		vector<int> ans;
		
		if(!bfs(ans) || failed){
			cout<<"not complete\n";
		}else{
			for(int i=0;i<ans.size();i++){
				cout<<(i==0?"":" ")<<ans[i];
			}
			cout<<endl;
		}
		
	}
}
