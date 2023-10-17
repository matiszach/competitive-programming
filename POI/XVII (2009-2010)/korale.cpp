//Task statement: szkopul.edu.pl/problemset/problem/z8Vva6nazo2Cy3CF67kT6IWe/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=2e5+7;
int arr[MAXN];
pll H[MAXN],R[MAXN];
const pll P={213139,278849};
const pll MOD={1e9+7,1e9+696969};
pll powers[MAXN];
int res[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	powers[0]={1,1};
	for(int i=1;i<=n;++i){
		powers[i].first=(powers[i-1].first*P.first)%MOD.first;
		powers[i].second=(powers[i-1].second*P.second)%MOD.second;
	}
	for(int i=1;i<=n;++i){
		H[i].first=(H[i-1].first+arr[i]*powers[i].first)%MOD.first;
		H[i].second=(H[i-1].second+arr[i]*powers[i].second)%MOD.second;
	}
	for(int i=n;i>=1;--i){
		R[i].first=(R[i+1].first+arr[i]*powers[n-i+1].first)%MOD.first;
		R[i].second=(R[i+1].second+arr[i]*powers[n-i+1].second)%MOD.second;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		vector<pll> V;
		for(int j=i;j<=n;j+=i){
			pll val={0,0};
			val.first=(H[j].first-H[j-i].first+MOD.first)*powers[n-j].first%MOD.first;
			val.second=(H[j].second-H[j-i].second+MOD.second)*powers[n-j].second%MOD.second;
			pll valR={0,0};
			valR.first=(R[j-i+1].first-R[j+1].first+MOD.first)*powers[j-i].first%MOD.first;
			valR.second=(R[j-i+1].second-R[j+1].second+MOD.second)*powers[j-i].second%MOD.second;
			V.pb(min(val,valR));
		}
		int cnt=1;
		sort(V.begin(),V.end());
		for(int j=1;j<(int)V.size();++j){
			if(V[j]!=V[j-1]) ++cnt;
		}
		res[i]=cnt;
		ans=max(ans,cnt);
	}
	vector<int> idx;
	for(int i=1;i<=n;++i) if(res[i]==ans) idx.pb(i);
	cout<<ans<<" "<<(int)idx.size()<<"\n";
	for(int v:idx) cout<<v<<"\n";
}
