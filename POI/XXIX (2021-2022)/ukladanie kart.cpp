//Task statement: szkopul.edu.pl/problemset/problem/K5Ias1qqQ4YUqHd8dj6GMPFl/site/
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
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int NAX=2e6+7;
ll fact[NAX];
ll MOD=1e9+7;
ll mlp(ll A,ll B){
	return A*B%MOD;
}
ll add(ll A,ll B){
	return (A+B+MOD)%MOD;
}
ll vals[NAX];
ll n;
ll precalc[11]={0,0,1,15,168,1700,17220,182406,2055200,24767928,319463100};
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>MOD;
	if(n<=10){
		cout<<precalc[n]%MOD<<"\n";
		return 0;
	}
	fact[1]=1;
	for(ll i=2;i<NAX;++i) fact[i]=mlp(fact[i-1],i);
	vals[0]=1;
	ll curr=n-1;
	for(int i=1;i<n;++i){
		vals[i]=mlp(vals[i-1],curr);
		--curr;
	}
	for(int i=n;i<=2*n-3;++i){
		vals[i]=add(fact[n-1],-vals[i-n]);
	}
	ll total=0;
	for(ll i=1;i<=2*n-3;++i){
		total=add(total,mlp(vals[i],i));
	}
	ll ans=mlp(fact[n-2],n);
	ll pre=mlp(fact[n-2],n);
	ll multipl=mlp(n,n-1);
	total=add(total,-pre);
	for(ll i=2;i<=n-2;++i){
		pre=add(pre,mlp(fact[n-i-1],multipl));
		ans=add(ans,mlp(pre,i));
		total=add(total,-pre);
		multipl=mlp(multipl,n-i);
	}
	ans=add(ans,mlp(total,n-1));
	cout<<ans<<"\n";
}
