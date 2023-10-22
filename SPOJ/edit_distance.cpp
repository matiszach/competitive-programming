// Task statement: https://www.spoj.com/problems/EDIST/
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
void solve_case(){
	string s1,s2; cin>>s1>>s2;
	int n=s1.size(),m=s2.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1));
	for(int i=1;i<=n;++i) dp[i][0]=i;
	for(int j=1;j<=m;++j) dp[0][j]=j;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			dp[i][j]=min(dp[i-1][j-1]+(s1[i-1]!=s2[j-1]),min(dp[i-1][j]+1,dp[i][j-1]+1));
		}
	}
	cout<<dp[n][m]<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) solve_case();
}
