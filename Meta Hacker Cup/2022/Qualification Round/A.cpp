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
const int MAXN=107;
int arr[MAXN];
int T[MAXN];
void solve_case(){
	int n,k; cin>>n>>k;
	for(int i=1;i<MAXN;++i) T[i]=0;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i){
		++T[arr[i]];
		if(T[arr[i]]>2){
			cout<<"NO\n";
			return;
		}
	}
	if(2*k<n) cout<<"NO\n";
	else cout<<"YES\n";
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
