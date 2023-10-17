//Task statement: szkopul.edu.pl/problemset/problem/VdGoo4AEt68ZDztfDsJ34iiP/site/
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
const ll INFLL=5e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=1e6+7;
int n,k;
ll m;
vector<ll> arr;
vector<int> closest;
ll dist(int a,int b){
	return max(arr[a],arr[b])-min(arr[a],arr[b]);
}
int res[MAXN];
vector<int> G[MAXN];
vector<int> cycle[MAXN];
int c[MAXN],pos[MAXN];
bitset<MAXN> visited;
vector<int> colors;
int color;
void DFS(int x){
	colors[x]=color;
	for(int v:G[x]) if(colors[v]==0) DFS(v);
}
bitset<MAXN> col;
vector<int> verts;
int cnt=0;
void DFS2(int x,int dst,int last_vert){
	visited[x]=1;
	++cnt;
	if(c[x]==0){
		verts.pb(x);
		if(dst+1>m) res[x]=verts[dst-m];
		else{
			ll new_m=m;
			new_m-=(dst+1);
			ll len=cycle[c[last_vert]].size();
			new_m%=len;
			res[x]=cycle[c[last_vert]][(pos[last_vert]-new_m+len)%len];
		}
		for(int v:G[x]){
			if(!visited[v]) DFS2(v,dst+1,last_vert);
		}
		verts.pop_back();
	}else{
		ll new_m=m;
		ll len=cycle[c[x]].size();
		new_m%=len;
		res[x]=cycle[c[x]][(pos[x]-new_m+len)%len];
		for(int v:G[x]){
			if(!visited[v]) DFS2(v,0,x);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>m;
	arr.resize(n+2);
	closest.resize(n+2);
	for(int i=1;i<=n;++i) cin>>arr[i];
	arr[0]=-INFLL;
	arr[n+1]=INFLL;
	closest[1]=k+1;
	int left=0,right=k;
	for(int i=2;i<=n;++i){
		while(dist(i,i-left-1)<=dist(i,i+right)){
			++left; --right;
		}
		while(dist(i,i+right+1)<dist(i,i-left)){
			--left; ++right;
		}
		if(dist(i,i-left)>=dist(i,i+right)) closest[i]=i-left;
		else closest[i]=i+right;
	}
	arr.clear();
	arr.resize(0);
	arr.shrink_to_fit();
	for(int i=1;i<=n;++i){
		G[i].pb(closest[i]);
		G[closest[i]].pb(i);
	}
	colors.resize(n+2);
	for(int i=1;i<=n;++i){
		if(colors[i]==0){
			++color;
			DFS(i);
		}
	}
	visited.reset();
	int counter=0;
	for(int i=1;i<=n;++i){
		if(!col[colors[i]]){
			int curr=i;
			visited[curr]=1;
			col[colors[curr]]=1;
			vector<int> enc;
			enc.pb(curr);
			while(!visited[closest[curr]]){
				curr=closest[curr];
				visited[curr]=1;
				enc.pb(curr);
			}
			int rep=closest[curr];
			++counter;
			int idx=0;
			while(enc.back()!=rep){
				c[enc.back()]=counter;
				cycle[counter].pb(enc.back());
				pos[enc.back()]=idx++;
				visited[enc.back()]=0;
				enc.pop_back();
			}
			c[enc.back()]=counter;
			cycle[counter].pb(enc.back());
			pos[enc.back()]=idx++;
			visited[enc.back()]=0;
			enc.pop_back();
			while(!enc.empty()){
				visited[enc.back()]=0;
				enc.pop_back();
			}
		}
	}
	closest.clear();
	closest.resize(0);
	closest.shrink_to_fit();
	visited.reset();
	colors.clear();
	colors.resize(0);
	colors.shrink_to_fit();
	for(int i=1;i<=n;++i){
		if(!visited[i]&&c[i]>0){
			DFS2(i,0,i);
			cycle[c[i]].clear();
			cycle[c[i]].resize(0);
			cycle[c[i]].shrink_to_fit();
		}
	}
	for(int i=1;i<=n;++i) cout<<res[i]<<" ";
}
