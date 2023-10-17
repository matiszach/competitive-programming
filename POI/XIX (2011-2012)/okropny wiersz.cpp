//Task statement: szkopul.edu.pl/problemset/problem/h9erYqBkPcC8KtSvLhMzhgjw/site/
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
const int MAXN=5e5+7;
const pii MOD={1e9+7,1e9+9};
const pii P={31,53};
pll powers[MAXN];
pll H[MAXN];
bool compare(int pos1,int pos2,int len){
	if(pos1>pos2) swap(pos1,pos2);
	pll val1={H[pos1+len-1].first-H[pos1-1].first,H[pos1+len-1].second-H[pos1-1].second};
	val1.first+=MOD.first; if(val1.first>=MOD.first) val1.first-=MOD.first;
	val1.second+=MOD.second; if(val1.second>=MOD.second) val1.second-=MOD.second;
	(val1.first*=powers[pos2-pos1].first)%=MOD.first;
	(val1.second*=powers[pos2-pos1].second)%=MOD.second;
	pll val2={H[pos2+len-1].first-H[pos2-1].first,H[pos2+len-1].second-H[pos2-1].second};
	val2.first+=MOD.first; if(val2.first>=MOD.first) val2.first-=MOD.first;
	val2.second+=MOD.second; if(val2.second>=MOD.second) val2.second-=MOD.second;
	return val1==val2;
}
int T[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	s="#"+s;
	powers[0]={1,1};
	for(int i=1;i<=n;++i){
		powers[i].first=powers[i-1].first*P.first%MOD.first;
		powers[i].second=powers[i-1].second*P.second%MOD.second;
	}
	for(int i=1;i<=n;++i){
		H[i].first=(H[i-1].first+(s[i]-'a'+1)*powers[i].first)%MOD.first;
		H[i].second=(H[i-1].second+(s[i]-'a'+1)*powers[i].second)%MOD.second;
	}
	for(int i=2;i<=n;++i){
		if(!T[i]){
			for(int j=i;j<=n;j+=i) if(!T[j]) T[j]=i;
		}
	}
	int q; cin>>q;
	for(int i=1;i<=q;++i){
		int a,b; cin>>a>>b;
		int diff=b-a+1;
		int m=diff,l=1;
		while(m!=l){
			int k=T[m/l];
			ll tmp=k;
			while((m/l)%(tmp*k)==0) tmp*=k;
			if(compare(a,a+m/k,m-m/k)) m/=k;
			else l*=k;
		}
		cout<<m<<"\n";
	}
}
