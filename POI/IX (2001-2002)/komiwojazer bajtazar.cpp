//Task statement: szkopul.edu.pl/problemset/problem/-fb7NxSJGXxkJ2Om5FvXzbil/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=1e5+7,LOG=18;
int n,m,k;
int a,b,c,t;
vector<int> G[MAXN];
int depth[MAXN];
int lca[LOG][MAXN];
int preorder[MAXN],postorder[MAXN];
int idx;
void DFS(int x,int pre,int dep){
	lca[0][x]=pre;
	depth[x]=dep;
	preorder[x]=++idx;
	for(int v:G[x]){
		if(v!=pre) DFS(v,x,dep+1);
	}
	postorder[x]=++idx;
}
bool anc(int v,int u){
	if(v==u) return 1;
	return (preorder[v]<preorder[u]&&postorder[v]>postorder[u]);
}
int LCA(int v,int u){
	if(anc(v,u)) return v;
	if(anc(u,v)) return u;
	for(int i=LOG-1;i>=0;--i){
		if(!anc(lca[i][v],u)) v=lca[i][v];
	}
	return lca[0][v];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,1,0);
	for(int i=1;i<LOG;++i){
		for(int j=1;j<=n;++j){
			lca[i][j]=lca[i-1][lca[i-1][j]];
		}
	}
	cin>>m;
	int curr=1;
	ll total=0;
	while(m--){
		cin>>c;
		int vert=LCA(curr,c);
		total+=(depth[curr]+depth[c]-2*depth[vert]);
		curr=c;
	}
	cout<<total<<"\n";
}

