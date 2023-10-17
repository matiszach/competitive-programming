//Task statement: szkopul.edu.pl/problemset/problem/hxMnCQMERV9OY1QwAdEXxQFy/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=3e6+7;
int n,k,a,b;
vector<int> graph[SIZE];
int max_node=0,max_dist=0;
int parent[SIZE],deg[SIZE];
void DFS(int x,int prev,int dist){
	parent[x]=prev;
	if(dist>max_dist){
		max_dist=dist;
		max_node=x;
	}
	for(int v:graph[x]){
		if(v!=prev) DFS(v,x,dist+1);
	}
}
int leaf[SIZE];
vector<int> layers[SIZE];
void DFS2(int x,int prev){
	if(deg[x]==1){
		leaf[x]=0;
	}
	for(int v:graph[x]){
		if(v!=prev){
			DFS2(v,x);
			if(leaf[v]>-1)
			leaf[x]=max(leaf[v]+1,leaf[x]);
		}
	}
	layers[leaf[x]].push_back(x);
}
vector<int> path;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<n;++i){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		++deg[a];
		++deg[b];
	}
	DFS(1,1,0);
	int min_node=max_node;
	max_dist=0;
	DFS(min_node,min_node,0);
	int curr_node=max_node;
	path.push_back(curr_node);
	while(curr_node!=min_node){
		curr_node=parent[curr_node];
		path.push_back(curr_node);
	}
	int root=path[path.size()/2];
	path.clear();
	for(int i=1;i<=n;++i) leaf[i]=-1;
	DFS2(root,root);
	int idx=0;
	while(layers[idx].size()>k){
		++idx;
	}
	cout<<idx<<" "<<max((int)layers[idx].size(),2)<<"\n";
	if(layers[idx].size()==1){
		cout<<layers[idx][0]<<" "<<graph[layers[idx][0]][0]<<"\n";
	}else{
		for(int v:layers[idx]) cout<<v<<" ";
	}
}
