//Task statement: szkopul.edu.pl/problemset/problem/-7cqC3RrH4e-Ar7DWy4GKzLv/site/
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
const int MAXN=5e5+7,nTree=(1<<19);
bool D[nTree<<1];
void update(int pos){
	pos+=nTree;
	while(pos>0){
		D[pos]^=1;
		pos>>=1;
	}
}
bool query(int l,int r){
	l+=nTree; r+=nTree;
	if(l>r) return 0;
	bool res=D[l];
	if(l<r) res^=D[r];
	while(l<r-1){
		if(l%2==0) res^=D[l+1];
		if(r%2==1) res^=D[r-1];
		l>>=1; r>>=1;
	}
	return res;
}
pair<pii,int> edges[MAXN];
int T[MAXN],A[MAXN];
int Find(int x){
	if(x==T[x]) return x;
	return T[x]=Find(T[x]);
}
void Union(int a,int b){
	a=Find(a); b=Find(b);
	if(A[b]>A[a]) swap(a,b);
	A[a]+=A[b];
	T[b]=a;
}
bool cmp(pair<pii,int> &X,pair<pii,int> &Y){
	return X.second<Y.second;
}
bool in_mst[MAXN];
vector<pii> Gmst[MAXN];
bool parity[MAXN];
int preorder[MAXN],postorder[MAXN];
int idx;
int amount[MAXN];
int edge_to_vert[MAXN];
void DFS(int x,int pre,int nr){
	preorder[x]=++idx;
	edge_to_vert[nr]=x;
	for(pii p:Gmst[x]){
		if(p.first!=pre){
			DFS(p.first,x,p.second);
		}
	}
	postorder[x]=idx;
}
ll k;
int edge_nr[MAXN];
bool valid=1;
void check_edge(int i){
	if(D[1]||!valid){
		cout<<"-1";
		return;
	}
	if(in_mst[i]){
		cout<<query(preorder[edge_to_vert[i]],postorder[edge_to_vert[i]]);
	}else{
		if(edge_nr[i]==-1) cout<<"0";
		else{
			cout<<(((1LL<<edge_nr[i])&k)>0);
		}
	}
}
vector<pair<pii,int>> V;
void update_k(ll new_k){
	if(new_k-1>=(1LL<<(int)V.size())){
		valid=0;
		return;
	}
	valid=1;
	if(k>0){
		for(int i=0;i<63;++i){
			if((1LL<<i)&k){
				update(preorder[V[i].first.first]);
				update(preorder[V[i].first.second]);
			}
		}
	}
	k=new_k-1;
	for(int i=0;i<63;++i){
		if((1LL<<i)&k){
			update(preorder[V[i].first.first]);
			update(preorder[V[i].first.second]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//*subtask #1*
	int n,m; cin>>n>>m;
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b;
		edges[i]={{a,b},i};
	}
	for(int i=1;i<=n;++i) cin>>parity[i];
	cin>>k;
	sort(edges+1,edges+m+1,cmp);
	for(int i=1;i<=n;++i){
		T[i]=i;
		A[i]=1;
	}
	vector<pair<pii,int>> MST;
	for(int i=1;i<=m;++i){
		if(Find(edges[i].first.first)!=Find(edges[i].first.second)){
			Union(edges[i].first.first,edges[i].first.second);
			in_mst[edges[i].second]=1;
			MST.pb(edges[i]);
			Gmst[edges[i].first.first].pb({edges[i].first.second,edges[i].second});
			Gmst[edges[i].first.second].pb({edges[i].first.first,edges[i].second});
		}
	}
	DFS(1,1,0);
	int q; cin>>q;
	//*subtask #2*
	int left=62;
	for(int i=1;i<=m;++i) edge_nr[i]=-1;
	for(int i=1;i<=m;++i){
		if(!in_mst[i]){
			V.pb(edges[i]);
			edge_nr[i]=62-left;
			--left;
			if(left==0) break;
		}
	}
	for(int i=1;i<=n;++i) if(parity[i]) update(preorder[i]);
	ll tmp=k;
	k=0;
	update_k(tmp);
	for(int i=1;i<=m;++i){
		check_edge(i);
		cout<<" ";
	}
	cout<<"\n";
	for(int i=1;i<=q;++i){
		char c; cin>>c;
		if(c=='K'){
			ll K; cin>>K;
			update_k(K);
		}else if(c=='M'){
			int x; cin>>x;
			update(preorder[x]);
		}else{
			int x; cin>>x;
			check_edge(x);
			cout<<"\n";
		}
	}
}
