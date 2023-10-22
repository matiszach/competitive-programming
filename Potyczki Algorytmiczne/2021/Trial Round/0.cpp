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
const int NAX=3e5+7;
string s;
int n;
ll cnt[NAX*2];
ll ans=1;
void check_pair(char fi,char se){
	for(int i=0;i<=n*2+5;++i) cnt[i]=0;
	int a=0,b=0;
	vector<int> last;
	for(int i=0;i<n;++i){
		if(s[i]!=fi&&s[i]!=se){
			for(int v:last) cnt[v]=0;
			last.clear();
			a=0; b=0;
			continue;
		}
		if(s[i]==fi) ++a;
		if(s[i]==se) ++b;
		ans+=cnt[a-b+n]+(a-b==0&&(a>0&&b>0)?1LL:0LL);
		++cnt[a-b+n];
		last.pb(a-b+n);
	}
}
map<pii,ll> m;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>s;
	n=s.size();
	//single
	ll curr=1;
	for(int i=1;i<n;++i){
		if(s[i]!=s[i-1]) curr=0;
		ans+=++curr;
	}
	//pair
	check_pair('a','b');
	check_pair('a','c');
	check_pair('b','c');
	//triple
	int a=0,b=0,c=0;
	for(int i=0;i<n;++i){
		if(s[i]=='a') ++a;
		if(s[i]=='b') ++b;
		if(s[i]=='c') ++c;
		ans+=m[{a-b,a-c}]+(a==b&&b==c&&(a>0&&b>0&&c>0)?1LL:0LL);
		++m[{a-b,a-c}];
	}
	cout<<ans<<"\n";
}
