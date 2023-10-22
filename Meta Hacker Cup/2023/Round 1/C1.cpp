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
const int MAXN=4e6+7;
bool arr[MAXN];
bool cnt[MAXN];
void solve_case(){
	int n; cin>>n;
	string s; cin>>s;
	for(int i=0;i<n;++i) arr[i+1]=(s[i]=='0'?0:1);
	int q; cin>>q;
	for(int i=1;i<=n;++i) cnt[i]=0;
	for(int i=1;i<=q;++i){
		int x; cin>>x;
		cnt[x]=!cnt[x];
	}
	for(int i=1;i<=n;++i){
		if(!cnt[i]) continue;
		for(int j=i;j<=n;j+=i) arr[j]^=1;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(arr[i]){
			for(int j=i;j<=n;j+=i) arr[j]^=1;
			++ans;
		}
	}
	cout<<ans<<"\n";
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
