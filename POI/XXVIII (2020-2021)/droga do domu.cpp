//Task statement: szkopul.edu.pl/problemset/problem/ZfS_tobZ_7xdR6D5s6Tegur3/site/
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
const int SIZE=5e4+7;
int n,m,s,p,t,l,x,y,v,a,b,c;
map<int,int> G[SIZE];
vector<int> route[SIZE];
vector<ll> pref[SIZE];
pii times[SIZE];
ll dp[2][SIZE];
ll recent(int idx,int point,ll val){
	ll addon=times[idx].first,mlp=times[idx].second;
	ll rec=addon+pref[idx][point];
	if(val<=rec) return rec;
	ll diff=val-rec;
	return rec+(diff/mlp+(ll)(diff%mlp!=0))*mlp;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>s>>p>>t;
	for(int i=1;i<=m;++i){
		cin>>a>>b>>c;
		G[a][b]=c;
		G[b][a]=c;
	}
	for(int i=1;i<=s;++i){
		cin>>l>>x>>y;
		times[i]={x,y};
		for(int j=1;j<=l;++j){
			cin>>v;
			route[i].pb(v);
		}
		pref[i].resize(l,0);
		for(int j=1;j<l;++j) pref[i][j]=pref[i][j-1]+G[route[i][j]][route[i][j-1]];
	}
	for(int i=1;i<=n;++i) dp[1][i]=INF;
	dp[1][1]=t;
	for(int i=0;i<=p;++i){
		for(int j=1;j<=n;++j) dp[0][j]=dp[1][j];
		for(int j=1;j<=s;++j){
			ll curr=INF;
			for(int k=0;k<(int)route[j].size()-1;++k){
				int vert=route[j][k],dest=route[j][k+1];
				curr=recent(j,k,min(dp[0][vert],curr));
				curr+=G[vert][dest];
				dp[1][dest]=min(dp[1][dest],curr);
			}
		}
	}
	if(dp[1][n]==INF) cout<<"NIE\n";
	else cout<<dp[1][n]<<"\n";
}
