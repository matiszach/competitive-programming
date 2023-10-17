//Task statement: szkopul.edu.pl/problemset/problem/SlqBmJqSmy7cVbTMEIVt3kyp/site/
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
const int MAXN=1e3+7;
vector<int> G[MAXN];
int arr[MAXN*100],org[MAXN*100];
vector<int> last_pos[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,k,m; cin>>n>>k>>m;
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) cin>>org[i];
	for(int i=1;i<=k;++i) last_pos[i].pb(n+1);
	for(int i=n;i>=1;--i) last_pos[arr[i]].pb(i);
	for(int i=1;i<=n;++i){
		int nxt=last_pos[org[i]].back();
		if(nxt>n){
			cout<<"NIE\n";
			return 0;
		}
		last_pos[org[i]].pop_back();
		for(int v:G[org[i]]){
			if(last_pos[v].back()<nxt){
				cout<<"NIE\n";
				return 0;
			}
		}
	}
	cout<<"TAK\n";
}
