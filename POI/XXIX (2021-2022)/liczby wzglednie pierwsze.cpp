//Task statement: szkopul.edu.pl/problemset/problem/kQ5ExYNkFhx3K2FvVuXAAbn4/site/
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
vector<ll> facts;
ll n,k,c;
ll count(ll x){
	ll res=0;
	for(ll &v:facts){
		res+=x/v;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>c;
	vector<ll> factors;
	ll N=n;
	for(ll i=2;i*i<=N;++i){
		while(N%i==0){
			N/=i;
			if(factors.empty()||factors.back()!=i) factors.pb(i);
		}
	}
	if(N!=1) if(factors.empty()||factors.back()!=N) factors.pb(N);
	int K=(int)factors.size();
	for(int mask=1;mask<(1<<K);++mask){
		ll curr=1;
		for(int j=0;j<K;++j){
			if((1<<j)&mask) curr*=factors[j];
		}
		facts.pb(curr*((int)__builtin_popcount(mask)%2?1:-1));
	}
	ll l=1,r=k*1000,mid=0;
	while(l<r){
		mid=(l+r)>>1;
		if(mid-count(mid)<k) l=mid+1;
		else r=mid;
	}
	cout<<l<<" ";
	while(c>1){
		++l;
		if(__gcd(l,n)==1){
			cout<<l<<" ";
			--c;
		}
	}
	cout<<"\n";
}

