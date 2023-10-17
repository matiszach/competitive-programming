//Task statement: szkopul.edu.pl/problemset/problem/eZiOMPFA4Cq9YsIFAjhCZlo9/site/
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
const int MAXN=207;
vector<int> G[MAXN];
bool l[MAXN],r[MAXN];
bitset<MAXN> visited;
vector<int> BG[MAXN];
void DFS(int x,int org){
	visited[x]=1;
	for(int v:G[x]){
		if(!visited[v]){
			if(r[v]){
				BG[org].pb(v);
				BG[v].pb(org);
			}
			DFS(v,org);
		}
	}
}
int nul;
int used[MAXN];
int conn[MAXN];
bool match(int x){
	if(used[x]==nul) return 0;
	used[x]=nul;
	for(int v:BG[x]){
		if(conn[v]==0){
			conn[v]=x;
			return 1;
		}
	}
	for(int v:BG[x]){
		if(used[conn[v]]!=nul&&match(conn[v])){
			conn[v]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	int ans=0;
	for(int i=1;i<n;++i){
		int x; cin>>x;
		for(int j=1;j<=x;++j){
			int v; cin>>v;
			if(i==1&&v!=n) l[v]=1;
			if(v==n&&i!=1) r[i]=1;
			if(i==1&&v==n) ++ans;
			else G[i].pb(v);
		}
	}
	for(int i=2;i<n;++i){
		if(l[i]&&r[i]){
			l[i]=r[i]=0;
			++ans;
		}
	}
	for(int i=2;i<n;++i){
		if(l[i]){
			visited.reset();
			DFS(i,i);
		}
	}
	for(int i=2;i<n;++i){
		if(l[i]){
			++nul;
			match(i);
		}
	}
	for(int i=2;i<n;++i) if(r[i]&&conn[i]!=0) ++ans;
	cout<<ans<<"\n";
}
