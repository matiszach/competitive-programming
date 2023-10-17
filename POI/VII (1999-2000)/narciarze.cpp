//Task statement: szkopul.edu.pl/problemset/problem/PUVCH73E4h3hU8UPiJqvvLmQ/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=5e3+1;
int n,q,z;
vector<int> graph[SIZE];
bitset<SIZE> visited,temp_visited;
stack<int> curr_path;
int paths=0;
bool done=false;
void DFS(int x){
	if(done) return;
	if(x==n){
		while(!curr_path.empty()){
			visited[curr_path.top()]=1;
			curr_path.pop();
		}
		++paths;
		done=1;
		return;
	}
	temp_visited[x]=1;
	curr_path.push(x);
	for(int v:graph[x]){
		if(!visited[v]&&!temp_visited[v]) DFS(v);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>q;
		for(int j=0;j<q;++j){
			cin>>z;
			graph[i].push_back(z);
		}
	}
	for(int v:graph[1]){
		done=0;
		DFS(v);
		while(!curr_path.empty()) curr_path.pop();
		temp_visited.reset();
	}
	cout<<paths<<"\n";
}
