// Task statement: https://www.spoj.com/problems/QTREE3/
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
const int MAXN=1e5+7,nTree=(1<<17);
int T[nTree<<1];
void update(int pos,int val){
	pos+=nTree;
	T[pos]=val;
	pos>>=1;
	while(pos>0){
		T[pos]=min(T[pos*2],T[pos*2+1]);
		pos>>=1;
	}
}
int query(int l,int r){
	l+=nTree; r+=nTree;
	if(l>r) return INF;
	int res=T[l];
	if(l<r) res=min(res,T[r]);
	while(l<r-1){
		if(l%2==0) res=min(res,T[l+1]);
		if(r%2==1) res=min(res,T[r-1]);
		l>>=1; r>>=1;
	}
	return res;
}
vector<int> G[MAXN];
int preorder[MAXN],postorder[MAXN],depth[MAXN],amount[MAXN];
int parent[MAXN];
void DFS(int x,int pre){
	parent[x]=pre;
	depth[x]=depth[pre]+1;
	for(int v:G[x]) if(v!=pre) DFS(v,x);
	amount[x]=1;
	for(int v:G[x]) if(v!=pre) amount[x]+=amount[v];
}
int path_end[MAXN];
int idx;
int preorder_to_vert[MAXN];
void HLD_init(int x,int pre){
	preorder[x]=++idx;
	preorder_to_vert[idx]=x;
	int heavy=0;
	for(int v:G[x]){
		if(v!=pre){
			if(amount[v]>=amount[x]/2){
				path_end[v]=path_end[x];
				heavy=v;
				HLD_init(v,x);
				break;
			}
		}
	}
	for(int v:G[x]){
		if(v!=pre&&v!=heavy){
			path_end[v]=v;
			HLD_init(v,x);
		}
	}
}
int get_path(int a,int b){
	int res=INF;
	while(path_end[a]!=path_end[b]){
		if(depth[path_end[a]]<depth[path_end[b]]) swap(a,b);
		res=min(res,query(preorder[path_end[a]],preorder[a]));
		a=parent[path_end[a]];
	}
	if(preorder[a]>preorder[b]) swap(a,b);
	res=min(res,query(preorder[a],preorder[b]));
	return res;
}
bitset<MAXN> active;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,q; cin>>n>>q;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,1);
	HLD_init(1,1);
	for(int i=0;i<nTree*2;++i) T[i]=INF;
	for(int i=1;i<=q;++i){
		int type,x; cin>>type>>x;
		if(type==1){
			int res=get_path(1,x);
			cout<<(res==INF?-1:preorder_to_vert[res])<<"\n";
		}else{
			if(!active[x]){
				update(preorder[x],preorder[x]);
				active[x]=1;
			}else{
				update(preorder[x],INF);
				active[x]=0;
			}
		}
	}
}
