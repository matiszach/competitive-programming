//Task statement: szkopul.edu.pl/problemset/problem/POAyCWzUB990_g4_MA4GF9Jw/site/
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
bool sign[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	int curr=0;
	for(int i=1;i<n;++i){
		char c; cin>>c;
		if(c=='+'){
			if(curr%2==1){
				sign[i]=1;
				++curr;
			}
		}else{
			if(curr%2==0){
				sign[i]=1;
				++curr;
			}
		}
	}
	for(int i=1;i<n;++i){
		if(sign[i]) cout<<"(";
		cout<<"-";
	}
	for(int i=1;i<=curr;++i) cout<<")";
	cout<<"\n";
}
