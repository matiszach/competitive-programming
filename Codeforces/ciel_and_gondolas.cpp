// Task statement: https://codeforces.com/problemset/problem/321/E
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
const int MAXN=4e3+7;
int pref[MAXN][MAXN];
int cost[MAXN][MAXN];
int dp[MAXN],dp_curr[MAXN];
void dp_opt(int l,int r,int optl,int optr){
	if(l>r) return;
	int mid=(l+r)>>1;
	int best=INF,pos=0;
	for(int i=optl;i<=min(mid,optr);++i){
		if(best>dp_curr[i]+cost[i+1][mid]){
			best=dp_curr[i]+cost[i+1][mid];
			pos=i;
		}
	}
	dp[mid]=best;
	dp_opt(l,mid-1,optl,pos);
	dp_opt(mid+1,r,pos,optr);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;++i){
		int x=0;
		for(int j=1;j<=n;++j){
			cin>>x;
			pref[i][j]=pref[i][j-1]+x;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			cost[i][j]=cost[i][j-1]+pref[j][j]-pref[j][i-1];
		}
	}
	for(int i=1;i<=n;++i) dp_curr[i]=cost[1][i];	
	for(int i=1;i<k;++i){
		dp_opt(0,n,0,n);
		for(int j=1;j<=n;++j) dp_curr[j]=dp[j];
	}
	cout<<dp_curr[n]<<"\n";
}
