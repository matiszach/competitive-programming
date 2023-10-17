//Task statement: szkopul.edu.pl/problemset/problem/lR_LabSUC2n7EMmDHpw-wk_b/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=5e5+7;
vector<int> G[MAXN];
int rioting_sons[MAXN];
int parent[MAXN];
bool is_riot[MAXN];
void DFS(int x,int pre){
	parent[x]=pre;
	for(int v:G[x]) if(v!=pre) DFS(v,x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin>>n;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,0);
	int m; cin>>m;
	int ans=1;
	for(int i=1;i<=m;++i){
		int x; cin>>x;
		if(x<0){
			x=-x;
			--rioting_sons[parent[x]];
			ans-=((int)G[x].size()-rioting_sons[x]-(is_riot[parent[x]]?1:0)-1);
			is_riot[x]=0;
		}else{
			++rioting_sons[parent[x]];
			is_riot[x]=1;
			ans+=((int)G[x].size()-rioting_sons[x]-(is_riot[parent[x]]?1:0)-1);
		}
		cout<<ans<<"\n";
	}
}
