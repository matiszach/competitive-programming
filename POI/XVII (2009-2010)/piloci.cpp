//Task statement: szkopul.edu.pl/problemset/problem/4ZH1h7Wr18Yb7B0L7ym_Km0L/site/
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
const int MAXN=3e6+7;
int arr[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int k,n; cin>>k>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	deque<pii> mini,maxi;
	int j=0;
	int ans=1;
	for(int i=1;i<=n;++i){
		while(j<n&&(mini.empty()||maxi.empty()||(arr[j+1]-mini.front().first<=k&&maxi.front().first-arr[j+1]<=k))){
			++j;
			while(!mini.empty()&&mini.back().first>=arr[j]) mini.pop_back();
			mini.push_back({arr[j],j});
			while(!maxi.empty()&&maxi.back().first<=arr[j]) maxi.pop_back();
			maxi.push_back({arr[j],j});
		}
		ans=max(ans,j-i+1);
		if(!mini.empty()&&mini.front().second==i) mini.pop_front();
		if(!maxi.empty()&&maxi.front().second==i) maxi.pop_front();
	}
	cout<<ans<<"\n";
}
