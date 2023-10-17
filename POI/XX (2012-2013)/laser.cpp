//Task statement: szkopul.edu.pl/problemset/problem/50NNSYZSygWhYhYv77iwZYP7/site/
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
pair<int,pii> points[MAXN*2];
bool cmp(pair<int,pii> &A,pair<int,pii> &B){
	return (ll)A.second.first*B.second.second<(ll)A.second.second*B.second.first;
}
int beg[MAXN],nd[MAXN];
vector<int> starting[MAXN*4],ending[MAXN*4];
int dp[2][MAXN*4];
int targets[MAXN*4],left_most[MAXN*4];
int main()
{
	ios_base::sync_with_stdio(0);
	int k,n; cin>>k>>n;
	for(int i=1;i<=n;++i){
		pii A,B; cin>>A.second>>A.first>>B.second>>B.first;
		points[i*2-1]={i,A};
		points[i*2]={i,B};
	}
	sort(points+1,points+2*n+1,cmp);
	points[0]={0,{0,1}};
	int curr=0;
	for(int i=1;i<=n*2;++i){
		if(points[i-1].second.first*points[i].second.second<points[i].second.first*points[i-1].second.second) curr+=2;
		if(beg[points[i].first]!=0) nd[points[i].first]=curr;
		else beg[points[i].first]=curr;
	}
	for(int i=1;i<=n;++i){
		starting[beg[i]].pb(i);
		ending[nd[i]+1].pb(i);
	}
	int cnt=0;
	multiset<int> opened;
	for(int i=1;i<=curr+1;++i){
		for(int v:starting[i]) opened.insert(beg[v]);
		for(int v:ending[i]) opened.erase(opened.lower_bound(beg[v]));
		cnt+=(int)starting[i].size();
		cnt-=(int)ending[i].size();
		targets[i]=cnt;
		if((int)opened.size()>0) left_most[i]=(*opened.begin())-1;
		else left_most[i]=i-1;
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=curr;++j){
			dp[i%2][j]=max(dp[i%2][j-1],dp[(i+1)%2][left_most[j]]+targets[j]);
		}
	}
	cout<<dp[k%2][curr]<<"\n";
}
