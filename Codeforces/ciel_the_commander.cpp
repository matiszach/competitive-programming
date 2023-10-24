// Task statement: https://codeforces.com/problemset/problem/321/C
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
list<pii> G[MAXN];
int amount[MAXN];
pair<list<pii>::iterator,list<pii>::iterator> edge[MAXN];
int centroid(int x,int pre,int N){
	int maxi=0,pos=0;
	for(pii v:G[x]){
		if(v.first!=pre){
			if(maxi<amount[v.first]){
				maxi=amount[v.first];
				pos=v.first;
			}
		}
	}
	if(maxi<=N/2) return x;
	return centroid(pos,x,N);
}
void set_dp(int x,int pre){
	for(pii v:G[x]) if(v.first!=pre) set_dp(v.first,x);
	amount[x]=1;
	for(pii v:G[x]) if(v.first!=pre) amount[x]+=amount[v.first];
}
int res[MAXN];
void decompose(int x,int pre,int letter){
	set_dp(x,x);
	int vert=centroid(x,x,amount[x]);
	res[vert]=letter;
	vector<pii> neigs;
	for(pii v:G[vert]) neigs.pb(v);
	for(pii v:neigs){
		if(v.first<vert){
			G[v.first].erase(edge[v.second].first);
			G[vert].erase(edge[v.second].second);
		}else{
			G[v.first].erase(edge[v.second].second);
			G[vert].erase(edge[v.second].first);
		}
		decompose(v.first,vert,letter+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		if(a>b) swap(a,b);
		G[a].push_front({b,i});
		G[b].push_front({a,i});
		edge[i]={G[a].begin(),G[b].begin()};
	}
	decompose(1,1,0);
	for(int i=1;i<=n;++i) cout<<char(res[i]+'A')<<" ";
	cout<<"\n";
}
