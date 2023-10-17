//Task statement: szkopul.edu.pl/problemset/problem/JkT6CwdepjCQnJ9c6CwxHolZ/site/
//*Author Mateusz Kowalski*
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
const int MAXN=1e5+7;
vector<int> G[MAXN],D[MAXN];
int n,m,a,b;
bitset<MAXN> visited;
int preorder[MAXN],low[MAXN],amount[MAXN];
int parent[MAXN];
int idx;
bitset<MAXN> is_art;
int sons=0;
void DFS(int x,int pre){
	visited[x]=1;
	low[x]=preorder[x]=++idx;
	parent[x]=pre;
	for(int v:G[x]){
		if(v!=pre){
			if(visited[v]) low[x]=min(low[x],preorder[v]);
			else{
				if(pre==0) ++sons;
				D[x].pb(v);
				DFS(v,x);
			}
		}
	}
	for(int v:G[x]) if(preorder[x]<preorder[v]) low[x]=min(low[x],low[v]);
	int maxi=0;
	for(int v:G[x]) if(preorder[x]<preorder[v]) maxi=max(maxi,low[v]);
	if((pre==0&&sons>1)||(pre!=0&&maxi>=preorder[x])) is_art[x]=1;
}
void DFSD(int x){
	visited[x]=1;
	for(int v:D[x]) DFSD(v);
	for(int v:D[x]) amount[x]+=amount[v];
	++amount[x];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			sons=0;
			DFS(i,0);
		}
	}
	visited.reset();
	for(int i=1;i<=n;++i) if(!visited[i]) DFSD(i);
	for(int i=1;i<=n;++i){
		if(is_art[i]){
			ll ans=2*(n-1),total=0;
			for(int v:D[i]){
				if(low[v]>=preorder[i]){
					total+=amount[v];
					ans+=(ll)amount[v]*(n-1-amount[v]);
				}
			}
			ans+=total*(n-1-total);
			cout<<ans<<"\n";
		}else cout<<2*(n-1)<<"\n";
	}
}
