// Task statement: https://codeforces.com/problemset/problem/1499/E
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
const int MAXN=1e3+7;
int cntx[MAXN],cnty[MAXN];
int dp[2][MAXN][MAXN];
const int MOD=998244353;
int main()
{
	ios_base::sync_with_stdio(0);
	string x,y; cin>>x>>y;
	int X=x.size(),Y=y.size();
	x="$"+x; y="$"+y;
	for(int i=1;i<=X;++i){
		cntx[i]=cntx[i-1]+1;
		if(x[i]==x[i-1]) cntx[i]=1;
	}
	for(int i=1;i<=Y;++i){
		cnty[i]=cnty[i-1]+1;
		if(y[i]==y[i-1]) cnty[i]=1;
	}
	int res=0;
	for(int a=1;a<=X;++a){
		for(int b=1;b<=Y;++b){
			if(x[a]!=y[b]) dp[0][a][b]=(dp[1][a-1][b]+cnty[b])%MOD;
			if(x[a]!=x[a-1]) (dp[0][a][b]+=dp[0][a-1][b])%=MOD;
			if(x[a]!=y[b]) dp[1][a][b]=(dp[0][a][b-1]+cntx[a])%MOD;
			if(y[b]!=y[b-1]) (dp[1][a][b]+=dp[1][a][b-1])%=MOD;
			(res+=(dp[0][a][b]+dp[1][a][b])%MOD)%=MOD;
		}
	}
	cout<<res<<"\n";
}
