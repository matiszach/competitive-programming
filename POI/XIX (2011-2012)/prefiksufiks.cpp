//Task statement: szkopul.edu.pl/problemset/problem/oFbHZH1QYy8yYlyN9AezBIZb/site/
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
const pii MOD={1e9+7,1e9+9};
const pii P={97,101};
pll powers[MAXN];
pll H[MAXN];
bool compare(int s1,int e1,int s2,int e2){
	++s1; ++e1; ++s2; ++e2;
	int diff=(s2-s1);
	pll val1={H[e1].first-H[s1-1].first+MOD.first,H[e1].second-H[s1-1].second+MOD.second};
	if(val1.first>=MOD.first) val1.first-=MOD.first;
	if(val1.second>=MOD.second) val1.second-=MOD.second;
	(val1.first*=powers[diff].first)%=MOD.first;
	(val1.second*=powers[diff].second)%=MOD.second;
	pll val2={H[e2].first-H[s2-1].first+MOD.first,H[e2].second-H[s2-1].second+MOD.second};
	if(val2.first>=MOD.first) val2.first-=MOD.first;
	if(val2.second>=MOD.second) val2.second-=MOD.second;
	return val1==val2;
}
int val[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	string s; cin>>s;
	string _s=s.substr(0,n/2)+"#"+s.substr(n/2+n%2,n-1);
	swap(s,_s);
	n+=((n+1)%2);
	powers[0]={1,1};
	for(int i=1;i<=n;++i){
		powers[i].first=(powers[i-1].first*P.first)%MOD.first;
		powers[i].second=(powers[i-1].second*P.second)%MOD.second;
	}
	for(int i=1;i<=n;++i){
		H[i].first=(H[i-1].first+(s[i-1]+1)*powers[i].first)%MOD.first;
		H[i].second=(H[i-1].second+(s[i-1]+1)*powers[i].second)%MOD.second;
	}
	int j=0;
	for(int i=n/2-1;i>=0;--i){
		j+=2;
		while(i+j-1>=n/2) --j;
		while(j>0&&!compare(i,i+j-1,n-j-i,n-i-1)) --j;
		val[i]=j;
	}
	int ans=0;
	for(int i=0;i<n/2;++i){
		if(compare(0,i,n-i-1,n-1)) ans=max(ans,i+1+val[i+1]);
	}
	cout<<ans<<"\n";
}
