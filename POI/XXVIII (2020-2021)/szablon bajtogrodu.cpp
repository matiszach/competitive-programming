//Task statement: szkopul.edu.pl/problemset/problem/y-mTVYClxMJcgMhUnHaUqPPq/site/
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
const int MAXN=2e3+7,A=26,LOG=12;
vector<pii> G[MAXN];
map<int,int> T[MAXN*MAXN];
int last[MAXN*MAXN];
vector<pii> inters[MAXN*MAXN];
int curr,idx,start_point,vert;
vector<int> to_check;
bool used[MAXN*MAXN];
void DFS3(int x,int pre){
	for(pii v:G[x]){
		if(v.first!=pre){
			if(T[curr].find(v.second)==T[curr].end()){
				T[curr][v.second]=++idx;
				last[idx]=curr;
				to_check.pb(idx);
				used[idx]=1;
			}
			curr=T[curr][v.second];
			inters[curr].pb({start_point,v.first});
			DFS3(v.first,x);
			curr=last[curr];
		}
	}
}
void DFS4(int x,int pre){
	for(pii v:G[x]){
		if(v.first!=pre){
			if(T[curr].find(v.second)==T[curr].end()){
				T[curr][v.second]=++idx;
				last[idx]=curr;
			}
			curr=T[curr][v.second];
			if(v.first==vert&&!used[curr]){
				used[curr]=1;
				to_check.pb(curr);
			}
			inters[curr].pb({start_point,v.first});
			DFS4(v.first,x);
			curr=last[curr];
		}
	}
}
void DFS(int x,int pre){
	for(pii v:G[x]){
		if(v.first!=pre){
			if(T[curr].find(v.second)==T[curr].end()){
				T[curr][v.second]=++idx;
				last[idx]=curr;
			}
			curr=T[curr][v.second];
			inters[curr].pb({start_point,v.first});
			DFS(v.first,x);
			curr=last[curr];
		}
	}
}
int parent[MAXN],depth[MAXN];
int lca[LOG][MAXN];
void DFS2(int x,int pre){
	lca[0][x]=pre;
	parent[x]=pre;
	depth[x]=depth[pre]+1;
	for(pii v:G[x]) if(v.first!=pre) DFS2(v.first,x);
}
int LCA(int v,int u){
	if(depth[v]<depth[u]) swap(v,u);
	int diff=depth[v]-depth[u];
	for(int i=LOG-1;i>=0;--i){
		if((1<<i)&diff) v=lca[i][v];
	}
	if(v==u) return v;
	for(int i=LOG-1;i>=0;--i){
		if(lca[i][v]!=lca[i][u]) u=lca[i][u],v=lca[i][v];
	}
	return lca[0][v];
}
int pref[MAXN];
int dp[MAXN];
int total;
bool ok=1;
void DFS5(int x,int pre){
	for(pii v:G[x]) if(v.first!=pre) DFS5(v.first,x);
	dp[x]=pref[x];
	for(pii v:G[x]) if(v.first!=pre) dp[x]+=dp[v.first];
	if(x!=1&&dp[x]<=0) ok=0;
}
bool good[MAXN*MAXN];
vector<int> word;
vector<string> res;
void DFS6(int x){
	for(auto p:T[x]){
		int i=p.first;
		word.pb(i);
		if(good[T[x][i]]){
			string s="";
			for(int v:word) s+=char(v+'A');
			res.pb(s);
		}
		DFS6(T[x][i]);
		word.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<n;++i){
		int a,b; char c; cin>>a>>b>>c;
		G[a].pb({b,c-'A'});
		G[b].pb({a,c-'A'});
	}
	DFS2(1,1);
	for(int i=2;i<=n;++i){
		if((int)G[i].size()==1){
			vert=i;
			break;
		}
	}
	for(int i=1;i<LOG;++i){
		for(int j=1;j<=n;++j){
			lca[i][j]=lca[i-1][lca[i-1][j]];
		}
	}
	start_point=vert;
	DFS3(vert,vert);
	for(int i=1;i<=n;++i){
		start_point=i;
		if(i!=vert) DFS4(i,i);
	}
	for(int i=1;i<=n;++i){
		start_point=i;
		DFS(i,i);
	}
	for(int v:to_check){
		for(int i=0;i<=n;++i) pref[i]=dp[i]=0;
		for(pii p:inters[v]){
			int x=LCA(p.first,p.second);
			pref[x]-=2;
			if(x==1) x=0;
			else x=parent[x];
			++pref[p.first];
			++pref[p.second];
		}
		ok=1;
		curr=0;
		DFS5(1,1);
		if(ok) good[v]=1;
	}
	curr=0;
	DFS6(0);
	sort(res.begin(),res.end());
	cout<<res.size()<<"\n";
	for(int i=0;i<(int)res.size();++i) cout<<res[i]<<"\n";
}
