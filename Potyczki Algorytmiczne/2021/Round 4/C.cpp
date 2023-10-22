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
const int NAX=1e6+7;
int arr[NAX];
int pos[NAX];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) pos[arr[i]]=i;
	int l=pos[n],r=pos[n];
	int curr=0;
	ll ans=0;
	for(int i=n;i>=n/2+n%2;--i){
		l=min(l,pos[i]);
		r=max(r,pos[i]);
		if(r-l+1<=curr&&curr>0){
			int diff=curr-(r-l+1);
			int st=max(1,l-diff);
			int en=min(n,r+diff);
			ans+=(en-st+1)-curr+1;
		}
		++curr;
		if(curr>n) break;
		if(r-l+1<=curr){
			int diff=curr-(r-l+1);
			int st=max(1,l-diff);
			int en=min(n,r+diff);
			ans+=(en-st+1)-curr+1;
		}
		++curr;
		if(curr>n) break;
	}
	cout<<2*n+1<<" "<<ans<<"\n";
}
