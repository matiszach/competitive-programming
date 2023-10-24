// Task statement: https://codeforces.com/problemset/problem/868/F
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
const int NAX=1e5+7;
ll dp[NAX],dp_prev[NAX];
ll cost;
int n,k;
int arr[NAX];
vector<int> buf;
int cnt[NAX];
int L,R;
void adjust_cost(int l,int r){
	while(L<l) cost-=(--cnt[arr[L++]]);
	while(L>l) cost+=(cnt[arr[--L]]++);
	while(R<r) cost+=(cnt[arr[++R]]++);
	while(R>r) cost-=(--cnt[arr[R--]]);
}
void compute(int l,int r,int optl,int optr){
	if(l>r) return;
	int mid=(l+r)>>1;
	pll res={INFLL,-1};
	for(int i=optl;i<=min(mid,optr);++i){
		adjust_cost(i,mid);
		res=min(res,{dp_prev[i-1]+cost,i});
	}
	dp[mid]=res.first;
	compute(l,mid-1,optl,res.second);
	compute(mid+1,r,res.second,optr);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) dp_prev[i]=dp_prev[i-1]+(cnt[arr[i]]++);
	for(int i=1;i<=n;++i) cnt[i]=0;
	L=1; R=0;
	for(int i=1;i<k;++i){
		compute(1,n,1,n);
		for(int j=1;j<=n;++j) dp_prev[j]=dp[j];
	}
	cout<<dp[n]<<"\n";
}
