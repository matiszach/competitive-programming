//Task statement: szkopul.edu.pl/problemset/problem/fYzoFHo_2JRG4FQSt5UPRpn5/site/
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
const int MAXN=1e6+7,MOD=1e9+7;
int res[MAXN];
vector<pii> G[MAXN];
bool visited[MAXN];
vector<int> marked;
void DFS(int x){
	marked.pb(x);
	visited[x]=1;
	for(pii &v:G[x]) if(!visited[v.first]) DFS(v.first);
}
int in[MAXN];
void force(int x){
	visited[x]=1;
	for(pii &v:G[x]){
		if(in[v.first]>1){
			if(v.first==x) res[v.second]=x;
			if(!visited[v.first]){
				res[v.second]=x;
				force(v.first);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i){
		char c; cin>>c;
		if(c=='T'){
			int a; cin>>a;
			G[a].pb({a,i});
			G[a].pb({a,i});
			++in[a]; ++in[a];
		}else{
			int a,b; cin>>a>>b;
			G[a].pb({b,i});
			G[b].pb({a,i});
			++in[a]; ++in[b];
		}
	}
	ll ans=1;
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			DFS(i);
			int cnt=0;
			for(int &v:marked){
				cnt+=(int)G[v].size();
			}
			cnt>>=1;
			if(cnt>(int)marked.size()) ans*=0;
			else{
				queue<int> Q;
				for(int &v:marked) if(in[v]==1) Q.push(v);
				while(!Q.empty()){
					int vert=Q.front(); Q.pop();
					for(pii &v:G[vert]){
						if(in[v.first]>1){
							res[v.second]=vert;
							--in[v.first];
							--in[vert];
							if(in[v.first]==1){
								Q.push(v.first);
							}
						}
					}
				}
				int rem=0;
				for(int &v:marked) if(in[v]>1){visited[v]=0; ++rem;}
				for(int &v:marked) if(in[v]>1){force(v); break;}
				if(rem>1) (ans*=2)%=MOD;
			}
			marked.clear();
		}
	}
	if(ans==1){
		cout<<"TAK\n";
		for(int i=1;i<=n;++i) cout<<res[i]<<"\n";
	}else{
		cout<<"NIE\n";
		cout<<ans<<"\n";
	}
}
