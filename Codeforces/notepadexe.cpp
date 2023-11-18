// Task statement: https://codeforces.com/contest/1672/problem/E
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
int ask(int val){
	cout<<"? "<<val<<endl;
	int res; cin>>res;
	cout.flush();
	return res;
}
void solve_case(){
	int n; cin>>n;
	int l=1,r=1e9,mid=0;
	while(l<r){
		mid=(l+r)>>1;
		if(ask(mid)==1) r=mid;
		else l=mid+1;
	}
	int ans=l;
	for(int i=2;i<=n;++i){
		int tmp=ans-1;
		int x=(tmp-1)/i+1;
		if(x*i>=ans) --x;
		int res=ask(x);
		if(res==i) ans=min(ans,res*x);
	}
	cout<<"! "<<ans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	solve_case();
}
