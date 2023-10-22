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
	int r,c; cin>>r>>c;
	bool is_tree=0;
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			char x; cin>>x;
			if(x=='^') is_tree=1;
		}
	}
	if((r==1||c==1)&&is_tree) cout<<"Impossible\n";
	else{
		cout<<"Possible\n";
		for(int i=1;i<=r;++i){
			for(int j=1;j<=c;++j) cout<<(is_tree?'^':'.');
			cout<<"\n";
		}
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
