//Task statement: szkopul.edu.pl/problemset/problem/hbT9J8hl2Xw1zWGJBsXN9aic/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INF=1e18+7;
#define pb push_back
const int SIZE=3e5+7,nTree=(1<<18);
int n;
int arr[SIZE],orders[SIZE];
ll pref[SIZE];
ll T[nTree*2],lazy[nTree*2];
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
	T[v]=min(T[v*2],T[v*2+1]);
}
ll query(int v,int start,int end,int l,int r){
	if(start>r||end<l||start>end) return INF;
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
	ll q1=query(v*2,start,mid,l,r);
	ll q2=query(v*2+1,mid+1,end,l,r);
	return min(q1,q2);
}
pii event[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) cin>>orders[i];
	for(int i=1;i<=n;++i) pref[i]=pref[i-1]+arr[i];
	for(int i=1;i<=n;++i) update(1,0,nTree-1,i,i,pref[i]);
	for(int i=1;i<=n;++i) event[i]={orders[i],i};
	sort(event+1,event+1+n);
	int ans=0;
	vector<int> res;
	for(int i=1;i<=n;++i){
		int pos=event[i].second;
		ll val=event[i].first;
		if(query(1,0,nTree-1,pos,n)>=val){
			update(1,0,nTree-1,pos,n,-val);
			res.pb(pos);
			++ans;
		}
	}
	cout<<ans<<"\n";
	sort(res.begin(),res.end());
	for(int v:res) cout<<v<<" ";
}
