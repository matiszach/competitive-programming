//Task statement: szkopul.edu.pl/problemset/problem/jgCcEjQu3kdpM4BmxA6GujfX/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=3e5+7;
int n,a,b;
vector<int> graph[SIZE];
int depth[SIZE];
int ans=0;
void DFS(int x,int prev,int dep){
	depth[x]=dep;
	for(int v:graph[x]){
		if(v!=prev) DFS(v,x,dep+1);
	}
}
int res[SIZE];
int find(int x,int prev,int val){
	res[x]=0;
	for(int v:graph[x]){
		if(v!=prev) res[x]+=find(v,x,val)+1;
	}
	res[x]=max(res[x]-val,0);
	return res[x];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1,1,0);
	int l=1,r=n,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		find(1,1,mid);
		int v1=res[1];
		find(1,1,mid-1);
		int v2=res[1];
		if(v1==0&&v2>0) break;
		if(v1>0) l=mid+1;
		else if(v1==0) r=mid-1;
	}
	find(1,1,0);
	if(res[1]==0) mid=0;
	cout<<mid<<"\n";
}
