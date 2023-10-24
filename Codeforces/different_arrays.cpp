// Task statement: https://codeforces.com/problemset/problem/1783/D
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
const int MAXN=307,M=9e4+7,MOD=998244353;
int arr[MAXN];
ll dp[MAXN][M*2];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	++dp[3][arr[3]-arr[2]+M];
	if(arr[2]!=0) ++dp[3][arr[3]+arr[2]+M];
	for(int i=3;i<n;++i){
		for(int j=0;j<M*2;++j){
			if(!dp[i][j]) continue;
			(dp[i+1][arr[i+1]+j]+=dp[i][j])%=MOD;
			if(j!=M) (dp[i+1][arr[i+1]-j+M*2]+=dp[i][j])%=MOD;
		}
	}
	ll ans=0;
	for(int i=0;i<M*2;++i) (ans+=dp[n][i])%=MOD;
	cout<<ans<<"\n";
}
