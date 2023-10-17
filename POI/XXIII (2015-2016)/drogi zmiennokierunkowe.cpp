//Task statement: szkopul.edu.pl/problemset/problem/9TaxfuNdAv2FPpQ6PeB-vlti/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=5e5+7;
int n,m,a,b;
vector<int> graph[SIZE],r_graph[SIZE],G[SIZE],RG[SIZE];
#define pb push_back
vector<int> postorder;
bitset<SIZE> visited,bad;
int dist[SIZE];
void DFS(int x){
	visited[x]=1;
	for(int v:graph[x]){
		if(!visited[v]) DFS(v);
	}
	postorder.pb(x);
}
int color;
int colors[SIZE];
void DFS2(int x){
	visited[x]=1;
	colors[x]=color;
	for(int v:r_graph[x]){
		if(!visited[v]) DFS2(v);
	}
}
void DFS3(int x){
	visited[x]=1;
	for(int v:G[x]){
		if(!visited[v]) DFS3(v);
	}
	postorder.pb(x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		graph[a].pb(b);
		r_graph[b].pb(a);
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]) DFS(i);
	}
	visited.reset();
	for(int i=n-1;i>=0;--i){
		if(!visited[postorder[i]]){
			++color;
			DFS2(postorder[i]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int v:graph[i]){
			if(colors[i]!=colors[v]){
				G[colors[i]].pb(colors[v]);
				RG[colors[v]].pb(colors[i]);
			}
		}
	}
	visited.reset();
	postorder.clear();
	for(int i=1;i<=color;++i){
		if(!visited[i]) DFS3(i);
	}
	for(int i=0;i<(int)postorder.size()/2;++i) swap(postorder[i],postorder[(int)postorder.size()-1-i]);
	int curr=0;
	for(int i=0;i<(int)postorder.size();++i) dist[postorder[i]]=i;
	for(int i=0;i<(int)postorder.size();++i){
		if(i<curr) bad[postorder[i]]=1;
		int mini=n+1;
		for(int v:G[postorder[i]]) mini=min(mini,dist[v]);
		curr=max(curr,mini);
	}
	curr=postorder.size()-1;
	for(int i=postorder.size()-1;i>=0;--i){
		if(i>curr) bad[postorder[i]]=1;
		int maxi=-1;
		for(int v:RG[postorder[i]]) maxi=max(maxi,dist[v]);
		curr=min(curr,maxi);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(!bad[colors[i]]) ++ans;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i){
		if(!bad[colors[i]]) cout<<i<<" ";
	}
}
