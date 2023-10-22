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
vector<int> curr;
vector<int> res;
int p;
void count(int x,int last,int total){
	if(x!=p) curr.pb(last);
	if(x==1){
		if(41-total+curr.size()<(res.empty()?INF:res.size())){
			res.clear();
			for(int i=total+1;i<=41;++i) res.pb(1);
			for(int &v:curr) res.pb(v);
		}
	}else
	for(int i=min(last,41-total);i>=2;--i){
		if(x%i==0) count(x/i,i,total+i);
	}
	curr.pop_back();
}
void solve_case(){
	cin>>p;
	res.clear();
	curr.clear();
	count(p,41,0);
	if(res.empty()) cout<<"-1\n";
	else{
		cout<<res.size()<<" ";
		for(int &v:res) cout<<v<<" ";
		cout<<"\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve_case();
	}
}
