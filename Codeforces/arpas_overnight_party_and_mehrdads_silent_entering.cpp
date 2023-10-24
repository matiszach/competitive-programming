// Task statement: https://codeforces.com/problemset/problem/741/C
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
const int MAXN=1e5+7;
vector<int> G[MAXN*2];
int a,b;
pii edges[MAXN];
bool res[MAXN*2];
bitset<MAXN*2> visited;
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		edges[i]={a,b};
		G[a].pb(b);
		G[b].pb(a);
	}
	for(int i=1;i<=n;++i){
		G[i*2-1].pb(i*2);
		G[i*2].pb(i*2-1);
	}
	for(int i=1;i<=2*n;++i){
		if(visited[i]) continue;
		queue<int> to_visit;
		to_visit.push(i);
		visited[i]=1;
		while(!to_visit.empty()){
			int vert=to_visit.front(); to_visit.pop();
			for(int v:G[vert]){
				if(!visited[v]){
					visited[v]=1;
					res[v]=!res[vert];
					to_visit.push(v);
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		cout<<(res[edges[i].first]?1:2)<<" "<<(res[edges[i].second]?1:2)<<"\n";
	}
}
