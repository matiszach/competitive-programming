// Task statement: https://codeforces.com/problemset/problem/1473/E
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
const int MAXN=8e5+7;
vector<pii> G[MAXN];
void make_edge(int a,int b,int c){
	//0 -> 0 0
	G[a*4].pb({b*4,c});
	G[a*4].pb({b*4+1,0});
	G[a*4].pb({b*4+2,c*2});
	G[a*4].pb({b*4+3,c});
	//1 -> 0 1 (-max)
	G[a*4+1].pb({b*4+1,c});
	G[a*4+1].pb({b*4+3,c*2});
	//2 -> 1 0 (+min)
	G[a*4+2].pb({b*4+2,c});
	G[a*4+2].pb({b*4+3,0});
	//3 -> 1 1 (-max + min)
	G[a*4+3].pb({b*4+3,c});
}
ll dist[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=m;++i){
		int a,b,c; cin>>a>>b>>c;
		make_edge(a,b,c);
		make_edge(b,a,c);
	}
	priority_queue<pli> Q;
	Q.push({0,4});
	for(int i=0;i<MAXN;++i) dist[i]=INFLL;
	dist[4]=0;
	while(!Q.empty()){
		pli vert=Q.top(); Q.pop();
		if(-vert.first>dist[vert.second]) continue;
		for(pii &v:G[vert.second]){
			if(-vert.first+v.second<dist[v.first]){
				dist[v.first]=-vert.first+v.second;
				Q.push({-dist[v.first],v.first});
			}
		}
	}
	for(int i=2;i<=n;++i) cout<<dist[i*4+3]<<" ";
	cout<<"\n";
}
