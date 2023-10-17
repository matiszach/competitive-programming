//Task statement: szkopul.edu.pl/problemset/problem/YmEnXY44jxuLdZPFrhWOfOQi/site/
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
const int MAXN=1e6+7;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,h; cin>>n>>h;
	string s; cin>>s;
	if(h==0){
		cout<<n<<"\n";
		return 0;
	}
	vector<int> pos;
	int ans=0,curr=0;
	for(int i=0;i<n;++i){
		if(s[i]=='(') ++curr;
		else --curr;
		if(curr>h){
			curr-=2;
			++ans;
		}
		if(curr<0){
			curr+=2;
			++ans;
		}
	}
	cout<<ans<<"\n";
}
