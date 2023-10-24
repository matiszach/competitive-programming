// Task statement: https://codeforces.com/problemset/problem/1387/B2
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
vector<int> G[MAXN];
int n;
int amount[MAXN],depth[MAXN];
void DFS(int x,int pre){
	depth[x]=depth[pre]+1;
	for(int v:G[x]) if(v!=pre) DFS(v,x);
	amount[x]=1;
	for(int v:G[x]) if(v!=pre) amount[x]+=amount[v];
}
int centroid(int x,int pre){
	int maxi=0,pos=0;
	for(int v:G[x]){
		if(v!=pre){
			if(amount[v]>maxi){
				maxi=amount[v];
				pos=v;
			}
		}
	}
	if(maxi<=n/2) return x;
	return centroid(pos,x);
}
pii edges[MAXN];
int new_pos[MAXN];
vector<int> tmp;
void get_verts(int x,int pre){
	tmp.pb(x);
	for(int v:G[x]) if(v!=pre) get_verts(v,x);
}
bool cmp(vector<int> &A,vector<int> &B){
	return (int)A.size()>(int)B.size();
}
int preorder[MAXN];
int preorder_to_vert[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
		edges[i]={a,b};
	}
	DFS(1,1);
	ll res=0;
	for(int i=1;i<=n;++i){
		if(depth[edges[i].first]<depth[edges[i].second]) swap(edges[i].first,edges[i].second);
		res+=min(amount[edges[i].first],n-amount[edges[i].first]);
	}
	int vert=centroid(1,1);
	vector<vector<int>> V;
	for(int v:G[vert]){
		tmp.clear();
		get_verts(v,vert);
		V.pb(tmp);
	}
	V.pb({vert});
	int idx=0;
	for(auto P:V){
		for(int v:P){
			preorder[v]=idx++;
			preorder_to_vert[idx-1]=v;
		}
	}
	cout<<res*2<<"\n";
	for(int i=1;i<=n;++i) cout<<preorder_to_vert[(preorder[i]+n/2)%n]<<" ";
	cout<<"\n";
}
