// Task statement: https://codeforces.com/problemset/problem/1473/F
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
const int MAXN=3e3+7;
int A[MAXN],B[MAXN];
vector<pii> G[MAXN];
struct edge{
	int a,b;
	int flow,cap;
	int other;
};
vector<edge> edges;
int idx;
void add_edge(int a,int b,int c){
	edges.pb({a,b,0,c,idx*2+1});
	edges.pb({b,a,c,c,idx*2});
	G[a].pb({b,idx*2});
	G[b].pb({a,idx*2+1});
	++idx;
}
int max_flow(int source,int tap,int sz){
	int ans=0;
	while(1){
		vector<bool> visited(sz+1);
		visited[source]=1;
		vector<pii> Q={{source,INF}};
		vector<int> pre(sz+1);
		int min_flow=0;
		for(int i=0;i<(int)Q.size();++i){
			int vert=Q[i].first,flow=Q[i].second;
			for(pii &v:G[vert]){
				if(!visited[v.first]&&edges[v.second].flow<edges[v.second].cap){
					visited[v.first]=1;
					pre[v.first]=v.second;
					Q.pb({v.first,min(flow,edges[v.second].cap-edges[v.second].flow)});
					if(v.first==tap){
						min_flow=min(flow,edges[v.second].cap-edges[v.second].flow);
						break;
					}
				}
				if(min_flow) break;
			}
			if(min_flow) break;
		}
		if(!min_flow) return ans;
		ans+=min_flow;
		int curr=tap;
		while(curr!=source){
			edges[pre[curr]].flow+=min_flow;
			edges[edges[pre[curr]].other].flow-=min_flow;
			curr=edges[pre[curr]].a;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>A[i];
	for(int i=1;i<=n;++i) cin>>B[i];
	for(int i=1;i<=n;++i) if(B[i]>0) add_edge(0,i,B[i]);
	for(int i=1;i<=n;++i) if(B[i]<0) add_edge(i,n+1,-B[i]);
	for(int i=1;i<=n;++i){
		vector<bool> used(101);
		for(int j=i-1;j>=1;--j){
			if(!used[A[j]]&&A[i]%A[j]==0){
				used[A[j]]=1;
				add_edge(i,j,INF);
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;++i) if(B[i]>0) res+=B[i];
	cout<<res-max_flow(0,n+1,n+1)<<"\n";
}
