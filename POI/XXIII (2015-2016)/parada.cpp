//Task statement: szkopul.edu.pl/problemset/problem/1QaUWE_ePAmitZjgAszOVD1U/site/
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
const int MAXN=2e5+7;
vector<int> G[MAXN];
int dp[MAXN];
int ans=0;
void DFS(int x,int pre){
	for(int v:G[x]){
		if(v!=pre) DFS(v,x);
	}
	if(x!=1&&(int)G[x].size()==1){
		dp[x]=1;
		return;
	}
	int maxi=1,maxi2=1,pos=0;
	for(int v:G[x]){
		if(v!=pre){
			if(dp[v]>maxi){
				maxi=dp[v];
				pos=v;
			}
		}
	}
	for(int v:G[x]){
		if(v!=pre&&v!=pos) maxi2=max(maxi2,dp[v]);
	}
	dp[x]=max((int)G[x].size()-2+maxi,(int)G[x].size());
	ans=max(ans,max((int)G[x].size()-2+maxi,maxi+maxi2+(int)G[x].size()-4));
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,1);
	cout<<ans<<"\n";
}
