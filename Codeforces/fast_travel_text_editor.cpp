// Task statement: https://codeforces.com/problemset/problem/1860/E
// *Author Mateusz Kowalski*
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
const int MAXN=5e4+7,A=26;
vector<pii> G[MAXN+A*A];
vector<int> G2[MAXN];
int dist[A*A][MAXN+A*A];
int closest[A*A][MAXN];
vector<int> pos[A*A];
int main()
{
	ios_base::sync_with_stdio(0);
	string s; cin>>s;
	int n=s.size();
	for(int i=1;i<n;++i){
		G[i].pb({i+1,1});
		G[i+1].pb({i,1});
		G2[i].pb(i+1);
		G2[i+1].pb(i);
		int val=(s[i-1]-'a')*A+(s[i]-'a');
		pos[val].pb(i);
		G[i].pb({val+MAXN,1});
		G[val+MAXN].pb({i,0});
	}
	for(int i=0;i<A*A;++i) for(int j=0;j<MAXN+A*A;++j) dist[i][j]=INF;
	for(int i=0;i<A*A;++i){
		deque<pii> Q;
		Q.push_front({MAXN+i,0});
		dist[i][MAXN+i]=0;
		while(!Q.empty()){
			pii vert=Q.front(); Q.pop_front();
			for(pii &v:G[vert.first]){
				if(dist[i][v.first]>vert.second+v.second){
					dist[i][v.first]=vert.second+v.second;
					if(v.second){
						Q.push_back({v.first,vert.second+1});
					}else Q.push_front({v.first,vert.second});
				}
			}
		}
	}
	for(int i=0;i<A*A;++i){
		vector<bool> visited(MAXN+A*A);
		queue<int> Q;
		for(int &v:pos[i]){
			Q.push(v);
			visited[v]=1;
		}
		while(!Q.empty()){
			int vert=Q.front(); Q.pop();
			for(int &v:G2[vert]){
				if(!visited[v]){
					visited[v]=1;
					closest[i][v]=closest[i][vert]+1;
					Q.push(v);
				}
			}
		}
	}
	int q; cin>>q;
	for(int i=1;i<=q;++i){
		int l,r; cin>>l>>r;
		if(l>r) swap(l,r);
		int ans=r-l;
		for(int j=0;j<A*A;++j){
			ans=min(ans,dist[j][r]+closest[j][l]+1);
		}
		cout<<ans<<"\n";
	}
}
