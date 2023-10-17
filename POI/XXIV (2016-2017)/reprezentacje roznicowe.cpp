//Task statement: szkopul.edu.pl/problemset/problem/WLKPphrG7df9acKBOlEMEKY3/site/
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
const int MAXN=207;
ll arr[MAXN];
map<ll,pii> res;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	set<ll> mex;
	for(int i=1;i<MAXN*MAXN;++i) mex.insert(i);
	mex.erase(1);
	arr[1]=1;
	arr[2]=2;
	res[1]={2,1};
	int last=0;
	for(int i=3;i<=MAXN;++i){
		if(i%2==1){
			arr[i]=arr[i-1]*2;
		}else{
			arr[i]=arr[i-1]+*mex.begin();
		}
		for(int j=1;j<i;++j){
			if(mex.find(arr[i]-arr[j])!=mex.end()) mex.erase(arr[i]-arr[j]);
			if(res.find(arr[i]-arr[j])==res.end()) res[arr[i]-arr[j]]={i,j};
		}
		if(arr[i]>2*INF){
			last=i;
			break;
		}
	}
	vector<ll> V;
	for(auto p:res){
		V.pb(p.first);
	}
	int t; cin>>t;
	for(int i=1;i<=t;++i){
		int x; cin>>x;
		if(res.find(x)!=res.end()) cout<<res[x].first<<" "<<res[x].second<<"\n";
		else{
			vector<ll>::iterator it=lower_bound(V.begin(),V.end(),x);
			ll cnt=x-(it-V.begin());
			cout<<last+2*cnt-1<<" "<<last+2*cnt-2<<"\n";
		}
	}
}
