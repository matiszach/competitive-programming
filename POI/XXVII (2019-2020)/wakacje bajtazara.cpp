//Task statement: szkopul.edu.pl/problemset/problem/pXcijJbDyC_jRAjkoxBH9sCO/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=1e6+7;
int val[MAXN];
vector<int> G[MAXN];
ll dpP[MAXN],dpN[MAXN],dpE[MAXN];
int startP[MAXN],startN[MAXN];
pii startE[MAXN];
bool is_N[MAXN];
vector<int> to_vis[MAXN];
vector<int> to_visP[MAXN];
int parent[MAXN];
pii pot_start,pot_start2;
ll maxi=0,maxi2=0;
int pos,pos2;
ll total=0;
void DFS(int x,int pre){
	parent[x]=pre;
	for(int v:G[x]) if(v!=pre) DFS(v,x);
	if(x!=1&&G[x].size()==1){
		dpN[x]=val[x];
		startN[x]=x;
		return;
	}
	//dpP
	maxi=-1; total=0;
	pos=0;
	for(int v:G[x]) if(v!=pre) total+=val[v];
	for(int v:G[x]) if(v!=pre){
		if(maxi<dpN[v]-val[v]){
			maxi=dpN[v]-val[v];
			pos=v;
		}
	}
	dpP[x]=max(0LL,maxi)+total;
	startP[x]=startN[pos];
	for(int v:G[x]) if(v!=pre&&v!=pos) to_visP[x].pb(v);
	//dpN
	maxi=-1; pos=0;
	for(int v:G[x]) if(v!=pre){
		if(maxi<dpP[v]){
			maxi=dpP[v];
			pos=v;
		}
	}
	dpN[x]=max(0LL,maxi)+val[x];
	startN[x]=startP[pos];
	if(startN[x]==0) startN[x]=x;
	//dpE (P)
	maxi=-1; pos=0;
	for(int v:G[x]){
		if(v!=pre){
			if(maxi<dpN[v]-val[v]){
				maxi=dpN[v]-val[v];
				pos=v;
			}
		}
	}
	pot_start={0,0};
	pot_start.first=startN[pos];
	maxi2=-1;
	pos2=0;
	for(int v:G[x]){
		if(v!=pre&&v!=pos){
			if(maxi2<dpN[v]-val[v]){
				maxi2=dpN[v]-val[v];
				pos2=v;
			}
		}
	}
	pot_start.second=startN[pos2];
	dpE[x]=max(0LL,maxi)+max(0LL,maxi2)+total+val[pre];
	for(int v:G[x]) if(v!=pos&&v!=pos2) to_vis[x].pb(v);
	//dpE (N)
	maxi=-1; maxi2=-1; pos=0; pos2=0;
	for(int v:G[x]){
		if(v!=pre){
			if(maxi<dpP[v]){
				maxi=dpP[v];
				pos=v;
			}
		}
	}
	pot_start2={0,0};
	pot_start2.first=startP[pos];
	for(int v:G[x]){
		if(v!=pre&&v!=pos){
			if(maxi2<dpP[v]){
				maxi2=dpP[v];
				pos2=v;
			}
		}
	}
	pot_start2.second=startP[pos2];
	if(max(0LL,maxi)+max(0LL,maxi2)+val[x]>dpE[x]){
		dpE[x]=max(0LL,maxi)+max(0LL,maxi2)+val[x];
		is_N[x]=1;
		startE[x]=pot_start2;
	}else{
		startE[x]=pot_start;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>val[i];
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	if(n==1){
		cout<<val[1]<<"\n1\n1\n";
		return 0;
	}
	DFS(1,0);
	ll ans=0,nr=0;
	for(int i=1;i<=n;++i){
		if(ans<dpE[i]){
			ans=dpE[i];
			nr=i;
		}
	}
	vector<int> path;
	int x=startE[nr].first;
	bool odd=1;
	while(x!=nr){
		path.pb(x);
		if(!odd){
			for(int v:to_visP[x]){
				path.pb(v);
				path.pb(x);
			}
		}
		x=parent[x];
		odd^=1;
	}
	vector<int> ext;
	ext.pb(nr);
	path.pb(nr);
	if(!is_N[nr]){
		for(int v:to_vis[nr]){
			path.pb(v);
			ext.pb(v);
			path.pb(nr);
			ext.pb(nr);
		}
	}
	if(startE[nr].second!=0){
		x=startE[nr].second;
		vector<int> tmp;
		odd=1;
		while(x!=nr){
			if(!odd){
				for(int v:to_visP[x]){
					tmp.pb(x);
					tmp.pb(v);
				}
			}
			tmp.pb(x);
			x=parent[x];
			odd^=1;
		}
		reverse(tmp.begin(),tmp.end());
		for(int v:tmp) path.pb(v);
	}
	if(path.size()%2==0) path.pop_back();
	cout<<ans<<"\n";
	cout<<path.size()/2+1<<"\n";
	for(int v:path) cout<<v<<" ";
	cout<<"\n";
}
