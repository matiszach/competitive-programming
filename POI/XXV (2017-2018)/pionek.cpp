//Task statement: szkopul.edu.pl/problemset/problem/NZSCUwz2ACePsBKuVCIVzrRt/site/
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
typedef long double dd;
typedef complex<dd> point;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=2e5+7;
const dd diff=1e-9;
pii arr[MAXN];
pair<point,dd> pnt[MAXN];
bool cmp(pair<point,dd> &A,pair<point,dd> &B){
	return A.second<B.second;
}
point cond[MAXN*2];
dd ang[MAXN*2];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i].first>>arr[i].second;
	int N=0;
	for(int i=1;i<=n;++i){
		if(arr[i].first==0&&arr[i].second==0) continue;
		pnt[++N]={point(arr[i].first,arr[i].second),arg(point(arr[i].first,arr[i].second))};
	}
	sort(pnt+1,pnt+N+1,cmp);
	int idx=0;
	point tmp=point(0,0);
	for(int i=1;i<=N;++i){
		tmp+=pnt[i].first;
		if(abs(pnt[i].second-pnt[i+1].second)>=diff){
			cond[++idx]=tmp;
			ang[idx]=pnt[i].second;
			tmp=point(0,0);
		}
	}
	for(int i=1;i<=idx;++i) cond[i+idx]=cond[i];
	for(int i=1;i<=idx;++i) ang[i+idx]=ang[i]+(dd)2*M_PI;
	int j=0;
	pll res={0,0};
	pll total={0,0};
	for(int i=1;i<=idx;++i){
		total.first+=(ll)cond[i].real();
		total.second+=(ll)cond[i].imag();
	}
	ll ans=0;
	for(int i=1;i<=idx;++i){
		while(ang[j+1]-ang[i]<M_PI&&j<idx*2){
			++j;
			res.first+=(ll)cond[j].real();
			res.second+=(ll)cond[j].imag();
		}
		ans=max(ans,res.first*res.first+res.second*res.second);
		ans=max(ans,(total.first-res.first)*(total.first-res.first)
				+(total.second-res.second)*(total.second-res.second));
		if(j<idx*2&&j+1-i<idx){
			res.first+=(ll)cond[j+1].real();
			res.second+=(ll)cond[j+1].imag();
			ans=max(ans,res.first*res.first+res.second*res.second);
			ans=max(ans,(total.first-res.first)*(total.first-res.first)
					+(total.second-res.second)*(total.second-res.second));
			res.first-=(ll)cond[j+1].real();
			res.second-=(ll)cond[j+1].imag();
		}
		res.first-=(ll)cond[i].real();
		res.second-=(ll)cond[i].imag();
	}
	cout<<ans<<"\n";
}
