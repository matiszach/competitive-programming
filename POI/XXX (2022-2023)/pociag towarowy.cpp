//Task statement: szkopul.edu.pl/problemset/problem/MAWN1VdLdXO29VvrVYuYxQyw/site/
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
const int MAXN=3e5+7;
int org[MAXN],arr[MAXN];
int pref[MAXN],suf[MAXN];
vector<int> pos[MAXN];
bool res[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i=1;i<=n;++i) cin>>org[i];
	for(int i=1;i<=m;++i) cin>>arr[i];
	for(int i=1;i<=m;++i) pos[arr[i]].pb(i);
	int idx=0;
	for(int i=1;i<=n;++i){
		pref[i]=pref[i-1];
		if(org[i]==arr[idx+1]){
			++pref[i];
			++idx;
		}
	}
	idx=m+1;
	suf[n+1]=m;
	for(int i=n;i>=1;--i){
		suf[i]=suf[i+1];
		if(org[i]==arr[idx-1]){
			--suf[i];
			--idx;
		}
	}
	for(int i=1;i<=n;++i){
		int x=org[i];
		vector<int>::iterator it=upper_bound(pos[x].begin(),pos[x].end(),pref[i]);
		if(it==pos[x].begin()) continue;
		--it;
		if(suf[i+1]<=(*it)) res[i]=1;
	}
	for(int i=1;i<=n;++i) cout<<res[i]<<" ";
	cout<<"\n";
}
