// Task statement: https://codeforces.com/problemset/problem/1680/E
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
const int MAXN=2e5+7;
char arr[2][MAXN];
int dp[2][MAXN];
void solve_case(){
	int n; cin>>n;
	for(int i=0;i<2;++i) for(int j=1;j<=n;++j) cin>>arr[i][j];
	int furthest=0;
	int start=0;
	for(int i=1;i<=n;++i) dp[0][i]=dp[1][i]=0;
	for(int i=1;i<=n;++i) if(arr[0][i]=='*'||arr[1][i]=='*') furthest=i;
	for(int i=1;i<=n;++i){
		if(arr[0][i]=='*'||arr[1][i]=='*'){
			start=i;
			break;
		}
	}
	if(arr[0][start]=='*'&&arr[1][start]=='.') dp[1][start]=1;
	if(arr[0][start]=='.'&&arr[1][start]=='*') dp[0][start]=1;
	if(arr[0][start]=='*'&&arr[1][start]=='*') dp[0][start]=dp[1][start]=1;
	for(int i=start+1;i<=furthest;++i){
		if(arr[0][i]=='*'&&arr[1][i]=='*') dp[0][i]=dp[1][i]=min(dp[0][i-1],dp[1][i-1])+2;
		else if(arr[0][i]=='*'){
			dp[0][i]=min(dp[0][i-1]+1,dp[1][i-1]+2);
			dp[1][i]=min(dp[0][i-1]+2,dp[1][i-1]+2);
		}else if(arr[1][i]=='*'){
			dp[1][i]=min(dp[0][i-1]+2,dp[1][i-1]+1);
			dp[0][i]=min(dp[0][i-1]+2,dp[1][i-1]+2);
		}else{
			dp[0][i]=dp[0][i-1]+1;
			dp[1][i]=dp[1][i-1]+1;
		}
	}
	cout<<min(dp[0][furthest],dp[1][furthest])<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i) solve_case();
}
