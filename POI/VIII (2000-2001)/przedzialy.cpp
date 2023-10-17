//Task statement: szkopul.edu.pl/problemset/problem/w5PRX1QCpJeRUHpwNUpcbF6S/site/
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
	int n; cin>>n;
	set<pii> s;
	for(int i=1;i<=n;++i){
		int a,b; cin>>a>>b;
		auto it=s.lower_bound({a,-1});
		vector<pii> to_del;
		int st=a,nd=b;
		while(it!=s.end()&&(it->first<=b||it->second<=b)){
			st=min(st,it->second);
			nd=max(b,it->first);
			to_del.pb(*it);
			++it;
		}
		for(pii v:to_del) s.erase(v);
		s.insert({nd,st});
	}
	for(pii v:s) cout<<v.second<<" "<<v.first<<"\n";
}
