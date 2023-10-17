//Task statement: szkopul.edu.pl/problemset/problem/l8-ujU0a7HQFxy8UY32B4Kk_/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INF=1e18+7;
#define pb push_back
const int SIZE=5e3+7;
int n,m,a,b,c;
ll prices[SIZE];
vector<pil> G[SIZE],rG[SIZE];
ll dist[SIZE],dist2[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>prices[i];
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b>>c;
		G[a].pb({b,c});
		rG[b].pb({a,c});
	}
	for(int i=1;i<=n;++i) dist[i]=INF;
	dist[1]=0;
	priority_queue<pli> Q;
	Q.push({0,1});
	while(!Q.empty()){
		pli vert=Q.top(); Q.pop();
		if(-vert.first>dist[vert.second]) continue;
		for(pil p:G[vert.second]){
			if(-vert.first+p.second<dist[p.first]){
				dist[p.first]=-vert.first+p.second;
				Q.push({-dist[p.first],p.first});
			}
		}
	}
	for(int i=1;i<=n;++i) dist2[i]=INF;
	dist2[1]=0;
	Q.push({0,1});
	while(!Q.empty()){
		pli vert=Q.top(); Q.pop();
		if(-vert.first>dist2[vert.second]) continue;
		for(pil p:rG[vert.second]){
			if(-vert.first+p.second<dist2[p.first]){
				dist2[p.first]=-vert.first+p.second;
				Q.push({-dist2[p.first],p.first});
			}
		}
	}
	ll ans=INF;
	for(int i=1;i<=n;++i) ans=min(ans,dist[i]+dist2[i]+prices[i]/2LL);
	cout<<ans<<"\n";
}
