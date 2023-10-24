// Task statement: https://codeforces.com/problemset/problem/1860/D
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
const int MAXN=107;
int dp[2][MAXN][MAXN*MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	string s; cin>>s;
	int cn0=0,cn1=0;
	for(char &c:s){
		if(c=='0') ++cn0;
		if(c=='1') ++cn1;
	}
	int n=s.size();
	for(int i=0;i<2;++i){
		for(int j=0;j<MAXN;++j){
			for(int k=0;k<MAXN*MAXN;++k) dp[i][j][k]=INF;
		}
	}
	dp[0][0][0]=0;
	for(int i=0;i<n;++i){
		for(int cnt0=0;cnt0<MAXN;++cnt0){
			for(int cnt01=0;cnt01<MAXN*MAXN-MAXN;++cnt01){
				dp[(i+1)%2][cnt0][cnt01]=INF;
			}
		}
		for(int cnt0=0;cnt0<MAXN-1;++cnt0){
			for(int cnt01=0;cnt01<MAXN*MAXN-MAXN;++cnt01){
				dp[(i+1)%2][cnt0+1][cnt01]=min(dp[(i+1)%2][cnt0+1][cnt01],dp[i%2][cnt0][cnt01]+(s[i]=='1'));
				dp[(i+1)%2][cnt0][cnt01+cnt0]=min(dp[(i+1)%2][cnt0][cnt01+cnt0],dp[i%2][cnt0][cnt01]+(s[i]=='0'));
			}
		}
	}
	cout<<dp[n%2][cn0][cn0*cn1/2]/2<<"\n";
}
