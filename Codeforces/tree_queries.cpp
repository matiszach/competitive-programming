// Task statement: https://codeforces.com/problemset/problem/1254/D
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
const int MAXN=2e5+7,nTree=(1<<18),SQR=150;
const int MOD=998244353;
int n,q;
ll F[nTree<<1];
int V;
void fen_update(int l,int r,int val){
	if(l>r) return;
	V=r;
	for(;V>0;V-=(V&(-V))) F[V]+=val;
	if(l==1) return;
	V=l-1;
	for(;V>0;V-=(V&(-V))) F[V]-=val;
}
ll R;
int fen_query(int v){
	R=0;
	for(;v<=n;v+=(v&(-v))) R+=F[v];
	return R%MOD;
}
vector<int> G[MAXN];
int preorder[MAXN],postorder[MAXN],depth[MAXN],amount[MAXN];
int parent[MAXN];
int preorder_to_vert[MAXN];
void DFS(int x,int pre){
	parent[x]=pre;
	depth[x]=depth[pre]+1;
	for(int v:G[x]) if(v!=pre) DFS(v,x);
	amount[x]=1;
	for(int v:G[x]) if(v!=pre) amount[x]+=amount[v];
}
vector<int> T[nTree<<1];
vector<int> verts;
void query(int l,int r){
	verts.clear();
	l+=nTree; r+=nTree;
	if(l>r) return;
	for(int v:T[l]) verts.pb(v);
	if(l<r) for(int v:T[r]) verts.pb(v);
	while(l<r-1){
		if(l%2==0) for(int v:T[l+1]) verts.pb(v);
		if(r%2==1) for(int v:T[r-1]) verts.pb(v);
		l>>=1; r>>=1;
	}
}
void init(int v){
	if(v>=nTree){
		if((int)G[preorder_to_vert[v-nTree]].size()>SQR) T[v].pb(preorder_to_vert[v-nTree]);
		return;
	}
	init(v*2);
	init(v*2+1);
	for(int w:T[v*2]) T[v].pb(w);
	for(int w:T[v*2+1]) T[v].pb(w);
}
int idx;
int path_end[MAXN];
void HLD_init(int x,int pre){
	preorder[x]=++idx;
	preorder_to_vert[idx]=x;
	int heavy=0;
	for(int v:G[x]){
		if(v!=pre){
			if(amount[v]>amount[heavy]) heavy=v;
		}
	}
	if(heavy!=0){
		path_end[heavy]=path_end[x];
		HLD_init(heavy,x);
	}
	for(int v:G[x]){
		if(v!=pre&&v!=heavy){
			path_end[v]=v;
			HLD_init(v,x);
		}
	}
	postorder[x]=idx;
}
int fat_val[MAXN];
int get_path(int a,int b){
	ll res_p=0;
	int last_end[2]={0,0};
	bool curr=0;
	while(path_end[a]!=path_end[b]){
		if(depth[path_end[a]]<depth[path_end[b]]){
			curr^=1;
			swap(a,b);
		}
		query(preorder[path_end[a]],preorder[a]);
		for(int v:verts){
			int bottom=preorder[v]+1;
			if(bottom>preorder[a]){
				if(last_end[curr]!=0) bottom=preorder[last_end[curr]];
				else continue;
			}
			bottom=preorder_to_vert[bottom];
			res_p+=(ll)fat_val[v]*(n-amount[bottom]);
		}
		last_end[curr]=path_end[a];
		a=parent[path_end[a]];
	}
	if(preorder[a]>preorder[b]){
		swap(a,b);
	}
	query(preorder[a],preorder[b]);
	for(int v:verts){
		int bottom=preorder[v]+1;
		if(bottom>preorder[b]){
			if(last_end[curr]!=0) bottom=preorder[last_end[curr]];
			else continue;
		}
		bottom=preorder_to_vert[bottom];
		res_p+=(ll)fat_val[v]*(n-amount[bottom]);
	}
	return res_p%MOD;
}
ll mod_pow(ll x){
	ll tmp=x%MOD,res=1;
	for(int i=0;i<31;++i){
		if((1<<i)&(MOD-2)) (res*=tmp)%=MOD;
		(tmp*=tmp)%=MOD;
	}
	return res%MOD;
}
ll ext[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	DFS(1,1);
	HLD_init(1,1);
	init(1);
	int inv=mod_pow(n);
	int val=0,tmp=0;
	for(int i=1;i<=q;++i){
		int type; cin>>type;
		if(type==1){
			int a,b; cin>>a>>b;
			(ext[a]+=((ll)b*n)%MOD)%=MOD;
			if((int)G[a].size()>SQR){
				(fat_val[a]+=b)%=MOD;
			}else{
				for(int v:G[a]){
					if(v!=parent[a]){
						val=(ll)b*(n-amount[v])%MOD;
						tmp=postorder[v];
						for(;tmp>0;tmp-=(tmp&(-tmp))) F[tmp]+=val;
						tmp=preorder[v]-1;
						for(;tmp>0;tmp-=(tmp&(-tmp))) F[tmp]-=val;
					}
				}
			}
			fen_update(1,preorder[a]-1,(((ll)b*amount[a]))%MOD);
			fen_update(postorder[a]+1,n,(((ll)b*amount[a]))%MOD);
		}else{
			int a; cin>>a;
			ll res=get_path(1,a);
			res+=ext[a];
			tmp=preorder[a];
			for(;tmp<=n;tmp+=(tmp&(-tmp))) res+=F[tmp];
			res%=MOD;
			res=(res*inv)%MOD;
			cout<<res<<"\n";
		}
	}
}
