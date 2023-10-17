//Task statement: szkopul.edu.pl/problemset/problem/JaAJ5t9WezcTv8GcwGAqAW_6/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+5,INF=1e9+7;
int n,m,a,b;
bool dynamite[SIZE];
int fire[SIZE],depth[SIZE];
vector<int> graph[SIZE];
int t,min_val;
void DFS(int v,int prev){
	for(int vert:graph[v]){
		if(vert!=prev) DFS(vert,v);
	}
	fire[v]=INF;
	depth[v]=-INF;
	if(dynamite[v]) depth[v]=0;
	for(int vert:graph[v]){
		if(vert!=prev){
			if(depth[vert]!=-INF)
				depth[v]=max(depth[v],depth[vert]+1);
			fire[v]=min(fire[v],fire[vert]+1);
		}
	}
	if(depth[v]==-INF) return;
	if(v==1&&depth[v]+fire[v]>t){
		++min_val;
		return;
	}
	if(depth[v]+fire[v]<=t){
		depth[v]=-INF;
		return;
	}
	if(depth[v]==t){
		depth[v]=-INF;
		fire[v]=0;
		++min_val;
		return;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>dynamite[i];
	}
	for(int i=1;i<=n-1;++i){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int l=0,r=n;
	while(l<=r){
		t=(l+r)/2;
		DFS(1,1);
		if(min_val<=m) r=t-1;
		else l=t+1;
		min_val=0;
	}
	cout<<r+1<<"\n";
}
