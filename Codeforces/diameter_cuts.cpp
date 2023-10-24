// Task statement: https://codeforces.com/problemset/problem/1499/F
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
const int MAXN=5e3+7,MOD=998244353;
vector<int> G[MAXN];
ll dp[MAXN][MAXN];
int n,k;
int DFS(int x,int pre){
	int h=0;
	dp[x][0]=1;
	for(int v:G[x]){
		if(v!=pre){
			int hv=DFS(v,x);
			vector<ll> dp_temp(max(h,hv+1)+1);
			for(int i=0;i<=h;++i){
				for(int j=0;j<=hv;++j){
					if(i+j+1<=k) (dp_temp[max(i,j+1)]+=dp[x][i]*dp[v][j]%MOD)%=MOD;
					if(i<=k&&j<=k) (dp_temp[i]+=dp[x][i]*dp[v][j]%MOD)%=MOD;
				}
			}
			h=max(h,hv+1);
			for(int i=0;i<=h;++i) dp[x][i]=dp_temp[i];
		}
	}
	return h;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,1);
	ll ans=0;
	for(int i=0;i<=k;++i) (ans+=dp[1][i])%=MOD;
	cout<<ans<<"\n";
}
