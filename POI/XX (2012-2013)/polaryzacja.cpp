//Task statement: szkopul.edu.pl/problemset/problem/vG3DC9--8cjl4sPNwjBj9ag6/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=3e5+7,SQR=507;
vector<int> G[MAXN];
int amount[MAXN],parent[MAXN];
void DFS(int x,int pre){
	parent[x]=pre;
	for(int v:G[x]) if(v!=pre) DFS(v,x);
	amount[x]=1;
	for(int v:G[x]) if(v!=pre) amount[x]+=amount[v];
}
int centroid(int x,int pre,int N){
	int maxi=0,pos=0;
	for(int v:G[x]){
		if(v!=pre){
			if(amount[v]>maxi){
				maxi=amount[v];
				pos=v;
			}
		}
	}
	if(maxi<=N/2) return x;
	return centroid(pos,x,N);
}
ll res;
void DFS2(int x,int pre,int dep){
	res+=dep;
	for(int v:G[x]) if(v!=pre) DFS2(v,x,dep+1);
}
int cnt[SQR];
bool dp[MAXN];
bool temp[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,1);
	int vert=centroid(1,1,n);
	vector<int> vals;
	vals.pb(n-amount[vert]);
	for(int v:G[vert]) if(v!=parent[vert]) vals.pb(amount[v]);
	vector<int> to_check;
	for(int v:vals){
		if(v<SQR) ++cnt[v];
		else to_check.pb(v);
	}
	dp[0]=1;
	for(int v:to_check){
		for(int j=n;j>=v;--j){
			if(dp[j-v]) dp[j]=1;
		}
	}
	for(int i=1;i<SQR;++i){
		if(cnt[i]==0) continue;
		for(int j=n;j>=i;--j){
			if(dp[j-i]){
				for(int k=0;k<cnt[i];++k){
					if(temp[j+k*i]) break;
					temp[j+k*i]=1;
				}
			}
		}
		for(int j=1;j<=n;++j){
			dp[j]|=temp[j];
			temp[j]=0;
		}
	}
	DFS2(vert,vert,0);
	ll maxi=0;
	for(int i=1;i<MAXN;++i){
		if(dp[i]){
			if((ll)i*(n-i-1)>maxi) maxi=(ll)i*(n-i-1);
		}
	}
	cout<<n-1<<" "<<res+maxi<<"\n";
}
