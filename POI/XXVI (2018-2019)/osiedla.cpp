//Task statement: szkopul.edu.pl/problemset/problem/nldsb4EW1YuZykBlf4lcZL1Y/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+5;
int n,m;
vector<pair<int,int> > graph[SIZE];
vector<int> new_graph[SIZE],r_new_graph[SIZE];
pair<int,int> conns[SIZE];
int directions[SIZE];
int a,b;
bitset<SIZE> visited;
void DFS(int x){
	for(pair<int,int> v:graph[x]){
		if(!visited[v.second]){
			directions[v.second]=v.first;
			visited[v.second]=1;
			new_graph[x].push_back(v.first);
			r_new_graph[v.first].push_back(x);
			DFS(v.first);
		}
	}
}
vector<int> postorder;
void DFS2(int x){
	visited[x]=1;
	for(int v:new_graph[x]){
		if(!visited[v]) DFS2(v);
	}
	postorder.push_back(x);
}
int counter=0;
void DFS3(int x){
	visited[x]=1;
	for(int v:r_new_graph[x]){
		if(!visited[v]) DFS3(v);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		graph[a].push_back({b,i});
		graph[b].push_back({a,i});
		conns[i]={a,b};
	}
	for(int i=1;i<=n;++i){
		DFS(i);
	}
	visited.reset();
	for(int i=1;i<=n;++i){
		if(!visited[i]) DFS2(i);
	}
	visited.reset();
	for(int i=postorder.size()-1;i>=0;--i){
		if(!visited[postorder[i]]){
			DFS3(postorder[i]);
			++counter;
		}
	}
	cout<<counter<<"\n";
	for(int i=0;i<m;++i){
		if(directions[i]==conns[i].first) cout<<"<";
		else cout<<">";
	}
}
