//Task statement: szkopul.edu.pl/problemset/problem/pxbqUTPy3IuPDul9FdT2_Sth/site/
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
pii org[MAXN];
pii f[MAXN];
pii A[MAXN],B[MAXN];
struct cmp{
	bool operator()(const pii &a,const pii &b) const{
		return (ll)a.first*b.second<(ll)a.second*b.first;
	}
};
multiset<pii,cmp> a_limit,b_limit;
void compare_functions(int i){
	if(f[i].second==f[i+1].second){
		if(f[i].first>f[i+1].first){
			A[i]={INF,1};
			a_limit.insert(A[i]);
		}else{
			A[i]={1,INF-7};
			a_limit.insert(A[i]);
		}
	}else if(f[i].first>f[i+1].first&&f[i].second<f[i+1].second){
		pii tmp={f[i].first-f[i+1].first,f[i+1].second-f[i].second};
		int g=__gcd(tmp.first,tmp.second);
		tmp.first/=g;
		tmp.second/=g;
		A[i]=tmp;
		a_limit.insert(tmp);
	}else if(f[i].first<f[i+1].first&&f[i].second>f[i+1].second){
		pii tmp={f[i+1].first-f[i].first,f[i].second-f[i+1].second};
		int g=__gcd(tmp.first,tmp.second);
		tmp.first/=g;
		tmp.second/=g;
		B[i]=tmp;
		b_limit.insert(tmp);
	}else if(f[i].first<=f[i+1].first&&f[i].second<=f[i+1].second){
		A[i]={1,INF-7};
		a_limit.insert(A[i]);
	}else{
		A[i]={INF,1};
		a_limit.insert(A[i]);
	}
}
void print_res(){
	if(!a_limit.empty()&&!b_limit.empty()){
		pii a=*(--a_limit.end()),b=*b_limit.begin();
		if((ll)a.first*b.second<=(ll)a.second*b.first) cout<<a.first<<"/"<<a.second<<"\n";
		else cout<<"NIE\n";
	}else if(!b_limit.empty()){
		pii b=*b_limit.begin();
		cout<<b.first<<"/"<<b.second<<"\n";
	}else{
		pii a=*(--a_limit.end());
		if(a.first<INF) cout<<a.first<<"/"<<a.second<<"\n";
		else cout<<"NIE\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>org[i].first>>org[i].second;
	for(int i=1;i<=n;++i){
		int x; cin>>x;
		f[i]=org[x];
	}
	for(int i=1;i<n;++i){
		compare_functions(i);
	}
	if(n==1) cout<<"1/420\n";
	else print_res();
	int q; cin>>q;
	for(int i=1;i<=q;++i){
		int x,y; cin>>x>>y;
		if(x>y) swap(x,y);
		if(x>1){
			if(A[x-1].first==0) b_limit.erase(b_limit.lower_bound(B[x-1]));
			else{
				a_limit.erase(a_limit.lower_bound(A[x-1]));
				A[x-1]={0,1};
			}
		}
		if(x+1<y){
			if(A[x].first==0) b_limit.erase(b_limit.lower_bound(B[x]));
			else{
				a_limit.erase(a_limit.lower_bound(A[x]));
				A[x]={0,1};
			}
		}
		if(y<n){
			if(A[y].first==0) b_limit.erase(b_limit.lower_bound(B[y]));
			else{
				a_limit.erase(a_limit.lower_bound(A[y]));
				A[y]={0,1};
			}
		}
		if(A[y-1].first==0) b_limit.erase(b_limit.lower_bound(B[y-1]));
		else{
			a_limit.erase(a_limit.lower_bound(A[y-1]));
			A[y-1]={0,1};
		}
		swap(f[x],f[y]);
		if(x>1) compare_functions(x-1);
		if(x+1<y) compare_functions(x);
		if(y<n) compare_functions(y);
		compare_functions(y-1);
		print_res();
	}
}
