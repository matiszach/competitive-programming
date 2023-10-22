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
char res[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	string s; cin>>s;
	int n=s.size();
	int l=0,r=n-1;
	bool last=0;
	for(int i=n-1;i>=0;--i){
		if(!last){
			res[l++]=s[i];
		}else{
			res[r--]=s[i];
		}
		last^=1;
	}
	for(int i=0;i<n;++i) cout<<res[i];
	cout<<"\n";
}
