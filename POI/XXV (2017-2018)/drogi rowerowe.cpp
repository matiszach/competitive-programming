//Task statement: szkopul.edu.pl/problemset/problem/aKKSmtjWTtDOEHDqnmQ3-eAA/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=5e4+5;
int n,m,a,b;
vector<int> graph[SIZE],r_graph[SIZE],new_graph[SIZE],r_new_graph[SIZE];
#define pb push_back
bitset<SIZE> visited;
vector<int> postorder;
void DFS(int x){
	visited[x]=1;
	for(int v:graph[x]){
		if(!visited[v]) DFS(v);
	}
	postorder.pb(x);
}
int counter=0;
int colors[SIZE];
int sizes[SIZE];
int values[SIZE];
void DFS2(int x){
	visited[x]=1;
	colors[x]=counter;
	++sizes[counter];
	for(int v:r_graph[x]){
		if(!visited[v]) DFS2(v);
	}
}
void DFS4(int x){
	visited[x]=1;
	for(int v:new_graph[x]){
		if(!visited[v]) DFS4(v);
	}
	postorder.pb(x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		graph[a].pb(b);
		r_graph[b].pb(a);
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			DFS(i);
		}
	}
	visited.reset();
	for(int i=postorder.size()-1;i>=0;--i){
		if(!visited[postorder[i]]){
			++counter;
			DFS2(postorder[i]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int v:graph[i]){
			if(colors[i]!=colors[v]){
				new_graph[colors[i]].pb(colors[v]);
				r_new_graph[colors[v]].pb(colors[i]);
			}
		}
	}
	visited.reset();
	postorder.clear();
	for(int i=1;i<=counter;++i){
		if(!visited[i]){
			DFS4(i);
		}
	}
	visited.reset();
	for(int e:postorder){
		for(int v:new_graph[e]){
			values[e]+=values[v]+1;
		}
		values[e]+=sizes[e]-1;
	}
	for(int i=1;i<=n;++i){
		cout<<max(values[colors[i]],sizes[colors[i]]-1)<<"\n";
	}
}
