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
const int MAXN=1e5+7;
ll arr[MAXN];
typedef long double ld;
void solve_case(){
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	sort(arr+1,arr+n+1);
	if(n>=6||n==4){
		ld st=(ld)(arr[1]+arr[2])/2;
		ld nd=(ld)(arr[n-1]+arr[n])/2;
		ld res=nd-st;
		cout<<fixed<<setprecision(10)<<res<<"\n";
	}else{
		ld st=(ld)(arr[1]+arr[3])/2;
		ld nd=(ld)(arr[n-1]+arr[n])/2;
		ld res=nd-st;
		st=(ld)(arr[1]+arr[2])/2;
		nd=(ld)(arr[n-2]+arr[n])/2;
		res=max(res,nd-st);
		cout<<fixed<<setprecision(10)<<res<<"\n";
	}
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
