//Task statement: szkopul.edu.pl/problemset/problem/LpgPj1kMBd1aIsADYqkUQf2U/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=2e2+7,K=9e3+7,INF=1e9+7;
int n,m,p,k,w,q,r,u,t,s;
int smith[SIZE];
vector<pair<int,pair<int,int> > > graph[SIZE];
int dist[SIZE][K];
priority_queue<pair<int,pair<int,int> > > pq;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>p>>k;
	for(int i=1;i<=k;++i){
		cin>>w>>q;
		for(int j=1;j<=q;++j){
			cin>>r; --r;
			smith[w]|=(1<<r);
		}
	}
	for(int i=1;i<=m;++i){
		cin>>u>>w>>t>>s;
		int mask=0;
		for(int j=1;j<=s;++j){
			cin>>r; --r;
			mask+=(1<<r);
		}
		graph[u].push_back({w,{t,mask}});
		graph[w].push_back({u,{t,mask}});
	}
	for(int i=1;i<=n;++i) for(int j=0;j<K;++j) dist[i][j]=INF;
	pq.push({0,{1,smith[1]}});
	dist[1][smith[1]]=0;
	while(!pq.empty()){
		int vert=pq.top().second.first,mask=pq.top().second.second;
		pq.pop();
		for(int i=0;i<graph[vert].size();++i){
			if((graph[vert][i].second.second|mask)==mask){
				int new_vert=graph[vert][i].first,
				new_dist=graph[vert][i].second.first+dist[vert][mask],
				new_mask=(smith[new_vert]|mask);
				if(dist[new_vert][new_mask]>new_dist){
					dist[new_vert][new_mask]=new_dist;
					pq.push({-new_dist,{new_vert,new_mask}});
				}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<K;++i) ans=min(ans,dist[n][i]);
	if(ans==INF) cout<<"-1\n";
	else cout<<ans<<"\n";
}
