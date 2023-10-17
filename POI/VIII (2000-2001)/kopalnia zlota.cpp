//Task statement: szkopul.edu.pl/problemset/problem/TYf8i2qvrGI0l8QHEYJXO5dG/site/
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
const int MAXN=3e4+7,nTree=(1<<16);
pii arr[MAXN];
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
vector<int> pts[MAXN*2];
int main()
{
	ios_base::sync_with_stdio(0);
	int s,w; cin>>s>>w;
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i].first>>arr[i].second;
	for(int i=1;i<=n;++i){
		arr[i].first+=MAXN;
		arr[i].second+=MAXN;
	}
	for(int i=1;i<=n;++i) pts[arr[i].first].pb(arr[i].second);
	int ans=0;
	for(int i=0;i<MAXN*2;++i){
		for(int &v:pts[i]){
			int r=min(v+w,MAXN*2-1);
			update(1,0,nTree-1,v,r,1);
		}
		if(i-s-1>=0){
			for(int &v:pts[i-s-1]){
				int r=min(v+w,MAXN*2-1);
				update(1,0,nTree-1,v,r,-1);
			}
		}
		ans=max(ans,T[1]);
	}
	cout<<ans<<"\n";
}
