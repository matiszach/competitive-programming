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
const int MAXN=1007;
int pref_hor[MAXN][MAXN];
int suf_hor[MAXN][MAXN];
int pref_ver[MAXN][MAXN];
int suf_ver[MAXN][MAXN];
int arr[MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>arr[i][j];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) pref_hor[i][j]=max(pref_hor[i][j-1],arr[i][j]);
		for(int j=m;j>=1;--j) suf_hor[i][j]=max(suf_hor[i][j+1],arr[i][j]);
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j) pref_ver[j][i]=max(pref_ver[j-1][i],arr[j][i]);
		for(int j=n;j>=1;--j) suf_ver[j][i]=max(suf_ver[j+1][i],arr[j][i]);
	}
	int ans=0;
	for(int i=2;i<n;++i){
		for(int j=2;j<m;++j){
			if(arr[i][j]&&pref_hor[i][j-1]>=arr[i][j]&&suf_hor[i][j+1]>=arr[i][j]
			&&pref_ver[i-1][j]>=arr[i][j]&&suf_ver[i+1][j]>=arr[i][j]) ++ans;
		}
	}
	cout<<ans<<"\n";
}
