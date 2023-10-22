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
const int MAXN=2e6+7;
int dp[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) dp[i]=INF;
	int last=0;
	for(int i=1;i<=n;++i){
		int x=__builtin_popcount(i);
		for(int j=last;j>=max(0,last-30);--j){
			if(j+x>=MAXN) break;
			if(dp[j]!=INF) dp[j+x]=min(dp[j+x],i);
		}
		last+=x;
		if(last>MAXN) break;
	}
	vector<int> res;
	int x=n;
	while(dp[x]>0){
		res.pb(dp[x]);
		x-=__builtin_popcount(dp[x]);
	}
	cout<<(int)res.size()<<"\n";
	for(int v:res) cout<<v<<" ";
	cout<<"\n";
}
