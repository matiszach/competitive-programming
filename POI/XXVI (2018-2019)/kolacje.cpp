//Task statement: szkopul.edu.pl/problemset/problem/CACYTyPO4YJxyZzNumr0zr5e/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+7,LOG=18;
#define INF 1e18
typedef long long ll;
int n,r,t,a,b,c;
int types[SIZE],amount[SIZE];
ll dist[SIZE];
vector<pair<int,ll> > graph[SIZE];
ll curr_dist=0;
bitset<SIZE> visited;
void DFS(int x,ll self_dist){
	visited[x]=1;
	curr_dist+=self_dist;
	dist[x]=curr_dist;
	for(pair<int,int> p:graph[x]){
		if(!visited[p.first]) DFS(p.first,p.second);
	}
	curr_dist-=self_dist;
}
int idx=0;
int enter_deg[SIZE],exit_deg[SIZE];
int lca[LOG][SIZE];
ll lca2[LOG][SIZE],dist2[SIZE];
void DFS2(int x,int v){
	visited[x]=1;
	enter_deg[x]=++idx;
	lca[0][x]=v;
	for(pair<int,int> p:graph[x]){
		if(!visited[p.first]) DFS2(p.first,x);
	}
	exit_deg[x]=++idx;
}
bool anc(int v,int u){
	if(v==u) return 1;
	return (enter_deg[u]>enter_deg[v]&&exit_deg[u]<exit_deg[v]);
}
int LCA(int v,int u){
	if(anc(v,u)) return v;
	if(anc(u,v)) return u;
	int v2=v;
	for(int i=LOG-1;i>=0;--i){
		if(!anc(lca[i][v2],u)) v2=lca[i][v2];
	}
	return lca[0][v2];
}
ll LCA2(int v,int u){
	ll ans=INF;
	if(v==u) return dist2[v];
	if(anc(v,u)){
		for(int i=LOG-1;i>=0;--i){
			if(!anc(lca[i][u],v)){
				ans=min(ans,lca2[i][u]);
				u=lca[i][u];
			}
		}
		ans=min(ans,lca2[0][u]);
		return ans;
	}
	if(anc(u,v)){
		for(int i=LOG-1;i>=0;--i){
			if(!anc(lca[i][v],u)){
				ans=min(ans,lca2[i][v]);
				v=lca[i][v];
			}
		}
		ans=min(ans,lca2[0][v]);
		return ans;
	}
	for(int i=LOG-1;i>=0;--i){
		if(!anc(lca[i][v],u)){
			ans=min(ans,lca2[i][v]);
			v=lca[i][v];
		}
	}
	for(int i=LOG-1;i>=0;--i){
		if(!anc(lca[i][u],v)){
			ans=min(ans,lca2[i][u]);
			u=lca[i][u];
		}
	}
	ans=min(ans,lca2[0][v]);
	ans=min(ans,lca2[0][u]);
	return ans;
}
vector<int> rest[SIZE];
int sqr=0;
priority_queue<pair<ll,int> > Q;
pair<pair<int,int>,pair<int,int> > ques[SIZE];
void Dijkstra(int x){
	for(int v:rest[x]){
		Q.push({0,v});
		dist2[v]=0;
	}
	while(!Q.empty()){
		ll val=-Q.top().first;
		int vert=Q.top().second;
		Q.pop();
		if(val>dist2[vert]) continue;
		for(pair<int,int> p:graph[vert]){
			if(dist2[p.first]>val+p.second){
				dist2[p.first]=val+p.second;
				Q.push({-val-p.second,p.first});
			}
		}
	}
}
ll get_dist(int v,int u){
	if(v==u) return 0;
	int x=LCA(v,u);
	return (ll)dist[v]+(ll)dist[u]-(ll)(2*dist[x]);
}
ll qrs[SIZE];
bitset<SIZE> computed;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>r;
	for(int i=1;i<=n;++i){
		cin>>types[i];
		rest[types[i]].push_back(i);
		++amount[types[i]];
	}
	for(int i=1;i<=n-1;++i){
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	DFS(1,0);
	visited.reset();
	DFS2(1,1);
	for(int i=1;i<LOG;++i){
		for(int j=1;j<=n;++j){
			lca[i][j]=lca[i-1][lca[i-1][j]];
		}
	}
	sqr=sqrt(n);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>a>>b>>c;
		ques[i]={{c,i},{a,b}};
	}
	sort(ques+1,ques+1+t);
	for(int i=1;i<=t;++i){
		a=ques[i].second.first;
		b=ques[i].second.second;
		c=ques[i].first.first;
		int idx=ques[i].first.second;
		if(amount[c]<sqr){
			if(amount[c]==0){
				qrs[idx]=-1;
				continue;
			}
			ll val=INF;
			for(int v:rest[c]){
				val=min(val,get_dist(a,v)+get_dist(b,v));
			}
			qrs[idx]=val;
		}else{
			if(!computed[c]){
				computed[c]=1;
				for(int j=1;j<=n;++j) dist2[j]=INF;
				Dijkstra(c);
				for(int v=1;v<=n;++v){
					lca2[0][v]=min(dist2[v],dist2[lca[0][v]]);
				}
				for(int j=1;j<LOG;++j){
					for(int k=1;k<=n;++k){
						lca2[j][k]=min(lca2[j-1][k],lca2[j-1][lca[j-1][k]]);
					}
				}
			}
			ll val=LCA2(a,b);
			qrs[idx]=get_dist(a,b)+(2*val);
		}
	}
	for(int i=1;i<=t;++i) cout<<qrs[i]<<"\n";
}
