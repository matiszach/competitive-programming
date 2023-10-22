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
	if(s[0]=='0'||s[0]=='1'){
		cout<<"DDDD";
		char pre='D';
		for(char &c:s){
			if(c=='0'){
				cout<<pre;
			}else{
				pre=(pre=='D'?'G':'D');
				cout<<pre;
			}
		}
		cout<<"\n";
	}else{
		char pre='D';
		for(int i=4;i<(int)s.size();++i){
			if(s[i]==pre) cout<<"0";
			else cout<<"1";
			pre=s[i];
		}
		cout<<"\n";
	}
}
