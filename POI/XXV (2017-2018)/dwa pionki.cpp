//Task statement: szkopul.edu.pl/problemset/problem/vl-wrtcyzmOumStUcnXGiQTm/site/
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
const int MAXN=5e5+7;
typedef complex<double> cd;
cd vects[MAXN];
double ang[MAXN];
pair<double,cd> pts[MAXN*2];
bool cmp(pair<double,cd> &A,pair<double,cd> &B){
	return A.first<B.first;
}
double get_diff(int idx1,int idx2){
	double x=pts[idx1].first,y=pts[idx2].first;
	if(y>=x) return y-x;
	return y-x+2*M_PI;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i){
		int a,b; cin>>a>>b;
		vects[i]=cd(a,b);
	}
	for(int i=1;i<=n;++i) ang[i]=arg(vects[i]);
	for(int i=1;i<=n;++i) pts[i]={ang[i],vects[i]};
	sort(pts+1,pts+n+1,cmp);
	for(int i=1;i<=n;++i) pts[i+n]=pts[i];
	double max_diff=M_PI;
	int j=0;
	ll ans=0;
	ll p1x=0,p1y=0,p2x=0,p2y=0;
	for(int i=1;i<=n;++i){
		p2x+=(int)pts[i].second.real();
		p2y+=(int)pts[i].second.imag();
	}
	for(int i=1;i<=n;++i){
		while(j<i+n-1&&get_diff(i,j+1)<=max_diff){
			++j;
			p1x+=(int)pts[j].second.real();
			p1y+=(int)pts[j].second.imag();
			p2x-=(int)pts[j].second.real();
			p2y-=(int)pts[j].second.imag();
			ll diff_x=max(p1x,p2x)-min(p1x,p2x);
			ll diff_y=max(p1y,p2y)-min(p1y,p2y);
			ans=max(ans,diff_x*diff_x+diff_y*diff_y);
		}
		p1x-=(int)pts[i].second.real();
		p1y-=(int)pts[i].second.imag();
		p2x+=(int)pts[i].second.real();
		p2y+=(int)pts[i].second.imag();
		ll diff_x=max(p1x,p2x)-min(p1x,p2x);
		ll diff_y=max(p1y,p2y)-min(p1y,p2y);
		ans=max(ans,diff_x*diff_x+diff_y*diff_y);
	}
	cout<<ans<<"\n";
}
