//Task statement: szkopul.edu.pl/problemset/problem/OuZMUi4nBcPXMIOr10Z-JGsG/site/
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
bool used[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	vector<int> res;
	for(int i=1;i<=n;++i){
		if(!used[i]){
			res.pb(i);
			used[i]=1;
			for(int &v:G[i]){
				used[v]=1;
				for(int &w:G[v]) used[w]=1;
			}
		}
	}
	cout<<(int)res.size()<<"\n";
	for(int &v:res) cout<<v<<" ";
	cout<<"\n";
}
