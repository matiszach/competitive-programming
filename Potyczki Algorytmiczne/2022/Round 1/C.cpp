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
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	string s; cin>>s;
	int ans=0;
	for(int i=0;i<10;++i){
		bool ok=1;
		for(int j=0;j<n/10;++j){
			if(s[i*(n/10)+j]=='N'){
				ok=0;
				break;
			}
		}
		if(ok) ++ans;
	}
	cout<<ans<<"\n";
}
