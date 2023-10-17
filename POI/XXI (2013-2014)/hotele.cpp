//Task statement: szkopul.edu.pl/problemset/problem/3_L6ZY7G-HX2CT7tYvkio8wH/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=5e3+7;
int n,a,b;
vector<int> graph[SIZE];
vector<vector<int> > depth;
ll val[SIZE],res[SIZE];
ll ans=0;
int curr=0;
vector<int> temp;
void DFS(int x,int prev,int dep){
	if(dep>(int)temp.size()-1) temp.push_back(1);
	else ++temp[dep];
	for(int v:graph[x]){
		if(v!=prev) DFS(v,x,dep+1);
	}
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
	for(int i=1;i<=n;++i){
		depth.clear();
		for(int j=0;j<=n;++j) val[j]=0;
		for(int v:graph[i]){
			DFS(v,i,0);
			depth.push_back(temp);
			temp.clear();
		}
		int amount=graph[i].size();
		for(int j=0;j<amount;++j){
			for(int k=0;k<depth[j].size();++k){
				val[k]+=depth[j][k];
			}
		}
		for(int j=0;j<=n;++j) res[i]+=val[j]*(val[j]-1)*(val[j]-2)/6;
		for(int j=0;j<amount;++j){
			for(int k=0;k<depth[j].size();++k){
				ll x=val[k]-depth[j][k],y=depth[j][k];
				res[i]-=y*(y-1)*(y-2)/6+y*(y-1)*x/2;
			}
		}
	}
	for(int i=1;i<=n;++i) ans+=res[i];
	cout<<ans<<"\n";
}
