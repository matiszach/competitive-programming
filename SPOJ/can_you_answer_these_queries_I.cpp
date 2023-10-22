// Task statement: https://www.spoj.com/problems/GSS1/
// *Author Mateusz Kowalski*
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
const int SIZE=1e5+7,nTree=(1<<17);
struct node{
	ll total,pref,suf,seg;
}T[nTree*2];
node merge(int l,int r){
	node res={0,0,0,0};
	res.total=T[l].total+T[r].total;
	res.pref=max(T[l].pref,T[l].total+T[r].pref);
	res.suf=max(T[r].suf,T[r].total+T[l].suf);
	res.seg=max(max(T[l].seg,T[r].seg),T[l].suf+T[r].pref);
	return res;
}
void update(int pos,ll val){
	pos+=nTree;
	T[pos].total+=val; T[pos].pref+=val; T[pos].suf+=val; T[pos].seg+=val;
	pos>>=1;
	while(pos>0){
		T[pos]=merge(pos*2,pos*2+1);
		pos>>=1;
	}
}
node query(int v,int start,int end,int l,int r){
	if(start>r||end<l||start>end) return {-INFLL,-INFLL,-INFLL,-INFLL};
	if(start>=l&&end<=r) return T[v];
	int mid=(start+end)>>1;
	node p1=query(v*2,start,mid,l,r);
	node p2=query(v*2+1,mid+1,end,l,r);
	node res={0,0,0,0};
	res.total=max(p1.total+p2.total,-INFLL);
	res.pref=max(p1.pref,p1.total+p2.pref);
	res.suf=max(p2.suf,p2.total+p1.suf);
	res.seg=max(max(p1.seg,p2.seg),p1.suf+p2.pref);
	return res;
}
int n,m,a,b;
int arr[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) update(i,arr[i]);
	cin>>m;
	while(m--){
		cin>>a>>b;
		ll ans=query(1,0,nTree-1,a,b).seg;
		cout<<ans<<"\n";
	}
}
