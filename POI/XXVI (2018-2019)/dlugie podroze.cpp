//Task statement: szkopul.edu.pl/problemset/problem/QHh99tBu4p9FMsFohv4da7S7/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e5+7,RND=2e2+7;
int n,m,p,a,b;
vector<int> graph[SIZE];
queue<int> q;
bitset<SIZE> visited;
int dist[RND][SIZE];
int idx=0;
void BFS(int x){
	for(int i=1;i<=n;++i) visited[i]=0;
	dist[idx][x]=0;
	q.push(x);
	visited[x]=1;
	while(!q.empty()){
		int vert=q.front();
		q.pop();
		for(int v:graph[vert]){
			if(!visited[v]){
				q.push(v);
				visited[v]=1;
				dist[idx][v]=dist[idx][vert]+1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>p;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	srand(time(NULL));
	for(int i=0;i<RND;++i){
		BFS(rand()%n+1);
		++idx;
	}
	while(p--){
		cin>>a>>b;
		int ans=n;
		for(int i=0;i<RND;++i){
			ans=min(ans,dist[i][a]+dist[i][b]);
		}
		cout<<ans<<"\n";
	}
}
