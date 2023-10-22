// Task statement: https://www.spoj.com/problems/BSHEEP/
// *Author Mateusz Kowalski*
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
struct point{
	int idx;
	ll x,y;
	point operator -(point &A){
		return {-1,x-A.x,y-A.y};
	}
};
ll cross(point &pivot,point &A,point &B){
	point pA=A-pivot,pB=B-pivot;
	return pA.x*pB.y-pA.y*pB.x;
}
bool cmp(point &A,point &B){
	if(A.y<B.y) return 1;
	if(A.y>B.y) return 0;
	return A.x<B.x;
}
vector<point> convex_hull(vector<point> pts){
	int N=pts.size();
	sort(pts.begin(),pts.end(),cmp);
	if(N<3) return pts;
	vector<point> res;
	for(int i=0;i<N;++i){
		while((int)res.size()>1&&cross(res[res.size()-2],res.back(),pts[i])>=0) res.pop_back();
		res.pb(pts[i]);
	}
	int curr_size=res.size();
	for(int i=N-2;i>=0;--i){
		while((int)res.size()>curr_size&&cross(res[res.size()-2],res.back(),pts[i])>=0) res.pop_back();
		res.pb(pts[i]);
	}
	res.pop_back();
	return res;
}
typedef long double ld;
void solve_case(){
	int n; cin>>n;
	vector<point> arr;
	set<pii> sheep;
	for(int i=1;i<=n;++i){
		int x,y; cin>>x>>y;
		if(sheep.find({x,y})==sheep.end()){
			sheep.insert({x,y});
			arr.pb({i,x,y});
		}
	}
	vector<point> res=convex_hull(arr);
	ld ans=0;
	for(int i=0;i<(int)res.size()-1;++i){
		ans+=sqrt((res[i].x-res[i+1].x)*(res[i].x-res[i+1].x)+(res[i].y-res[i+1].y)*(res[i].y-res[i+1].y));
	}
	ans+=sqrt((res[0].x-res.back().x)*(res[0].x-res.back().x)+(res[0].y-res.back().y)*(res[0].y-res.back().y));
	cout<<fixed<<setprecision(2)<<ans<<"\n";
	reverse(res.begin()+1,res.end());
	for(auto &p:res) cout<<p.idx<<" ";
	cout<<"\n\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i) solve_case();
}
