//Task statement: szkopul.edu.pl/problemset/problem/wrTmzO9-dzEbLtsRUCdMV2_W/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+7;
int n,q,a,b;
typedef pair<int,int> pii;
#define pb push_back
pii graph[SIZE];
queue<int> Q;
vector<int> nodes[SIZE];
void DFS(int x){
	if(graph[x].first!=0) DFS(graph[x].first);
	if(graph[x].second!=0) nodes[1].pb(graph[x].second);
}
int order[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		graph[i]={a,b};
	}
	DFS(1);
	Q.push(1);
	int idx=1;
	while(!Q.empty()){
		int vert=Q.front(); Q.pop();
		bool l=0,r=0;
		for(int v:nodes[vert]){
			order[v]=vert;
			if(graph[v].first!=0) l=1;
			if(graph[v].second!=0) r=1;
		}
		if(l){
			++idx;
			for(int v:nodes[vert]) if(graph[v].first!=0) nodes[idx].pb(graph[v].first);
			Q.push(idx);
		}
		if(r){
			++idx;
			for(int v:nodes[vert]) if(graph[v].second!=0) nodes[idx].pb(graph[v].second);
			Q.push(idx);
		}
	}
	cin>>q;
	while(q--){
		cin>>a>>b;
		cout<<(order[a]>=order[b]?"TAK\n":"NIE\n");
	}
}
