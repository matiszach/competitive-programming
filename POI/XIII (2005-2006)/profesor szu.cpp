//Task statement: szkopul.edu.pl/problemset/problem/mBGR2EV0zVOpK9nHSlOL0aNr/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+7,INF=36500;
int n,m,a,b;
vector<int> graph[SIZE],postorder,visited,on_stack,res;
void DFS(int x){
	visited[x]=1;
	on_stack[x]=1;
	for(int v:graph[x]){
		if(visited[v]==0) DFS(v);
		else if(on_stack[v]==1) visited[v]=2;
	}
	on_stack[x]=0;
}
void DFS2(int x){
	visited[x]=2;
	for(int v:graph[x]){
		if(visited[v]==1) DFS2(v);
	}
}
void DFS3(int x){
	visited[x]=1;
	for(int v:graph[x]){
		if(visited[v]==0) DFS3(v);
	}
	postorder.push_back(x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		graph[b].push_back(a);
	}
	visited.resize(n+2,0);
	on_stack.resize(n+2,0);
	DFS(n+1);
	for(int i=1;i<=n+1;++i){
		if(visited[i]==2) DFS2(i);
	}
	on_stack.clear();
	on_stack.shrink_to_fit();
	res.resize(n+2,0);
	for(int i=1;i<=n+1;++i){
		if(visited[i]==2) res[i]=INF;
	}
	for(int i=1;i<=n+1;++i) visited[i]=0;
	for(int i=1;i<=n+1;++i){
		if(visited[i]==0) DFS3(i);
	}
	visited.clear();
	visited.shrink_to_fit();
	res[n+1]=1;
	for(int i=postorder.size()-1;i>=0;--i){
		for(int v:graph[postorder[i]]){
			res[v]=min(INF,res[v]+res[postorder[i]]);
		}
	}
	int ans=0,amount=0;
	for(int i=1;i<=n;++i) ans=max(ans,res[i]);
	for(int i=1;i<=n;++i){
		if(ans==res[i]) ++amount;
	}
	if(ans==INF) cout<<"zawsze\n";
	else cout<<ans<<"\n";
	cout<<amount<<"\n";
	for(int i=1;i<=n;++i){
		if(ans==res[i]) cout<<i<<" ";
	}
}
