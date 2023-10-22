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
	string s; cin>>s;
	vector<char> last;
	for(char &c:s){
		if(c=='('||c=='['||c=='{'||c=='<') last.pb(c);
		else{
			if(c==')') c='(';
			if(c==']') c='[';
			if(c=='}') c='{';
			if(c=='>') c='<';
			if(last.empty()||last.back()!=c){
				cout<<"Nie\n";
				return 0;
			}
			last.pop_back();
		}
	}
	if(last.empty()) cout<<"Tak\n";
	else cout<<"Nie\n";
}
