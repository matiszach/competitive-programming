// Task statement: https://www.spoj.com/problems/PON/
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
typedef __int128 i128;
ll binpow(ll x,ll p,ll mod){
	i128 res=1,curr=x;
	for(int i=0;i<63;++i){
		if((1LL<<i)&p) (res*=curr)%=mod;
		(curr*=curr)%=mod;
	}
	return res;
}
bool check(ll a,ll p,ll s,int d){
	i128 x=binpow(a,s,p);
	if(x==1||x==p-1) return 0;
	for(int i=1;i<=d;++i){
		(x*=x)%=p;
		if(x==p-1) return 0;
	}
	return 1;
}
ll super_rand(ll a,ll b){
	ll x=(ll)(rand()%RAND_MAX)*RAND_MAX;
	return a+x%(b-a);
}
bool miller_rabin(ll x,int k){
	if(x==2||x==3) return 1;
	if(x<4) return 0;
	ll s=x-1;
	int d=0;
	while((s&1)==0){
		s>>=1;
		++d;
	}
	for(int i=1;i<=k;++i){
		ll a=super_rand(2,x-1);
		if(check(a,x,s,d)) return 0;
	}
	return 1;
}
void solve_case(){
	ll n; cin>>n;
	cout<<(miller_rabin(n,30)?"YES":"NO")<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	srand(420);
	int t; cin>>t;
	while(t--) solve_case();
}
