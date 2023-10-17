//Task statement: szkopul.edu.pl/problemset/problem/uZ5ZaNMU_HTS3nAXN6grrplt/site/
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
int main()
{
	ios_base::sync_with_stdio(0);
	int p,n; cin>>p>>n;
	deque<pii> Q;
	Q.push_back({INF,0});
	int curr=0,diff=0;
	ll ans=0;
	for(int i=1;i<=n;++i){
		int c,d; cin>>c>>d;
		pii val={c,curr};
		while(!Q.empty()&&Q.front().second<curr-p) Q.pop_front();
		ans+=diff*Q.front().first;
		while(!Q.empty()&&Q.back().first>=c) Q.pop_back();
		Q.push_back(val);
		curr+=d;
		diff=d;
	}
	while(!Q.empty()&&Q.front().second<curr-p) Q.pop_front();
	ans+=diff*Q.front().first;
	cout<<ans<<"\n";
}
