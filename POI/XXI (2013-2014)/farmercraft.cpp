//Task statement: szkopul.edu.pl/problemset/problem/vxIJvdKsTWZup9JYnSgRZPT3/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INF=1e18+7;
#define pb push_back
const int SIZE=5e5+7;
int val[SIZE];
vector<int> G[SIZE];
int n,a,b;
pii dp[SIZE];
bool cmp(int A,int B){
	return dp[A].first>dp[B].first;
}
void DFS(int x,int pre){
	for(int v:G[x]){
		if(v!=pre) DFS(v,x);
	}
	if((int)G[x].size()==1&&x!=1) dp[x].first=val[x];
	else{
		vector<int> curr;
		for(int v:G[x]){
			if(v!=pre){
				curr.pb(v);
				dp[x].second+=dp[v].second+2;
			}
		}
		sort(curr.begin(),curr.end(),cmp);
		int maxi=dp[curr[0]].first-1;
		for(int i=1;i<(int)curr.size();++i){
			maxi-=(dp[curr[i]].second+2);
			maxi=max(maxi,0);
			maxi=max(maxi,dp[curr[i]].first-1);
		}
		if(x!=1) maxi=max(maxi,val[x]-dp[x].second);
		dp[x].first=maxi;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>val[i];
	for(int i=1;i<n;++i){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,1);
	cout<<dp[1].second+max(dp[1].first,val[1])<<"\n";
}
