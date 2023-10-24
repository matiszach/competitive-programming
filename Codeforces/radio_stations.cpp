// Task statement: https://codeforces.com/problemset/problem/1215/F
// *Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=16e5+7;
vector<int> sat[MAXN],rsat[MAXN];
void make_edge(int A,int B){
	sat[A].pb(B);
	rsat[B].pb(A);
}
void make_implication(int A,int B){
	make_edge(A^1,B);
	make_edge(B^1,A);
}
bitset<MAXN> visited;
bitset<MAXN> solution;
vector<int> postorder;
int color;
int colors[MAXN];
void DFS(int x){
	visited[x]=1;
	for(int v:sat[x]){
		if(!visited[v]) DFS(v);
	}
	postorder.pb(x);
}
void rDFS(int x){
	colors[x]=color;
	for(int v:rsat[x]){
		if(colors[v]==0) rDFS(v);
	}
}
int n,p,M,m,a,b;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>p>>M>>m;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		--a; --b;
		make_implication(a*2,b*2);
	}
	for(int i=0;i<p;++i){
		cin>>a>>b;
		if(a!=1) make_implication((a-2+p)*2,i*2+1);
		if(b!=M) make_implication((b-1+p)*2+1,i*2+1);
	}
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		--a; --b;
		make_implication(a*2+1,b*2+1);
	}
	for(int i=2;i<M;++i){
		make_implication((i-2+p)*2,(i-1+p)*2+1);
	}
	for(int i=0;i<MAXN;++i){
		if(!visited[i]) DFS(i);
	}
	for(int i=postorder.size()-1;i>=0;--i){
		if(colors[postorder[i]]==0){
			++color;
			rDFS(postorder[i]);
		}
	}
	vector<int> res;
	for(int i=0;i<p+M-1;++i){
		if(colors[i*2]==colors[i*2+1]){
			cout<<"-1\n";
			return 0;
		}
		if(colors[i*2]>colors[i*2+1]) res.pb(i);
	}
	int f=1;
	vector<int> stat;
	for(int v:res){
		if(v<p) stat.pb(v);
		else f=max(f,v-p+2);
	}
	cout<<(int)stat.size()<<" "<<f<<"\n";
	for(int v:stat) cout<<v+1<<" ";
	cout<<"\n";
}
