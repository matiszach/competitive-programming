//Task statement: szkopul.edu.pl/problemset/problem/SVA2DjOz9BEg9nlwm40NUNcK/site/
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
map<int,int> was;
vector<int> nums[9];
int main()
{
	ios_base::sync_with_stdio(0);
	int k,n; cin>>k>>n;
	int curr=0;
	for(int i=1;i<=8;++i){
		curr*=10;
		curr+=k;
		nums[i].pb(curr);
		was[curr]=i;
	}
	for(int i=2;i<=8;++i){
		for(int j=1;j<=i-1;++j){
			for(int &x:nums[j]){
				for(int &y:nums[i-j]){
					if(was.find(x+y)==was.end()){
						nums[i].pb(x+y);
						was[x+y]=i;
					}
					if(was.find(x-y)==was.end()&&x>y){
						nums[i].pb(x-y);
						was[x-y]=i;
					}
					if((ll)x*y<INF&&was.find(x*y)==was.end()){
						nums[i].pb(x*y);
						was[x*y]=i;
					}
					if(x%y==0&&was.find(x/y)==was.end()){
						nums[i].pb(x/y);
						was[x/y]=i;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		int x; cin>>x;
		cout<<(was.find(x)==was.end()?"NIE":to_string(was[x]))<<"\n";
	}
}

