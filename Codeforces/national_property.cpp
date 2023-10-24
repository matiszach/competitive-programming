// Task statement: https://codeforces.com/problemset/problem/875/C
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
const int MAXN=1e5+7;
vector<int> words[MAXN];
vector<int> sat[MAXN];
map<pii,bool> conns;
void make_edge(int A,int B){
	if(conns.find({A,B})!=conns.end()) return;
	conns[{A,B}]=1;
	sat[A].pb(B);
}
int solution[MAXN];
bitset<MAXN> visited;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m,x,a; cin>>m>>n;
	for(int i=1;i<=m;++i){
		cin>>x;
		for(int j=1;j<=x;++j){
			cin>>a;
			words[i].pb(a);
		}
	}
	for(int i=m;i>=2;--i){
		int j=0;
		while(1){
			if(j>=(int)words[i].size()||j>=(int)words[i-1].size()) break;
			if(words[i][j]!=words[i-1][j]) break;
			++j;
		}
		if(j>=(int)words[i].size()||j>=(int)words[i-1].size()){
			if(words[i].size()<words[i-1].size()){
				cout<<"No\n";
				return 0;
			}
		}else{
			if(words[i][j]<words[i-1][j]){
				solution[words[i-1][j]]=1;
			}else{
				make_edge(words[i][j],words[i-1][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]&&solution[i]==1){
			queue<int> Q;
			Q.push(i);
			visited[i]=1;
			while(!Q.empty()){
				int vert=Q.front(); Q.pop();
				for(int v:sat[vert]){
					if(!visited[v]){
						visited[v]=1;
						if(solution[vert]==1) solution[v]=1;
						Q.push(v);
					}
				}
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<(int)words[i].size();++j){
			if(solution[words[i][j]]==1) words[i][j]-=2*n;
		}
	}
	for(int i=m;i>=2;--i){
		int j=0;
		while(1){
			if(j>=(int)words[i].size()||j>=(int)words[i-1].size()) break;
			if(words[i][j]!=words[i-1][j]) break;
			++j;
		}
		if(j>=(int)words[i].size()||j>=(int)words[i-1].size()) continue;
		if(words[i][j]<words[i-1][j]){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	int ans=0;
	for(int i=1;i<=n;++i) if(solution[i]==1) ++ans;
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i) if(solution[i]==1) cout<<i<<" ";
	cout<<"\n";
}
