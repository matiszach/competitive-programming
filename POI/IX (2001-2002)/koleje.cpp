//Task statement: szkopul.edu.pl/problemset/problem/tNexGGGfl9rXi0IJkMjeA-SM/site/
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
const int nTree=(1<<17);
int T[nTree<<1],lazy[nTree<<1];
void update(int v,int start,int end,int l,int r,int val){
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
int query(int v,int start,int end,int l,int r){
	if(start>r||end<l||start>end) return 0;
	if(lazy[v]!=0){
		T[v]+=lazy[v];
		if(start!=end){
			lazy[v*2]+=lazy[v];
			lazy[v*2+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(start>=l&&end<=r) return T[v];
	int mid=(start+end)>>1;
	return max(query(v*2,start,mid,l,r),query(v*2+1,mid+1,end,l,r));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,z; cin>>n>>m>>z;
	for(int i=1;i<=z;++i){
		int p,k,l; cin>>p>>k>>l;
		if(query(1,0,nTree-1,p,k-1)<=m-l){
			update(1,0,nTree-1,p,k-1,l);
			cout<<"T\n";
		}else cout<<"N\n";
	}
}
