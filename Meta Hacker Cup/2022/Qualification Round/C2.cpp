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
void solve_case(){
	int n; cin>>n;
	string s; cin>>s;
	int N=(1<<10);
	string k;
	for(int i=0;i<min(10,(int)s.size());++i) k+=s[i];
	vector<int> res;
	for(int mask=0;mask<N;++mask){
		int matches=0;
		for(int i=0;i<(int)k.size();++i){
			if((k[i]=='.'&&((1<<i)&mask))||(k[i]=='-'&&(((1<<i)&mask)==0))) ++matches;
		}
		if(matches<(int)k.size()) res.pb(mask);
	}
	for(int v:res){
		for(int i=0;i<10;++i){
			if((1<<i)&v) cout<<".";
			else cout<<"-";
		}
		cout<<"\n";
		--n;
		if(n==1) return;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<":\n";
		solve_case();
	}
}
