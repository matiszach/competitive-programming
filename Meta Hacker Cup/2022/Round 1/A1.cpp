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
const int MAXN=5e5+7;
const pll MOD={7499944314905951,3021143604657433};
const pll P={1e9+7,1e9+9};
pll powers[MAXN];
pll H[MAXN],H2[MAXN];
int a[MAXN],b[MAXN];
bool compare_hashes(int s1,int e1,int s2,int e2){
	pll h1={0,0};
	h1.first=H[e1].first-H[s1-1].first+MOD.first;
	if(h1.first>=MOD.first) h1.first-=MOD.first;
	h1.second=H[e1].second-H[s1-1].second+MOD.second;
	if(h1.second>=MOD.second) h1.second-=MOD.second;
	pll h2={0,0};
	h2.first=H2[e2].first-H2[s2-1].first+MOD.first;
	if(h2.first>=MOD.first) h2.first-=MOD.first;
	h2.second=H2[e2].second-H2[s2-1].second+MOD.second;
	if(h2.second>=MOD.second) h2.second-=MOD.second;
	if(s1>s2) swap(h1,h2);
	int diff=abs(s2-s1);
	(h1.first*=powers[diff].first)%=MOD.first;
	(h1.second*=powers[diff].second)%=MOD.second;
	return h1==h2;
}
void solve_case(){
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	powers[0]={1,1};
	for(int i=1;i<=n;++i){
		powers[i].first=powers[i-1].first*P.first%MOD.first;
		powers[i].second=powers[i-1].second*P.second%MOD.second;
	}
	for(int i=1;i<=n;++i){
		H[i].first=(H[i-1].first+a[i]*powers[i].first)%MOD.first;
		H[i].second=(H[i-1].second+a[i]*powers[i].second)%MOD.second;
	}
	for(int i=1;i<=n;++i){
		H2[i].first=(H2[i-1].first+b[i]*powers[i].first)%MOD.first;
		H2[i].second=(H2[i-1].second+b[i]*powers[i].second)%MOD.second;
	}
	if(k==0){
		if(compare_hashes(1,n,1,n)) cout<<"YES\n";
		else cout<<"NO\n";
		return;
	}
	vector<int> shifts;
	for(int i=1;i<=n;++i){
		if(compare_hashes(1,i,n-i+1,n)&&compare_hashes(i+1,n,1,n-i)){
			shifts.pb(i);
		}
	}
	if(shifts.empty()){
		cout<<"NO\n";
		return;
	}
	if(shifts.size()==1&&shifts.back()==n&&k==1){
		cout<<"NO\n";
		return;
	}
	if(n==2&&shifts.size()==1&&shifts.back()%2!=k%2){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve_case();
	}
}
