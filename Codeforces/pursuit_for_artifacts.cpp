// Task statement: https://codeforces.com/problemset/problem/652/E
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
const int MAXN=3e5+7;
vector<pair<int,bool>> G[MAXN];
int preorder[MAXN],low[MAXN];
int postorder[MAXN];
int idx=0;
bitset<MAXN> visited;
int parent[MAXN];
vector<pii> bridges;
map<pii,bool> brgs;
void DFS(int x,int pre){
	visited[x]=1;
	parent[x]=pre;
	low[x]=preorder[x]=++idx;
	for(auto p:G[x]){
		if(p.first!=pre){
			if(visited[p.first]) low[x]=min(low[x],preorder[p.first]);
			else DFS(p.first,x);
		}
	}
	for(auto p:G[x]) if(preorder[x]<preorder[p.first]) low[x]=min(low[x],low[p.first]);
	postorder[x]=idx;
	if(pre!=0&&low[x]>preorder[pre]) brgs[{x,pre}]=1;
}
bool anc(int v,int u){
	return (preorder[v]<=preorder[u]&&postorder[v]>=postorder[u]);
}
int colors[MAXN];
int color;
vector<int> cols[MAXN];
void DFS2(int x){
	colors[x]=color;
	cols[color].pb(x);
	for(auto p:G[x]){
		if(colors[p.first]==0&&brgs.find({x,p.first})==brgs.end()&&brgs.find({p.first,x})==brgs.end()){
			DFS2(p.first);
		}
	}
}
bitset<MAXN> checked;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m,a,b; cin>>n>>m;
	bool c;
	for(int i=1;i<=m;++i){
		cin>>a>>b>>c;
		G[a].pb({b,c});
		G[b].pb({a,c});
		if(c) bridges.pb({a,b});
	}
	int x,y; cin>>x>>y;
	DFS(x,0);
	for(int i=1;i<=n;++i){
		if(colors[i]==0){
			++color;
			DFS2(i);
		}
	}
	if(colors[x]==colors[y]){
		for(auto p:bridges){
			if(colors[p.first]==colors[p.second]&&colors[p.second]==colors[x]){
				cout<<"YES\n";
				return 0;
			}
		}
		cout<<"NO\n";
	}else{
		for(auto p:bridges){
			if(anc(p.first,y)&&anc(p.second,y)&&anc(x,p.first)&&anc(x,p.second)){
				cout<<"YES\n";
				return 0;
			}
			if(!checked[colors[p.first]]&&colors[p.first]==colors[p.second]){
				checked[colors[p.first]]=1;
				for(int v:cols[colors[p.first]]){
					if(anc(v,y)&&anc(x,v)){
						cout<<"YES\n";
						return 0;
					}
				}
			}
		}
		cout<<"NO\n";
	}
}
