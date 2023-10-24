// Task statement: https://codeforces.com/problemset/problem/1626/D
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
const int MAXN=2e5+7;
int arr[MAXN];
int cnt[MAXN];
int nec[MAXN];
void solve_case(){
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) ++cnt[arr[i]];
	set<int> s;
	for(int i=1;i<=n;++i) s.insert(arr[i]);
	vector<int> pref={0};
	for(int v:s){
		pref.pb(pref.back()+cnt[v]);
	}
	int N=pref.size();
	int ans=INF;
	for(int i=1;i<N;++i){
		int curr=pref[i];
		for(int j=0;j<18;++j){
			int req=(1<<j);
			vector<int>::iterator it=upper_bound(pref.begin(),pref.end(),curr+req);
			--it;
			int rest=n-(*it);
			ans=min(ans,nec[curr]+nec[(*it)-curr]+nec[rest]);
		}
	}
	for(int v:s) cnt[v]=0;
	cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int curr=1;
	for(int i=0;i<MAXN;++i){
		if(i>curr) curr*=2;
		nec[i]=curr-i;
	}
	int t; cin>>t;
	for(int i=1;i<=t;++i) solve_case();
}
