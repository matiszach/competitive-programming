// Task statement: https://codeforces.com/problemset/problem/932/F
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
struct line{
	ll a,b;
	ll operator()(ll x){return a*x+b;}
};
struct li_tree{
	struct node{
		node *left_node=nullptr,*right_node=nullptr;
		line l;
		node(line x){l=x;}
	};
	node *root=new node({0,INFLL*5});
	void update(node *v,ll start,ll end,line x){
		if(v->l(start)<x(start)&&v->l(end)<x(end)) return;
		if(v->l(start)>x(start)&&v->l(end)>x(end)){v->l=x; return;}
		ll mid=(start+end)>>1;
		if(v->l(mid)>x(mid)) swap(v->l,x);
		if(start==end) return;
		if(v->l(start)>x(start)){
			if(v->left_node==nullptr){v->left_node=new node(x); return;}
			update(v->left_node,start,mid,x);
		}else{
			if(v->right_node==nullptr){v->right_node=new node(x); return;}
			update(v->right_node,mid+1,end,x);
		}
	}
	ll query(node *v,ll start,ll end,ll x){
		if(v==nullptr) return INFLL*5;
		if(start==end) return v->l(x);
		ll mid=(start+end)>>1;
		if(x<=mid) return min(v->l(x),query(v->left_node,start,mid,x));
		else return min(v->l(x),query(v->right_node,mid+1,end,x));
	}
	void update(line x){update(root,-INF,INF,x);}
	ll query(ll x){return query(root,-INF,INF,x);}
};
const int MAXN=1e5+7;
int n;
int rep[MAXN],s[MAXN];
vector<line> cont[MAXN];
li_tree t[MAXN];
int Find(int x){
	if(rep[x]==x) return x;
	return rep[x]=Find(rep[x]);
}
void Union(int x,int y){
	x=Find(x); y=Find(y);
	if(x==y) return;
	if(s[x]<s[y]) swap(x,y);
	for(line v:cont[y]) cont[x].pb(v);
	for(line v:cont[y]) t[x].update(v);
	cont[y].clear();
	cont[y].shrink_to_fit();
	s[x]+=s[y];
	rep[y]=x;
}
vector<int> G[MAXN];
ll a[MAXN],b[MAXN];
int amount[MAXN],parent[MAXN];
void DFS(int x,int pre){
	parent[x]=pre;
	for(int v:G[x]) if(v!=pre) DFS(v,x);
	for(int v:G[x]) if(v!=pre) amount[x]+=amount[v];
	++amount[x];
}
ll dp[MAXN];
void solve(int x,int pre){
	for(int v:G[x]) if(v!=pre) solve(v,x);
	int heavy=0;
	for(int v:G[x]) if(v!=pre) if(amount[heavy]<amount[v]) heavy=v;
	if(heavy==0){
		cont[x].pb({b[x],0});
		t[x].update({b[x],0});
		return;
	}
	for(int v:G[x]) if(v!=pre) Union(v,heavy);
	dp[x]=t[Find(heavy)].query(a[x]);
	cont[x].pb({b[x],dp[x]});
	Union(heavy,x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	for(int i=1;i<n;++i){
		int v,u; cin>>v>>u;
		G[v].pb(u);
		G[u].pb(v);
	}
	DFS(1,1);
	for(int i=1;i<=n;++i){
		rep[i]=i;
		s[i]=1;
	}
	solve(1,1);
	for(int i=1;i<=n;++i) cout<<dp[i]<<"\n";
}
