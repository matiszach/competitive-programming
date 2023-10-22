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
	int p; cin>>p;
	vector<int> res;
	int total=0;
	for(int i=2;i<=41;++i){
		while(p%i==0){
			total+=i;
			res.pb(i);
			p/=i;
		}
	}
	if(total>41||p>1){
		cout<<"-1\n";
		return;
	}
	cout<<41-total+res.size()<<" ";
	for(int i=total+1;i<=41;++i) cout<<"1 ";
	for(int &v:res) cout<<v<<" ";
	cout<<"\n";
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
