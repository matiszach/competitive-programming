//Task statement: szkopul.edu.pl/problemset/problem/J5f8YHtUsaMdtOdfx0QoHKe0/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int SIZE=1e6+7;
const ll INF=1e9+1;
int n,g,k,m1,m2,d,a,b;
vector<int> graph[SIZE];
vector<ll> groups;
pair<ll,ll> interval[SIZE];
int deg[SIZE];
bitset<SIZE> visited;
void DFS(int x,int prev,int minimal,int maximal){
	visited[x]=1;
	ll verts=max((ll)graph[x].size()-1,(ll)1);
	if(x!=m1&&x!=m2)
	interval[x]={min(minimal*verts,INF),min(maximal*verts,INF+1)};
	for(int v:graph[x]){
		if(v!=prev) DFS(v,x,min(minimal*verts,INF),min(maximal*verts,INF+1));
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>g>>k;
	for(int i=1;i<=g;++i){
		cin>>d;
		groups.pb(d);
	}
	for(int i=1;i<=n-1;++i){
		cin>>a>>b;
		if(i==1){
			m1=a;
			m2=b;
		}
		graph[a].pb(b);
		graph[b].pb(a);
		++deg[a];
		++deg[b];
	}
	interval[m1]={k,k+1};
	interval[m2]={k,k+1};
	DFS(m1,m2,k,k+1);
	DFS(m2,m1,k,k+1);
	groups.pb(-1);
	groups.pb(INF*2);
	sort(groups.begin(),groups.end());
	ll ans=0;
	for(int i=1;i<=n;++i){
		if(deg[i]==1){
			ll mini=interval[i].first;
			ll maxi=interval[i].second-1;
			ans+=(ll)(((upper_bound(groups.begin(),groups.end(),maxi))-
			(lower_bound(groups.begin(),groups.end(),mini)))*k);
		}
	}
	cout<<ans<<"\n";
}
