//Task statement: szkopul.edu.pl/problemset/problem/Mlar--JvS1gThazr04pNorHN/site/
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
const int MAXN=5e4+7,LOG=16,SQR=250;
int n,a,b;
int arr[MAXN];
int order[MAXN];
int K[MAXN];
vector<int> G[MAXN];
int lca[LOG][MAXN];
int idx;
int postorder[MAXN],preorder[MAXN];
int depth[MAXN];
int curr=0;
void DFS(int x,int pre){
	depth[x]=++curr;
	preorder[x]=++idx;
	lca[0][x]=pre;
	for(int v:G[x]){
		if(v!=pre) DFS(v,x);
	}
	postorder[x]=++idx;
	--curr;
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
int L[MAXN];
vector<int> quers[MAXN];
int res[MAXN];
int pref[MAXN];
void DFS2(int x,int pre,int diff){
	int start=x;
	if(depth[x]<=diff) start=0;
	else{
		for(int i=LOG-1;i>=0;--i){
			if(diff&(1<<i)){
				start=lca[i][start];
			}
		}
	}
	pref[x]=pref[start]+arr[x];
	for(int v:quers[x]){
		int d=depth[x]-depth[L[v]];
		int e=(d+1)/K[v];
		d=(e+((d+1)%K[v]>0))*K[v];
		start=x;
		if(depth[x]<=d) start=0;
		else{
			for(int i=LOG-1;i>=0;--i){
				if(d&(1<<i)){
					start=lca[i][start];
				}
			}
		}
		res[v]+=pref[x]-pref[start];
	}
	quers[x].clear();
	for(int v:G[x]){
		if(v!=pre) DFS2(v,x,diff);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<n;++i){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	for(int i=1;i<=n;++i) cin>>order[i];
	for(int i=1;i<n;++i) cin>>K[i];
	DFS(1,1);
	for(int i=1;i<LOG;++i){
		for(int j=1;j<=n;++j){
			lca[i][j]=lca[i-1][lca[i-1][j]];
		}
	}
	for(int i=1;i<n;++i){
		L[i]=LCA(order[i],order[i+1]);
	}
	for(int i=1;i<n;++i){
		if(K[i]>=SQR){
			int d1=depth[order[i]]-depth[L[i]];
			int d2=depth[order[i+1]]-depth[L[i]];
			int amount=d1/K[i];
			int start=order[i];
			res[i]+=arr[start];
			for(int j=1;j<=amount;++j){
				for(int k=LOG-1;k>=0;--k){
					if(K[i]&(1<<k)) start=lca[k][start];
				}
				res[i]+=arr[start];
			}
			amount=d2/K[i];
			start=order[i+1];
			res[i]+=arr[start];
			for(int j=1;j<=amount;++j){
				for(int k=LOG-1;k>=0;--k){
					if(K[i]&(1<<k)) start=lca[k][start];
				}
				res[i]+=arr[start];
			}
			if(d1%K[i]==0) res[i]-=arr[L[i]];
		}
	}
	for(int i=1;i<SQR;++i){
		for(int j=1;j<n;++j){
			if(K[j]==i){
				quers[order[j]].pb(j);
				quers[order[j+1]].pb(j);
				int d=depth[order[j]]-depth[L[j]];
				if(d%i==0) res[j]-=arr[L[j]];
			}
		}
		DFS2(1,1,i);
	}
	for(int i=1;i<n;++i) cout<<res[i]<<"\n";
}
