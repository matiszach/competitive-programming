// Task statement: https://codeforces.com/problemset/problem/1552/F
// *Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct teleport{
	ll x,y;
	bool active;
};
bool cmp(teleport &A,teleport &B){
	return A.x<B.x;
}
const ll MOD=998244353;
void add_self(ll &a,ll b){
	a+=b;
	a%=MOD;
}
vector<int> poses;
int closest(int pos){
	return upper_bound(poses.begin(),poses.end(),pos)-poses.begin()-1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<teleport> arr(n+1);
	for(int i=1;i<=n;++i) cin>>arr[i].x>>arr[i].y>>arr[i].active;
	for(int i=1;i<=n;++i) poses.push_back(arr[i].x);
	poses.push_back(0);
	sort(poses.begin(),poses.end());
	sort(arr.begin(),arr.end(),cmp);
	vector<ll> dp(n+1),dp2(n+1);
	for(int i=1;i<=n;++i){
		ll res=dp2[i-1]+arr[i].x-arr[i-1].x+MOD;
		res%=MOD;
		int idx=closest(arr[i].y);
		if(idx+1<i)
		add_self(res,dp2[i-1]-dp2[idx]-(arr[i].y-arr[idx].x)+arr[i].x-arr[i-1].x+MOD);
		else add_self(res,arr[i].x-arr[i].y+MOD);
		dp2[i]=res;
	}
	for(int i=1;i<=n;++i){
		ll res=dp[i-1]+arr[i].x-arr[i-1].x+MOD;
		res%=MOD;
		int idx=closest(arr[i].y);
		if(arr[i].active){
			if(idx+1<i){
				ll buf=dp2[i-1]-dp2[idx]-(arr[i].y-arr[idx].x)+arr[i].x-arr[i-1].x+MOD;
				buf%=MOD;
				add_self(res,buf);
			}else add_self(res,arr[i].x-arr[i].y+MOD);
		}
		dp[i]=res;
	}
	cout<<(dp[n]+1)%MOD<<"\n";
}
