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
const int MAXN=1e5+7;
ll t[MAXN],p[MAXN];
int n;
ll m;
bool check(int x){
	priority_queue<ll> Q;
	for(int i=1;i<=x;++i) Q.push(0);
	for(int i=1;i<=n;++i){
		ll val=-Q.top(); Q.pop();
		if(val>t[i]+m) return 0;
		val=max(val,t[i]);
		Q.push(-val-p[i]*2);
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>t[i];
	for(int i=1;i<=n;++i) cin>>p[i];
	int l=1,r=n,mid=0;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
}
