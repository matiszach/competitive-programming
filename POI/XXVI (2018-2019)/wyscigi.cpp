//Task statement: szkopul.edu.pl/problemset/problem/S8phA644ooC9arh6FhXzvbiH/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nTree=524288,SIZE=5e5+7;
const ll INF=1e18+7;
ll T[nTree*2],lazy[nTree*2];
ll Tp[nTree*2];
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
	int mid=(start+end)/2;
	update(v*2,start,mid,l,r,val);
	update(v*2+1,mid+1,end,l,r,val);
	T[v]=max(T[v*2],T[v*2+1]);
}
ll query(int v,int start,int end,int l,int r){
	if(start>r||end<l||start>end) return -INF;
	if(lazy[v]!=0){
		T[v]+=lazy[v];
		if(start!=end){
			lazy[v*2]+=lazy[v];
			lazy[v*2+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(start>=l&&end<=r) return T[v];
	int mid=(start+end)/2;
	ll q1=query(v*2,start,mid,l,r);
	ll q2=query(v*2+1,mid+1,end,l,r);
	return max(q1,q2);
}
void update2(int l,int r,int val){
	l+=nTree;
	r+=nTree;
	if(l==r){
		Tp[l]+=val;
		return;
	}
	Tp[l]+=val;
	Tp[r]+=val;
	while(l<r-1){
		if(l%2==0) Tp[l+1]+=val;
		if(r%2==1) Tp[r-1]+=val;
		l/=2;
		r/=2;
	}
}
ll query2(int pos){
	pos+=nTree;
	ll val=0;
	while(pos>0){
		val+=Tp[pos];
		pos/=2;
	}
	return val;
}
int n,q;
int arr[SIZE];
char c;
ll x,y;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>arr[i];
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;++i){
		update(1,0,nTree-1,i,i,arr[i]+n+1-i);
		update2(i,i,arr[i]);
	}
	update2(n+1,n+1,INF);
	update2(0,0,-INF);
	while(q--){
		cin>>c;
		if(c=='B'){
			cin>>x>>y;
			if(query2(n)<x) continue;
			int l=1,r=n,mid=0;
			while(l<=r){
				mid=(l+r)/2;
				ll v=query2(mid),v2=query2(mid-1);
				if(v>=x&&v2<x) break;
				else if(v>=x) r=mid-1;
				else l=mid+1;
			}
			update(1,0,nTree-1,mid,n,y);
			update2(mid,n,y);
		}else if(c=='K'){
			cin>>x>>y;
			if(query2(1)>x) continue;
			int l=1,r=n,mid=0;
			while(l<=r){
				mid=(l+r)/2;
				ll v=query2(mid),v2=query2(mid+1);
				if(v<=x&&v2>x) break;
				else if(v<=x) l=mid+1;
				else r=mid-1;
			}
			update(1,0,nTree-1,1,mid,-y);
			update2(1,mid,-y);
		}else{
			ll M=query(1,0,nTree-1,1,n);
			M-=(ll)n;
			int l=1,r=n,mid=0;
			while(l<=r){
				mid=(l+r)/2;
				ll v=query2(mid),v2=query2(mid-1);
				if(v>=M&&v2<M) break;
				else if(v>=M) r=mid-1;
				else l=mid+1;
			}
			cout<<n-mid+1<<"\n";
		}
	}
}
