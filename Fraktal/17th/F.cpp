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
int arr[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,p; cin>>n>>p;
	for(int i=1;i<=n;++i) cin>>arr[i];
	int cnt=0;
	for(int i=1;i<=n;++i) cnt+=arr[i];
	for(int i=n;i>=1;--i){
		arr[i]=min(cnt,p);
		cnt-=min(cnt,p);
	}
	int q; cin>>q;
	for(int i=1;i<=q;++i){
		int x; cin>>x;
		cout<<arr[x]<<"\n";
	}
}
