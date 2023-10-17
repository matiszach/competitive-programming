//Task statement: szkopul.edu.pl/problemset/problem/xNjwUvwdHQoQTFBrmyG8vD1O/site/
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
const int MAXN=2e5+7,nTree=(1<<19);
int n,k;
map<ll,int> m;
int arr[MAXN];
pii rolls[MAXN];
int start[MAXN],last[MAXN];
vector<int> sat[nTree*2],rsat[nTree*2];
int neg(int a){
	if(a-nTree>MAXN) return a-MAXN;
	else return a+MAXN;
}
void make_edge(int a,int b,bool directed){
	sat[a].pb(b);
	rsat[b].pb(a);
	if(!directed){
		sat[b].pb(a);
		rsat[a].pb(b);
	}
}
void init(int v){
	if(v>=nTree) return;
	make_edge(v,v*2,1);
	make_edge(v,v*2+1,1);
	init(v*2);
	init(v*2+1);
}
void update(int l,int r,int org){
	if(l>r) return;
	l+=nTree; r+=nTree; org+=nTree;
	make_edge(org,l,1);
	if(l<r) make_edge(org,r,1);
	while(l<r-1){
		if(l%2==0) make_edge(org,l+1,1);
		if(r%2==1) make_edge(org,r-1,1);
		l>>=1; r>>=1;
	}
}
bitset<nTree*2> visited;
vector<int> postorder;
void DFS(int x){
	visited[x]=1;
	for(int v:sat[x]){
		if(!visited[v]) DFS(v);
	}
	postorder.pb(x);
}
int colors[nTree*2];
int color;
void rDFS(int x){
	colors[x]=color;
	for(int v:rsat[x]){
		if(colors[v]==0) rDFS(v);
	}
}
bool SAT(){
	for(int i=1;i<nTree*2;++i){
		if(!visited[i]) DFS(i);
	}
	for(int i=postorder.size()-1;i>=0;--i){
		if(colors[postorder[i]]==0){
			++color;
			rDFS(postorder[i]);
		}
	}
	bool ok=1;
	for(int i=1;i<MAXN;++i){
		if(colors[i+nTree]==colors[neg(i+nTree)]) ok=0;
	}
	return ok;
}
void solve_case(){
	postorder.clear();
	m.clear();
	for(int i=1;i<nTree*2;++i){
		sat[i].clear();
		rsat[i].clear();
		visited[i]=0;
		colors[i]=0;
	}
	for(int i=1;i<MAXN;++i){
		arr[i]=0;
		rolls[i]={0,0};
		start[i]=0;
		last[i]=0;
	}
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	int idx=0;
	for(int i=1;i<n;++i){
		if(m.find(arr[i]*MAXN+arr[i+1])==m.end()) m[arr[i]*MAXN+arr[i+1]]=++idx;
		rolls[i]={m[arr[i]*MAXN+arr[i+1]],i};
	}
	sort(rolls+1,rolls+n);
	for(int i=1;i<n;++i){
		if(start[rolls[i].first]==0) start[rolls[i].first]=i;
		last[rolls[i].first]=i;
	}
	init(1);
	map<int,int> m2;
	for(int i=1;i<n;++i){
		m2[rolls[i].second]=i;
	}
	make_edge(neg(m2[1]+nTree),m2[1]+nTree,1);
	make_edge(neg(m2[n-1]+nTree),m2[n-1]+nTree,1);
	for(int i=1;i<n-1;++i){
		make_edge(neg(m2[i]+nTree),m2[i+1]+nTree,1);
		make_edge(neg(m2[i+1]+nTree),m2[i]+nTree,1);
	}
	for(int i=1;i<n;++i){
		int beg=start[rolls[i].first],las=last[rolls[i].first];
		update(beg+MAXN,i-1+MAXN,i);
		update(i+1+MAXN,las+MAXN,i);
	}
	//2SAT here
	cout<<(SAT()?"TAK":"NIE")<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	while(t--){
		solve_case();
	}
}
