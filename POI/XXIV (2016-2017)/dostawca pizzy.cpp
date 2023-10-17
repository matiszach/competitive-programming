//Task statement: szkopul.edu.pl/problemset/problem/q_HBwDECevrQ2iQh1wT6ssx2/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=1e5+7,nTree=(1<<17);
ll T[nTree<<1],lazy[nTree<<1];
int leader[nTree<<1];
void update(int v,int start,int end,int l,int r,ll val){
	if(lazy[v]!=0){
		T[v]+=lazy[v];
		if(start!=end){
			lazy[v*2]+=lazy[v];
			lazy[v*2+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(start>r||end<l||start>end) return;
	if(start>=l&&end<=r){
		T[v]+=val;
		if(start!=end){
			lazy[v*2]+=val;
			lazy[v*2+1]+=val;
		}
		return;
	}
	int mid=(start+end)>>1;
	update(v*2,start,mid,l,r,val);
	update(v*2+1,mid+1,end,l,r,val);
	if(T[v*2]>T[v*2+1]){
		T[v]=T[v*2];
		leader[v]=leader[v*2];
	}else{
		T[v]=T[v*2+1];
		leader[v]=leader[v*2+1];
	}
}
pli query(int v,int start,int end,int l,int r){
	if(lazy[v]!=0){
		T[v]+=lazy[v];
		if(start!=end){
			lazy[v*2]+=lazy[v];
			lazy[v*2+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(start>r||end<l||start>end) return {-INFLL,0};
	if(start>=l&&end<=r) return {T[v],leader[v]};
	int mid=(start+end)>>1;
	pli q1=query(v*2,start,mid,l,r);
	pli q2=query(v*2+1,mid+1,end,l,r);
	return {max(q1.first,q2.first),(q1.first>q2.first?q1.second:q2.second)};

}
vector<pii> G[MAXN];
int parent[MAXN];
int preorder[MAXN],postorder[MAXN];
int idx;
ll depth[MAXN];
void DFS(int x,int pre){
	parent[x]=pre;
	preorder[x]=++idx;
	for(pii v:G[x]){
		if(v.first!=pre){
			depth[v.first]=depth[x]+v.second;
			DFS(v.first,x);
		}
	}
	postorder[x]=idx;
}
bitset<MAXN> used;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,k; cin>>n>>k;
	ll ans=0;
	for(int i=1;i<n;++i){
		int a,b,c; cin>>a>>b>>c;
		G[a].pb({b,c});
		G[b].pb({a,c});
		ans+=c;
	}
	ans<<=1;
	DFS(1,1);
	for(int i=1;i<=n;++i) leader[preorder[i]+nTree]=i;
	for(int i=1;i<=n;++i) update(1,0,nTree-1,preorder[i],preorder[i],depth[i]);
	used[1]=1;
	for(int i=1;i<=k;++i){
		pli val=query(1,0,nTree-1,1,n);
		if(val.first<=0) break;
		ans-=val.first;
		int vert=parent[val.second];
		int pre=val.second;
		update(1,0,nTree-1,preorder[val.second],preorder[val.second],-depth[val.second]*2);
		vector<pair<pii,int>> V;
		while(!used[vert]){
			V.pb({{vert,depth[vert]-depth[parent[vert]]},pre});
			used[vert]=1;
			update(1,0,nTree-1,preorder[vert],preorder[vert],-depth[vert]*2);
			pre=vert;
			vert=parent[vert];
		}
		ll curr=0;
		reverse(V.begin(),V.end());
		for(auto v:V){
			curr+=v.first.second;
			for(pii p:G[v.first.first]){
				if(p.first!=v.second&&p.first!=parent[v.first.first]){
					update(1,0,nTree-1,preorder[p.first],postorder[p.first],-curr*2);
				}
			}
		}
	}
	cout<<ans<<"\n";
}
