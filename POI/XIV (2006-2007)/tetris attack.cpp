//Task statement: szkopul.edu.pl/problemset/problem/noPY-IL0vsAi2TiXF-v2f5Br/site/
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
const int MAXN=5e4+7;
bool was[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<int> s;
	vector<int> res;
	for(int i=1;i<=n*2;++i){
		int x; cin>>x;
		s.pb(x);
		int idx=s.size()-2;
		if(was[x]){
			while(s[idx]!=x) --idx;
			for(int j=idx;j<(int)s.size()-2;++j){
				res.pb(j+1);
				swap(s[j],s[j+1]);
			}
			s.pop_back(); s.pop_back();
		}else was[x]=1;
	}
	cout<<(int)res.size()<<"\n";
	for(int v:res) cout<<v<<"\n";
}
