//Task statement: szkopul.edu.pl/problemset/problem/owcaRjm1cAGxst32bd_-elx6/site/
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
vector<pii> G[MAXN];
bool used[MAXN];
int amount[MAXN];
int order[MAXN];
void DFS(int x,int pre){
	for(pii v:G[x]) if(v.first!=pre&&!used[v.first]) DFS(v.first,x);
	amount[x]=1;
	for(pii v:G[x]) if(v.first!=pre&&!used[v.first]) amount[x]+=amount[v.first];
}
int centroid(int x,int pre,int N){
	int vert=0;
	for(pii v:G[x]){
		if(v.first!=pre&&!used[v.first]){
			if(amount[v.first]>amount[vert]) vert=v.first;
		}
	}
	if(amount[vert]<=N/2) return x;
	return centroid(vert,x,N);
}
int colors[MAXN];
void DFS_color(int x,int pre,int color){
	colors[order[x]]=color;
	for(pii v:G[x]) if(v.first!=pre&&!used[v.first]) DFS_color(v.first,x,color);
}
int dist[MAXN],dist_ord[MAXN];
void DFS_dist(int x,int pre,int last){
	dist[x]=dist[pre]+last;
	dist_ord[order[x]]=dist[x];
	for(pii v:G[x]) if(v.first!=pre&&!used[v.first]) DFS_dist(v.first,x,v.second);
}
ll res[MAXN];
void decompose(int x,vector<int> nums){
	if(nums.size()<=1) return;
	DFS(x,x);
	int vert=centroid(x,x,amount[x]);
	//magic
	colors[order[vert]]=0;
	int curr_color=0;
	for(pii v:G[vert]){
		if(!used[v.first]){
			DFS_color(v.first,vert,++curr_color);
		}
	}
	vector<vector<int>> V(curr_color+1,vector<int>());
	for(int v:nums){
		V[colors[v]].pb(v);
	}
	vector<ll> counter(curr_color+1);
	vector<int> cnt(curr_color+1);
	dist[vert]=0;
	DFS_dist(vert,vert,0);
	ll total=0;
	int v_count=0;
	for(int v:nums){
		res[v]+=((ll)dist_ord[v]*(v_count-cnt[colors[v]])+(total-counter[colors[v]]))*2;
		total+=dist_ord[v];
		++v_count;
		counter[colors[v]]+=dist_ord[v];
		++cnt[colors[v]];
	}
	//end of magic
	used[vert]=1;
	int idx=0;
	for(pii v:G[vert]){
		if(!used[v.first]){
			decompose(v.first,V[++idx]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<n;++i){
		int a,b,c; cin>>a>>b>>c;
		G[a].pb({b,c});
		G[b].pb({a,c});
	}
	order[1]=1;
	for(int i=1;i<=m;++i){
		int x; cin>>x;
		order[x]=i+1;
	}
	vector<int> castles;
	for(int i=1;i<=m+1;++i) castles.pb(i);
	decompose(1,castles);
	ll ans=0;
	for(int i=2;i<=m+1;++i){
		ans+=res[i];
		cout<<ans<<"\n";
	}
}
