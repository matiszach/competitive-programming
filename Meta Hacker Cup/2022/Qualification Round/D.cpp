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
const int MAXN=2e5+7;
vector<pii> G[MAXN];
map<int,int> conns[MAXN];
map<int,vector<int>> queries[MAXN];
int s[MAXN];
ll res[MAXN];
void solve_case(){
	int n,m,q; cin>>n>>m>>q;
	for(int i=1;i<MAXN;++i){
		conns[i].clear();
		G[i].clear();
		G[i].shrink_to_fit();
		queries[i].clear();
		res[i]=0;
	}
	for(int i=1;i<=m;++i){
		int a,b,c; cin>>a>>b>>c;
		G[a].pb({b,c});
		G[b].pb({a,c});
	}
	for(int i=1;i<=n;++i){
		for(pii p:G[i]){
			conns[i][p.first]=p.second;
		}
	}
	for(int i=1;i<=q;++i){
		int a,b; cin>>a>>b;
		++s[a];
		queries[a][b].pb(i);
	}
	for(int i=1;i<=n;++i){
		for(pii p:G[i]){
			if(queries[i].find(p.first)!=queries[i].end()){
				vector<int> tmp=queries[i][p.first];
				for(int &v:tmp){
					res[v]+=p.second*2;
				}
			}
			if(s[i]<(int)conns[p.first].size()){
				for(pair<int,vector<int>> w:queries[i]){
					for(int &v:w.second){
						if(conns[p.first].find(w.first)!=conns[p.first].end()){
							res[v]+=min(p.second,conns[p.first][w.first]);
						}
					}
				}
			}else{
				for(pii v:conns[p.first]){
					if(queries[i].find(v.first)!=queries[i].end()){
						vector<int> tmp=queries[i][v.first];
						for(int &w:tmp){
							res[w]+=min(p.second,v.second);
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=q;++i) cout<<res[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve_case();
	}
}
