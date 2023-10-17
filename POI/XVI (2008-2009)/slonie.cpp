//Task statement: szkopul.edu.pl/problemset/problem/hVt8GQhxDxdYzrhLngOSJuzS/site/
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
int n;
int arr[MAXN];
int org[MAXN],trg[MAXN],where_banana[MAXN];
bitset<MAXN> visited;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	int glob_min=arr[1];
	for(int i=1;i<=n;++i) glob_min=min(glob_min,arr[i]);
	for(int i=1;i<=n;++i) cin>>org[i];
	for(int i=1;i<=n;++i) cin>>trg[i];
	for(int i=1;i<=n;++i) where_banana[trg[i]]=i;
	ll ans=0;
	for(int i=1;i<=n;++i){
		int curr=org[i];
		vector<int> cycle;
		while(!visited[curr]){
			cycle.pb(curr);
			visited[curr]=1;
			curr=org[where_banana[curr]];
		}
		if((int)cycle.size()<=1) continue;
		ll total=0;
		for(int v:cycle) total+=arr[v];
		ll mini=arr[cycle[0]];
		for(int v:cycle) mini=min(mini,(ll)arr[v]);
		ll amount=(int)cycle.size();
		ans+=total+min(mini+glob_min*(amount+1),mini*(amount-2));
	}
	cout<<ans<<"\n";
}
