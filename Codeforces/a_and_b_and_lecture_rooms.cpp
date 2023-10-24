// Task statement: https://codeforces.com/problemset/problem/519/E
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
const int MAXN=1e5+7,LOG=18;
int n,q,a,b;
vector<int> G[MAXN];
int lca[LOG][MAXN];
int depth[MAXN];
int amount[MAXN];
void DFS(int x,int pre){
	lca[0][x]=pre;
	depth[x]=depth[pre]+1;
	for(int v:G[x]){
		if(v!=pre) DFS(v,x);
	}
	for(int v:G[x]){
		if(v!=pre) amount[x]+=amount[v];
	}
	++amount[x];
}
int x,y;
int LCA(int v,int u){
	if(depth[v]<depth[u]) swap(v,u);
	for(int i=LOG-1;i>=0;--i){
		if(depth[v]-(1<<i)>=depth[u]) v=lca[i][v];
	}
	if(v==u) return v;
	for(int i=LOG-1;i>=0;--i){
		if(lca[i][v]!=lca[i][u]){
			v=lca[i][v];
			u=lca[i][u];
		}
	}
	x=v; y=u;
	return lca[0][v];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	depth[1]=-1;
	DFS(1,1);
	for(int i=1;i<LOG;++i){
		for(int j=1;j<=n;++j){
			lca[i][j]=lca[i-1][lca[i-1][j]];
		}
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		cin>>a>>b;
		int vert=LCA(a,b);
		int dist=depth[a]+depth[b]-2*depth[vert];
		if(a==b){
			cout<<n<<"\n";
		}else if(dist%2==1) cout<<"0\n";
		else{
			if(depth[a]<depth[b]) swap(a,b);
			dist>>=1;
			int dist2=dist-1;
			int bef=a;
			for(int j=LOG-1;j>=0;--j){
				if(dist-(1<<j)>=0){
					dist-=(1<<j);
					a=lca[j][a];
				}
			}
			for(int j=LOG-1;j>=0;--j){
				if(dist2-(1<<j)>=0){
					dist2-=(1<<j);
					bef=lca[j][bef];
				}
			}
			if(a==vert){
				if(x==y) y=0;
				cout<<n-amount[x]-amount[y]<<"\n";
			}else{
				cout<<amount[a]-amount[bef]<<"\n";
			}
		}
	}
}
