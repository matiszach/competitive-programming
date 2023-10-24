// Task statement: https://codeforces.com/problemset/problem/1572/C
// *Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
void solve_case(){
	int n; cin>>n;
	vector<int> arr(n+1);
	for(int i=1;i<=n;++i) cin>>arr[i];
	vector<vector<int>> dp(n+1,vector<int>(n+1));
	vector<vector<int>> pos(n+1,vector<int>());
	for(int i=1;i<=n;++i) pos[arr[i]].push_back(i);
	for(int len=1;len<=n-1;++len){
		for(int i=1;i<=n-len;++i){
			int start=i,end=i+len;
			int res=dp[start+1][end];
			for(int v:pos[arr[start]]){
				if(v<=start||v>end) continue;
				res=max(res,dp[start+1][v-1]+dp[v][end]+1);
			}
			dp[start][end]=res;
		}
	}
	cout<<n-1-dp[1][n]<<"\n";
}
int main()
{
	int t; cin>>t;
	while(t--){
		solve_case();
	}
}
