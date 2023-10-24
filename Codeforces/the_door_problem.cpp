// Task statement: https://codeforces.com/problemset/problem/776/D
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
const int MAXN=1e5+7;
bool arr[MAXN];
int s1[MAXN],s2[MAXN];
vector<int> sat[MAXN*2],rsat[MAXN*2];
void make_edge(int a,int b){
	sat[a].pb(b);
	rsat[b].pb(a);
}
bool visited[MAXN*2];
vector<int> postorder;
void DFS(int x){
	visited[x]=1;
	for(int &v:sat[x]){
		if(!visited[v]) DFS(v);
	}
	postorder.pb(x);
}
int colors[MAXN*2];
int color;
void rDFS(int x){
	colors[x]=color;
	for(int &v:rsat[x]){
		if(!colors[v]) rDFS(v);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=m;++i){
		int y; cin>>y;
		for(int j=1;j<=y;++j){
			int x; cin>>x;
			if(!s1[x]) s1[x]=i;
			else s2[x]=i;
		}
	}
	for(int i=1;i<=n;++i){
		if(arr[i]){
			make_edge(s1[i]*2,s2[i]*2);
			make_edge(s2[i]*2,s1[i]*2);
			make_edge(s1[i]*2-1,s2[i]*2-1);
			make_edge(s2[i]*2-1,s1[i]*2-1);
		}else{
			make_edge(s1[i]*2,s2[i]*2-1);
			make_edge(s2[i]*2,s1[i]*2-1);
			make_edge(s1[i]*2-1,s2[i]*2);
			make_edge(s2[i]*2-1,s1[i]*2);
		}
	}
	for(int i=0;i<m*2;++i){
		if(!visited[i]) DFS(i);
	}
	reverse(postorder.begin(),postorder.end());
	for(int &v:postorder){
		if(!colors[v]){
			++color;
			rDFS(v);
		}
	}
	vector<int> res(m+1);
	for(int i=1;i<=m;++i){
		if(colors[i*2]==colors[i*2-1]){
			cout<<"NO\n";
			return 0;
		}
		res[i]=colors[i*2]>colors[i*2-1];
	}
	cout<<"YES\n";
}
