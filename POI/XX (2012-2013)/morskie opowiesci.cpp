//Task statement: szkopul.edu.pl/problemset/problem/CfSEK4ACOcAPaAfX29Fp7Tud/site/
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
const int MAXN=5e3+7,K=1e6+7;
vector<int> G[MAXN*2];
vector<pair<int,pii>> tales[MAXN];
bool visited[MAXN*2];
int dist[MAXN*2];
bool res[K];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b+MAXN);
		G[b].pb(a+MAXN);
		G[a+MAXN].pb(b);
		G[b+MAXN].pb(a);
	}
	for(int i=1;i<=k;++i){
		int a,b,c; cin>>a>>b>>c;
		tales[a].pb({i,{b,c}});
	}
	for(int i=1;i<=n;++i){
		if(G[i].empty()) continue;
		for(int j=0;j<MAXN*2;++j) visited[j]=0,dist[j]=0;
		queue<int> Q;
		visited[i]=1;
		Q.push(i);
		while(!Q.empty()){
			int vert=Q.front(); Q.pop();
			for(int v:G[vert]){
				if(!visited[v]){
					dist[v]=dist[vert]+1;
					visited[v]=1;
					Q.push(v);
				}
			}
		}
		for(pair<int,pii> &v:tales[i]){
			if(v.second.second%2&&dist[v.second.first+MAXN]<=v.second.second) res[v.first]=visited[v.second.first+MAXN];
			if(v.second.second%2==0&&dist[v.second.first]<=v.second.second) res[v.first]=visited[v.second.first];
		}
	}
	for(int i=1;i<=k;++i) cout<<(res[i]?"TAK":"NIE")<<"\n";
}
