// Task statement: https://codeforces.com/problemset/problem/1626/E
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
const int MAXN=3e5+7;
bool black[MAXN];
vector<int> T[MAXN];
pii edges[MAXN*2];
int dp[MAXN];
vector<int> G[MAXN];
void DFS(int x,int pre){
	for(int v:T[x]) if(v!=pre) DFS(v,x);
	dp[x]=black[x];
	for(int v:T[x]) if(v!=pre) dp[x]+=dp[v];
}
void DFS2(int x,int pre){
	if(dp[x]>1||black[x]) G[x].pb(pre);
	if(dp[1]-dp[x]>1||black[pre]) G[pre].pb(x);
	for(int v:T[x]) if(v!=pre) DFS2(v,x);
}
bool visited[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>black[i];
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		edges[i*2-1]={a,b};
		edges[i*2]={b,a};
		T[a].pb(b);
		T[b].pb(a);
	}
	DFS(1,1);
	DFS2(1,1);
	queue<int> Q;
	for(int i=1;i<=n;++i){
		if(black[i]){
			Q.push(i);
			visited[i]=1;
		}
	}
	while(!Q.empty()){
		int vert=Q.front(); Q.pop();
		for(int v:G[vert]){
			if(!visited[v]){
				visited[v]=1;
				Q.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i) cout<<visited[i]<<" ";
	cout<<"\n";
}
