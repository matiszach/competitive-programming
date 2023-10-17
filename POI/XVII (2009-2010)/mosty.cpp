//Task statement: szkopul.edu.pl/problemset/problem/BKM4bb6_C3OZsScdRxzaed8N/site/
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
vector<pii> all_edges;
int n,m;
const int MAXN=1e3+7;
int T[MAXN][MAXN];
struct edge{
	int a,b;
	int flow,cap;
	int other;
	int org;
};
vector<edge> edges;
vector<pii> G[MAXN*3];
int idx;
void add_edge(int a,int b,int c,int org){
	edges.pb({a,b,0,c,idx*2+1,org});
	edges.pb({b,a,c,c,idx*2,org});
	G[a].pb({b,idx*2});
	G[b].pb({a,idx*2+1});
	++idx;
}
int max_flow(int source,int tap,int sz){
	int ans=0;
	while(1){
		vector<bool> visited(sz+1);
		visited[source]=1;
		vector<int> pre(sz+1);
		queue<pii> Q;
		Q.push({source,INF});
		int min_flow=0;
		while(!Q.empty()){
			int vert=Q.front().first,flow=Q.front().second;
			Q.pop();
			for(pii v:G[vert]){
				if(!visited[v.first]&&edges[v.second].flow<edges[v.second].cap){
					visited[v.first]=1;
					Q.push({v.first,min(flow,edges[v.second].cap-edges[v.second].flow)});
					pre[v.first]=v.second;
					if(v.first==tap){
						min_flow=min(flow,edges[v.second].cap-edges[v.second].flow);
						break;
					}
				}
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
int M;
vector<pair<pii,int>> E;
int deg[MAXN];
bool check(int x){
	//reset variables
	idx=0;
	edges.clear();
	E.clear();
	for(int i=0;i<MAXN*3;++i) G[i].clear();
	//construct graph
	M=0;
	for(pii &v:all_edges){
		++M;
		if(T[v.first][v.second]>x&&T[v.second][v.first]>x) return 0;
		if(T[v.first][v.second]>x){
			E.pb({{v.second,v.first},0});
		}else if(T[v.second][v.first]>x){
			E.pb({v,1});
		}else{
			E.pb({v,2});
		}
	}
	//from source
	for(int i=1;i<=M;++i){
		add_edge(0,i,1,0);
	}
	//between edges and vertices
	for(int i=1;i<=M;++i){
		if(E[i-1].second<2){
			add_edge(i,E[i-1].first.second+M,1,i-1);
		}else{
			add_edge(i,E[i-1].first.first+M,1,i-1);
			add_edge(i,E[i-1].first.second+M,1,i-1);
		}
	}
	//to tap
	for(int i=1;i<=n;++i){
		add_edge(i+M,M+n+1,deg[i]/2,0);
	}
	return max_flow(0,M+n+1,M+n+1)==M;
}
int edge_idx[MAXN][MAXN];
vector<int> GP[MAXN];
bool visited[MAXN*2];
vector<int> order;
void DFS(int x){
	for(int &v:GP[x]){
		if(!visited[edge_idx[x][v]]){
			visited[edge_idx[x][v]]=1;
			DFS(v);
			order.pb(edge_idx[x][v]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	int mini=0,maxi=0;
	for(int i=1;i<=m;++i){
		int a,b,c,d; cin>>a>>b>>c>>d;
		mini=max(mini,min(c,d));
		maxi=max(maxi,max(c,d));
		T[a][b]=c;
		T[b][a]=d;
		edge_idx[a][b]=edge_idx[b][a]=i;
		++deg[a];
		++deg[b];
		all_edges.pb({a,b});
	}
	int l=mini,r=maxi+1,mid=0;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(l==maxi+1) cout<<"NIE\n";
	else{
		cout<<l<<"\n";
		check(l);
		vector<pii> used;
		for(int i=1;i<=M;++i){
			for(pii &v:G[i]){
				if(edges[v.second].flow>0){
					if(v.first-M==E[edges[v.second].org].first.first) swap(E[edges[v.second].org].first.first,E[edges[v.second].org].first.second);
					used.pb(E[edges[v.second].org].first);
				}
			}
		}
		for(pii &v:used) GP[v.first].pb(v.second);
		DFS(1);
		reverse(order.begin(),order.end());
		for(int &v:order) cout<<v<<" ";
		cout<<"\n";
	}
}
