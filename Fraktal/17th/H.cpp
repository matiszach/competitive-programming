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
int dp[MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; ll m; cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) cin>>arr[j];
		sort(arr+1,arr+n+1);
		int pos=0;
		for(int j=1;j<=n;++j) if(arr[j]<m) pos=j;
		if(pos<i){
			cout<<i-1<<"\n";
			return 0;
		}
		for(int j=pos-i+1;j<=pos;++j) m+=arr[j];
	}
	cout<<n<<"\n";
}
