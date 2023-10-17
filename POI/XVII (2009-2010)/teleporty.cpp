//Task statement: szkopul.edu.pl/problemset/problem/unYhfsxoVEsb1O89HLtzjWc5/site/
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
const int MAXN=4e4+7,MAXM=1e6+7;
vector<int> G[MAXN];
int dist[MAXN];
int layer[MAXN];
pii edges[MAXM];
int cnt[7];
int used[7][7];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
		edges[i]={a,b};
	}
	for(int i=1;i<=n;++i) dist[i]=INF;
	dist[1]=0;
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		int vert=Q.front(); Q.pop();
		for(int &v:G[vert]){
			if(dist[v]>dist[vert]+1){
				dist[v]=dist[vert]+1;
				Q.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i) layer[i]=(dist[i]<3?dist[i]:6);
	layer[2]=5;
	for(int i=1;i<=n;++i) dist[i]=INF;
	dist[2]=0;
	Q.push(2);
	while(!Q.empty()){
		int vert=Q.front(); Q.pop();
		for(int &v:G[vert]){
			if(dist[v]>dist[vert]+1){
				dist[v]=dist[vert]+1;
				if(dist[v]==1) Q.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(dist[i]<=2) layer[i]=5-dist[i];
	}
	vector<int> rest;
	for(int i=1;i<=n;++i) if(layer[i]==6) rest.pb(i);
	for(int i=1;i<=n;++i) ++cnt[layer[i]];
	if(cnt[1]>=cnt[4]){
		for(int &v:rest){
			layer[v]=2;
			++cnt[2];
		}
	}else{
		for(int &v:rest){
			layer[v]=3;
			++cnt[3];
		}
	}
	for(int i=1;i<=m;++i){
		if(layer[edges[i].first]>layer[edges[i].second]) swap(edges[i].first,edges[i].second);
		++used[layer[edges[i].first]][layer[edges[i].second]];
	}
	ll ans=0;
	for(int i=1;i<=4;++i){
		ll pot=((ll)cnt[i]*(cnt[i]-1))/2-used[i][i];
		ans+=pot;
	}
	for(int i=1;i<=3;++i){
		ll pot=((ll)cnt[i]*cnt[i+1])-used[i][i+1];
		ans+=pot;
	}
	cout<<ans<<"\n";
}
