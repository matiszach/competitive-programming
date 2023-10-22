// Task statement: https://www.spoj.com/problems/PR003004/
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
ll dp[17][200][2];
ll count(ll x){
	if(x<=0) return 0;
	for(int i=0;i<17;++i) for(int j=0;j<200;++j) for(int k=0;k<2;++k) dp[i][j][k]=0;
	vector<int> digits;
	while(x>0){
		digits.pb(x%10);
		x/=10;
	}
	reverse(digits.begin(),digits.end());
	int n=(int)digits.size();
	dp[0][0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<200;++j){
			for(int b=0;b<2;++b){
				for(int digit=0;digit<10;++digit){
					if(digit>digits[i-1]&&!b) break;
					if(j+digit>=200) break;
					dp[i][j+digit][b||(digit<digits[i-1])]+=dp[i-1][j][b];
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<200;++i){
		ans+=(ll)i*dp[n][i][0];
		ans+=(ll)i*dp[n][i][1];
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i){
		ll a,b; cin>>a>>b;
		cout<<count(b)-count(a-1)<<"\n";
	}
}
