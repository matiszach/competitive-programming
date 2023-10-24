// Task statement: https://codeforces.com/problemset/problem/628/D
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
const int N=2e3+7,MOD=1e9+7;
ll dp[N][N][2];
ll count(string x,int m,int d){
	for(int i=0;i<N;++i) for(int j=0;j<N;++j) for(int k=0;k<2;++k) dp[i][j][k]=0;
	int n=(int)x.size();
	dp[0][0][1]=1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<m;++j){
			for(int b=0;b<2;++b){
				for(int digit=0;digit<=(b?x[i]-'0':9);++digit){
					if(i%2&&digit!=d) continue;
					if(i%2==0&&digit==d) continue;
					if(i==0&&digit==0) continue;
					(dp[i+1][(j*10+digit)%m][b&&(digit==(x[i]-'0'))]+=dp[i][j][b])%=MOD;
				}
			}
		}
	}
	return (dp[n][0][0]+dp[n][0][1])%MOD;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int m,d; cin>>m>>d;
	string a,b; cin>>a>>b;
	ll ans=count(b,m,d)-count(a,m,d)+MOD;
	bool ok=1;
	ll curr=0;
	for(int i=0;i<(int)a.size();++i){
		if(i%2&&a[i]-'0'!=d) ok=0;
		if(i%2==0&&a[i]-'0'==d) ok=0;
		curr*=10;
		curr+=a[i]-'0';
		curr%=m;
	}
	if(curr>0) ok=0;
	ans+=ok;
	cout<<ans%MOD<<"\n";
}
