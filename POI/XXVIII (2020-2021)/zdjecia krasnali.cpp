//Task statement: szkopul.edu.pl/problemset/problem/GfCNwxdYubiS1Nlnb_h7VkJW/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=5e5+7;
int n,m,a,b;
vector<int> graph[SIZE],final[SIZE];
int edges[SIZE];
int enter_deg[SIZE];
queue<int> q;
int edges_num=0;
bitset<SIZE> visited;
vector<int> order;
int idx[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		++edges[a];
		++edges[b];
		++edges_num;
	}
	q.push(1);
	while(!q.empty()){
		int vert=q.front();
		q.pop();
		if(vert==2) continue;
		visited[vert]=1;
		for(int v:graph[vert]){
			if(visited[v]) continue;
			++enter_deg[v];
			--edges_num;
			final[vert].push_back(v);
			if(edges[v]/enter_deg[v]==2){
				q.push(v);
			}
			else if(edges[v]/2<enter_deg[v]&&v!=2){
				cout<<"NIE\n";
				return 0;
			}
		}
	}
	if(edges_num>0){
		cout<<"NIE\n";
		return 0;
	}
	visited.reset();
	q.push(1);
	visited[1]=1;
	order.push_back(1);
	while(!q.empty()){
		int vert=q.front();
		q.pop();
		for(int v:final[vert]){
			if(visited[v]) continue;
			--enter_deg[v];
			if(enter_deg[v]==0){
				q.push(v);
				visited[v]=1;
				order.push_back(v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]) order.push_back(i);
	}
	for(int i=0;i<order.size();++i){
		idx[order[i]]=i+1;
	}
	cout<<"TAK\n";
	for(int i=1;i<=n;++i){
		cout<<idx[i]<<" ";
	}
}
