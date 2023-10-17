//Task statement: szkopul.edu.pl/problemset/problem/LRxIzCCc5Nn4UvWV514zro4a/site/
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
int arr[MAXN];
ll T[nTree<<1],lazy[nTree<<1];
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
	T[v]=max(T[v*2],T[v*2+1]);
}
void prop(int v){
	T[v]+=lazy[v];
	if(v<nTree){
		lazy[v*2]+=lazy[v];
		lazy[v*2+1]+=lazy[v];
	}
	lazy[v]=0;
}
int query(int v,int start,int end){
	if(start==end) return v-nTree;
	prop(v);
	prop(v*2);
	prop(v*2+1);
	int mid=(start+end)>>1;
	if(T[v*2]>0) return query(v*2,start,mid);
	else return query(v*2+1,mid+1,end);
}
void build(int v){
	if(v>=nTree) return;
	build(v*2);
	build(v*2+1);
	T[v]=max(T[v*2],T[v*2+1]);
}
ll suf[MAXN];
ll s[MAXN];
ll ans[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=n;i>=1;--i) suf[i]=suf[i+1]+arr[i];
	for(int i=1;i<=n;++i) s[i]=arr[i]-suf[i+1];
	for(int i=1;i<=n;++i) T[i+nTree]=s[i];
	for(int i=n+1;i<nTree;++i) T[i+nTree]=-INFLL;
	T[nTree]=-INFLL;
	build(1);
	ll res=0;
	for(int i=1;i<=n;++i) res+=arr[i];
	for(int i=n;i>=1;--i){
		ans[i]=res;
		int idx=query(1,0,nTree-1);
		res-=arr[idx];
		update(1,0,nTree-1,idx,idx,-INFLL);
		update(1,0,nTree-1,1,idx-1,arr[idx]);
	}
	for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
	cout<<"\n";
}
