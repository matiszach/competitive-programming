//Task statement: szkopul.edu.pl/problemset/problem/bLHHUzy1-byoiJSbilgpI6Dc/site/
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
const int MAXN=1e6+7;
int n,a,b;
vector<int> G[MAXN];
int dp_size[MAXN],dp_depth[MAXN];
ll dp_cost[MAXN];
void DFS(int x,int pre){
	for(int v:G[x]){
		if(v!=pre) DFS(v,x);
	}
	dp_size[x]=1;
	for(int v:G[x]){
		if(v!=pre){
			dp_size[x]+=dp_size[v];
			dp_cost[x]+=dp_cost[v];
			dp_depth[x]=max(dp_depth[x],dp_depth[v]);
		}
	}
	dp_cost[x]+=dp_size[x];
	++dp_depth[x];
}
ll res[MAXN];
int biggest,vert;
ll cost;
void DFS2(int x,int pre,int pre_size,int pre_depth,ll pre_cost){
	biggest=pre_size;
	vert=pre;
	for(int v:G[x]){
		if(v!=pre){
			if(dp_size[v]>biggest){
				biggest=dp_size[v];
				vert=v;
			}
		}
	}
	cost=pre_cost;
	for(int v:G[x]) if(v!=pre) cost+=dp_cost[v];
	if(biggest*2-1==n-1){
		//bierzemy najdalszy wierzcholek z poddrzewa "vert"
		if(vert==pre) res[x]=cost*2-pre_depth;
		else res[x]=cost*2-dp_depth[vert];
	}else if(biggest*2>=n){
		//brak odpowiedzi smuteczek
		res[x]=-1;
	}else{
		//obliczamy normalnie i bierzemy najdalszy wierzcholek z dowolnego poddrzewa
		int deepest=pre_depth;
		for(int v:G[x]) if(v!=pre) deepest=max(deepest,dp_depth[v]);
		res[x]=cost*2-deepest;
	}
	if((int)G[x].size()==1&&x!=1) return;
	//najpierw glebokosc
	int st=pre_depth,nd=0,pos=0;
	for(int v:G[x]){
		if(v!=pre){
			if(st<dp_depth[v]){
				st=dp_depth[v];
				pos=v;
			}
		}
	}
	if(pos!=0) nd=pre_depth;
	for(int v:G[x]){
		if(v!=pre){
			if(v!=pos&&nd<dp_depth[v]){
				nd=dp_depth[v];
			}
		}
	}
	//potem wielkosc
	//potem koszt
	ll total_cost=pre_cost;
	for(int v:G[x]) if(v!=pre) total_cost+=dp_cost[v];
	for(int v:G[x]){
		if(v!=pre){
			//idziemy do synow wierzcholka dajac im zaktualizowane wartosci ojca
			int new_depth=(st==dp_depth[v]?nd:st)+1;
			int new_size=n-dp_size[v];
			ll new_cost=total_cost+new_size-dp_cost[v];
			DFS2(v,x,new_size,new_depth,new_cost);
		}
	}
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
	DFS(1,0);
	DFS2(1,0,0,0,0);
	for(int i=1;i<=n;++i) cout<<res[i]<<"\n";
}

