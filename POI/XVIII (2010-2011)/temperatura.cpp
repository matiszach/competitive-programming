//Task statement: szkopul.edu.pl/problemset/problem/6sGsrkO-SrmtogJ7u3RIOj3f/site/
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
int n;
int low[MAXN],high[MAXN];
deque<pii> Q;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>low[i]>>high[i];
	int j=0,ans=1;
	for(int i=1;i<=n;++i){
		while(j<n&&(Q.empty()||Q.back().first<=high[j+1])){
			++j;
			while(!Q.empty()&&Q.front().first<=low[j]) Q.pop_front();
			Q.push_front({low[j],j});
			ans=max(ans,j-i+1);
		}
		if(!Q.empty()&&Q.back().second==i) Q.pop_back();
	}
	cout<<ans<<"\n";
}
