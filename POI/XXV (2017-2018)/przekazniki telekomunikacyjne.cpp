//Task statement: szkopul.edu.pl/problemset/problem/GmAagCBetbskP0qiKlgVd-6A/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int nTree=524288;
typedef long long ll;
ll T[nTree*2];
pair<ll,ll> lazy[nTree*2];
ll calculate(ll start,ll end,ll a,ll b){
	return (2*b+(end-start)*a)*(end-start+1)/2;
}
void update(int v,int start,int end,int l,int r,ll a,ll b){
	int mid=(start+end)/2;
	if(lazy[v].first!=0||lazy[v].second!=0){
		T[v]+=calculate(start,end,lazy[v].first,lazy[v].second);
		if(start!=end){
			lazy[v*2].first+=lazy[v].first;
			lazy[v*2].second+=lazy[v].second;
			lazy[v*2+1].first+=lazy[v].first;
			lazy[v*2+1].second+=lazy[v].second+lazy[v].first*(mid-start+1);
		}
		lazy[v]={0,0};
	}
	if(start>r||end<l||start>end) return;
	if(start>=l&&end<=r){
		b+=(start-l)*a;
		T[v]+=calculate(start,end,a,b);
		if(start!=end){
			lazy[v*2].first+=a;
			lazy[v*2].second+=b;
			lazy[v*2+1].first+=a;
			lazy[v*2+1].second+=b+(mid-start+1)*a;
		}
		return;
	}
	update(v*2,start,mid,l,r,a,b);
	update(v*2+1,mid+1,end,l,r,a,b);
	T[v]=T[v*2]+T[v*2+1];
}
ll query(int v,int start,int end,int l,int r){
	int mid=(start+end)/2;
	if(start>r||end<l||start>end) return 0;
	if(lazy[v].first!=0||lazy[v].second!=0){
		T[v]+=calculate(start,end,lazy[v].first,lazy[v].second);
		if(start!=end){
			lazy[v*2].first+=lazy[v].first;
			lazy[v*2].second+=lazy[v].second;
			lazy[v*2+1].first+=lazy[v].first;
			lazy[v*2+1].second+=lazy[v].second+lazy[v].first*(mid-start+1);
		}
		lazy[v]={0,0};
	}
	if(start>=l&&end<=r) return T[v];
	ll v1=query(v*2,start,mid,l,r);
	ll v2=query(v*2+1,mid+1,end,l,r);
	return v1+v2;
}
int n,m;
char c;
struct pole{
	int l,r,s,a;
};
pole poles[nTree];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>c;
		if(c=='P'){
			int x,s,a;
			cin>>x>>s>>a;
			int l=max(x-s/a,1);
			int r=min(x+s/a,n);
			if(l<=x) update(1,1,nTree-1,l,x,a,s-(x-l)*a);
			if(r>x) update(1,1,nTree-1,x+1,r,-a,s-a);
			poles[x]={l,r,s,a};
		}else if(c=='U'){
			int x;
			cin>>x;
			if(poles[x].l<=x) update(1,1,nTree-1,poles[x].l,x,-poles[x].a,-poles[x].s+(x-poles[x].l)*poles[x].a);
			if(poles[x].r>x) update(1,1,nTree-1,x+1,poles[x].r,poles[x].a,-poles[x].s+poles[x].a);
			poles[x]={0,0,0,0};
		}else{
			int a,b;
			cin>>a>>b;
			cout<<query(1,1,nTree-1,a,b)/(b-a+1)<<"\n";
		}
	}
}
