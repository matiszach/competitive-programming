//Task statement: szkopul.edu.pl/problemset/problem/gxeCvLD1xW1t-Y33bbC0n3wZ/site/
//*Author Mateusz Kowalski*
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
const ll INFLL=8e18+7;
const int INF=1e9+7;
#define pb push_back
__int128 n,a,b;
int check(__int128 base,int req){
	__int128 curr=1;
	while(curr<=n){
		curr*=base;
		--req;
	}
	return req;
}
int main()
{
	ios_base::sync_with_stdio(0);
	ll tn,ta,tb;
	cin>>tn>>ta>>tb;
	n=tn; a=ta; b=tb;
	__int128 it=1,idx=0;
	while(it<=n){
		it<<=1;
		++idx;
	}
	vector<__int128> to_check;
	for(int i=1;i<=idx;++i){
		ll l=2,r=INFLL,mid=(l+r)>>1LL;
		while(l<r){
			if(check(mid,i)<0) l=mid+1;
			else r=mid;
			mid=(l+r)>>1LL;
		}
		to_check.pb(r);
	}
	__int128 ans=INFLL;
	for(ll i=0;i<(int)to_check.size();++i){
		__int128 x=to_check[i]-1;
		__int128 tmp=(__int128)(i+1)*(__int128)(a+x*b);
		__int128 maxi=0;
		if(x>1){
			for(int j=1;j<=i;++j){
				__int128 cnt=1;
				for(int k=1;k<=j;++k) cnt*=x;
				for(int k=j+1;k<=i+1;++k) cnt*=(x+1);
				if(cnt>n) maxi=j;
			}
		}
		ans=min(ans,tmp-(__int128)maxi*b);
	}
	cout<<(ll)ans<<"\n";
}
