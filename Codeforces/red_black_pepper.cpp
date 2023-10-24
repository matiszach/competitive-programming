// Task statement: https://codeforces.com/problemset/problem/1728/E
// *Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __int128 ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=3e5+7;
int a[MAXN],b[MAXN];
long long res[MAXN];
ll prefA[MAXN],prefB[MAXN];
pll euclides(ll x,ll y){
	if(x%y==0) return {0,1};
	pll curr=euclides(y,x%y);
	ll tmp=curr.second;
	curr.second=curr.first-(x/y)*curr.second;
	curr.first=tmp;
	return curr;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i]>>b[i];
	vector<pair<ll,pll>> V;
	for(int i=1;i<=n;++i){
		V.pb({a[i]-b[i],{a[i],b[i]}});
	}
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	for(int i=1;i<=n;++i) prefA[i]=prefA[i-1]+V[i-1].second.first;
	for(int i=n;i>=1;--i) prefB[i]=prefB[i+1]+V[i-1].second.second;
	for(int i=0;i<=n;++i) res[i]=prefA[i]+prefB[i+1];
	int pos=0;
	for(int i=1;i<=n;++i){
		if(res[pos]<res[i]) pos=i;
	}
	int m; cin>>m;
	for(int i=1;i<=m;++i){
		long long x,y; cin>>x>>y;
		if(x==1&&y==1){
			cout<<res[pos]<<"\n";
			continue;
		}
		ll g=__gcd(x,y);
		if(n%g!=0){
			cout<<"-1\n";
			continue;
		}
		ll c=n/g;
		pll sol=euclides(x,y);
		sol.first*=c; sol.second*=c;
		ll X=sol.first*x;
		ll diff=abs(x*y)/g;
		X-=diff*((ll)1e18/diff);
		ll pot1=((pos-X)/diff)*diff+X;
		ll pot2=pot1+diff;
		long long ans=-1;
		if(pot1>=0&&pot1<=n&&(n-pot1)%y==0) ans=res[pot1];
		if(pot2>=0&&pot2<=n&&(n-pot2)%y==0) ans=max(ans,res[pot2]);
		cout<<ans<<"\n";
	}
}
