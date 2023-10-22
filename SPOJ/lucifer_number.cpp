// Task statement: https://www.spoj.com/problems/LUCIFER/
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
const int N=10,M=50;
int dp[N][M*2][2];
bool T[M*2];
int count(int x){
	for(int i=0;i<N;++i) for(int j=0;j<M*2;++j) dp[i][j][0]=dp[i][j][1]=0;
	vector<int> digits;
	while(x>0){
		digits.pb(x%10);
		x/=10;
	}
	reverse(digits.begin(),digits.end());
	int n=(int)digits.size();
	dp[0][M][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<M*2;++j){
			for(bool b:{0,1}){
				for(int digit=0;digit<10;++digit){
					if(digit>digits[i-1]&&!b) break;
					if((n-i)&1){
						if(j+digit>=M*2) break;
						dp[i][j+digit][b||(digit<digits[i-1])]+=dp[i-1][j][b];
					}else{
						if(j-digit<0) break;
						dp[i][j-digit][b||(digit<digits[i-1])]+=dp[i-1][j][b];
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=2;i<M;++i){
		if(!T[i]) ans+=(dp[n][i+M][0]+dp[n][i+M][1]);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for(int i=2;i*i<M;++i){
		if(T[i]) continue;
		for(int j=i*i;j<M;j+=i) T[j]=1;
	}
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		int a,b; cin>>a>>b;
		cout<<count(b)-count(a-1)<<"\n";
	}
}
