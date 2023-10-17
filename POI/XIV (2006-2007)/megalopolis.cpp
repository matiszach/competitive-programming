//Task statement: szkopul.edu.pl/problemset/problem/R6kgLB2Xz3fsLFYKA-4P9fzp/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=3e5+5,nTree=262144;
int T[nTree*2];
int n,m,a,b;
vector<int> graph[SIZE];
int query(int x){
	x+=nTree;
	int curr_sum=0;
	while(x>0){
		curr_sum+=T[x];
		x/=2;
	}
	return curr_sum;
}
void update(int x,int y){
	x+=nTree;
	y+=nTree;
	if(x==y){
		++T[x];
		return;
	}
	++T[x];
	++T[y];
	while(x<y-1){
		if(x%2==0) ++T[x+1];
		if(y%2==1) ++T[y-1];
		x/=2;
		y/=2;
	}
}
bitset<SIZE> visited;
int order=0;
pair<int,int> segments[SIZE];
int dict[SIZE];
int depth=0;
int depths[SIZE];
void DFS(int x){
	++order;
	depths[x]=depth;
	++depth;
	segments[x].first=order;
	visited[x]=1;
	for(int v:graph[x]){
		if(!visited[v]) DFS(v);
	}
	--depth;
	segments[x].second=order;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n-1;++i){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1);
	cin>>m;
	for(int i=0;i<n+m-1;++i){
		char c; cin>>c;
		if(c=='W'){
			int x;
			cin>>x;
			cout<<depths[x]-query(segments[x].first)<<"\n";
		}else{
			int x,y;
			cin>>x>>y;
			if(x>y) swap(x,y);
			update(segments[y].first,segments[y].second);
		}
	}
}
