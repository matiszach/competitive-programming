// Task statement: https://codeforces.com/problemset/problem/1499/D
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
const int MAXN=2e7+7;
int cnt[MAXN];
int powers[50];
void solve_case(){
	int c,d,x; cin>>c>>d>>x;
	vector<int> divs;
	int ans=0;
	for(int i=1;i*i<=x;++i){
		if(x%i==0){
			int val=x/i;
			if((val+d)%c==0) ans+=(1<<cnt[(val+d)/c]);
			if(i*i!=x){
				if((i+d)%c==0) ans+=(1<<cnt[(i+d)/c]);
			}
		}
	}
	cout<<ans<<"\n";
}
bool T[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	for(int i=2;i<MAXN;++i){
		if(!cnt[i]){
			for(int j=i;j<MAXN;j+=i) ++cnt[j];
		}
	}
	int t; cin>>t;
	for(int i=1;i<=t;++i) solve_case();
}
