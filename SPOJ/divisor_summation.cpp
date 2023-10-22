// Task statement: https://www.spoj.com/problems/DIVSUM/
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
const int MAXN=5e5+7;
ll res[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	for(int i=1;i<MAXN;++i) res[i]=1;
	for(int i=2;i<MAXN;++i){
		if(res[i]>1) continue;
		for(int j=i;j<MAXN;j+=i){
			int x=i,cnt=1;
			ll buf=res[j]*x;
			while(i<=707&&j%(x*i)==0){
				x*=i;
				buf+=res[j]*x;
				++cnt;
			}
			res[j]+=buf;
		}
	}
	int t; cin>>t;
	while(t--){
		int x; cin>>x;
		cout<<res[x]-x<<"\n";
	}
}
