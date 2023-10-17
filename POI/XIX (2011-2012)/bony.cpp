//Task statement: szkopul.edu.pl/problemset/problem/Y2sHfxzqdwT7qKzabT0fzmlB/site/
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
const int MAXN=1e6+7;
bool bon[MAXN];
int last[MAXN];
bool taken[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	int maxi=0;
	for(int i=1;i<=n;++i){
		int x; cin>>x;
		bon[x]=1;
		maxi=max(maxi,x);
	}
	int q; cin>>q;
	vector<ll> res;
	ll total=0;
	for(int i=1;i<=q;++i){
		int x; cin>>x;
		int curr=0;
		for(int j=last[x]+x;j<=maxi;j+=x){
			last[x]=j;
			if(taken[j]) continue;
			++curr;
			if(bon[j]) res.pb(curr+total);
			taken[j]=1;
			if(curr>=x) break;
		}
		total+=x;
	}
	cout<<res.size()<<"\n";
	for(ll &v:res) cout<<v<<"\n";
}
