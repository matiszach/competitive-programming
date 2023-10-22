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
const long long MOD=1e9+7;
const int MAXN=5e5+7;
pii trees[MAXN],wells[MAXN];
void solve_case(){
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>trees[i].first>>trees[i].second;
	int q; cin>>q;
	for(int i=1;i<=q;++i) cin>>wells[i].first>>wells[i].second;
	long long ans=0;
	vector<pair<pii,bool>> V;
	for(int i=1;i<=n;++i) V.pb({trees[i],0});
	for(int i=1;i<=q;++i) V.pb({wells[i],1});
	sort(V.begin(),V.end());
	ll to_add=0,ens=0,opened=0,pre_x=V[0].first.first;
	for(auto p:V){
		ll diff=p.first.first-pre_x;
		pre_x=p.first.first;
		ll tmp=diff*(2*ens+2*opened+2*(ens+opened*(diff-1)%MOD))/2;
		tmp%=MOD;
		(ens+=opened*diff)%=MOD;
		(to_add+=tmp)%=MOD;
		if(!p.second){
			opened+=1;
		}else{
			(ans+=to_add)%=MOD;
		}
	}
	reverse(V.begin(),V.end());
	to_add=0,ens=0,opened=0,pre_x=V[0].first.first;
	for(auto p:V){
		ll diff=pre_x-p.first.first;
		pre_x=p.first.first;
		ll tmp=diff*(2*ens+2*opened+2*(ens+opened*(diff-1)%MOD))/2;
		tmp%=MOD;
		(ens+=opened*diff)%=MOD;
		(to_add+=tmp)%=MOD;
		if(!p.second){
			opened+=1;
		}else{
			(ans+=to_add)%=MOD;
		}
	}
	for(auto &p:V) swap(p.first.first,p.first.second);
	sort(V.begin(),V.end());
	to_add=0,ens=0,opened=0,pre_x=V[0].first.first;
	for(auto p:V){
		ll diff=p.first.first-pre_x;
		pre_x=p.first.first;
		ll tmp=diff*(2*ens+2*opened+2*(ens+opened*(diff-1)%MOD))/2;
		tmp%=MOD;
		(ens+=opened*diff)%=MOD;
		(to_add+=tmp)%=MOD;
		if(!p.second){
			opened+=1;
		}else{
			(ans+=to_add)%=MOD;
		}
	}
	reverse(V.begin(),V.end());
	to_add=0,ens=0,opened=0,pre_x=V[0].first.first;
	for(auto p:V){
		ll diff=pre_x-p.first.first;
		pre_x=p.first.first;
		ll tmp=diff*(2*ens+2*opened+2*(ens+opened*(diff-1)%MOD))/2;
		tmp%=MOD;
		(ens+=opened*diff)%=MOD;
		(to_add+=tmp)%=MOD;
		if(!p.second){
			opened+=1;
		}else{
			(ans+=to_add)%=MOD;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve_case();
	}
}
