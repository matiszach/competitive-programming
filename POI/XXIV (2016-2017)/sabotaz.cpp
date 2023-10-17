//Task statement: szkopul.edu.pl/problemset/problem/CUjJDGGSEZmO7HvdZU4FKrL6/site/
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
typedef long double ld;
const int MAXN=5e5+7;
vector<int> G[MAXN];
int amount[MAXN];
void DFS_ext(int x){
	for(int v:G[x]) DFS_ext(v);
	amount[x]=1;
	for(int v:G[x]) amount[x]+=amount[v];
}
int dp[MAXN];
void DFS(int x,ld m){
	for(int v:G[x]) DFS(v,m);
	dp[x]=1;
	if(G[x].empty()) return;
	int maxi=0;
	for(int v:G[x]) maxi=max(maxi,dp[v]);
	if((ld)maxi/(ld)(amount[x]-1)>m) dp[x]=amount[x];
	else dp[x]=maxi;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n,k; cin>>n>>k;
	for(int i=2;i<=n;++i){
		int x; cin>>x;
		G[x].pb(i);
	}
	DFS_ext(1);
	ld l=0,r=1,mid=0;
	while(r-l>(1e-8)){
		mid=(l+r)/(ld)2;
		for(int i=1;i<=n;++i) dp[i]=0;
		DFS(1,mid);
		if(dp[1]>k) l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(8)<<mid<<"\n";
}
