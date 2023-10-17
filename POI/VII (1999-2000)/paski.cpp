//Task statement: szkopul.edu.pl/problemset/problem/-V7jnI3hTRYAtQ2DJGibzJ0s/site/
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
const int MAXN=1e3+7;
int arr[4];
int q;
int dp[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	for(int i=1;i<=3;++i) cin>>arr[i];
	for(int i=1;i<=1000;++i){
		unordered_set<int> pos;
		for(int j=1;j<=3;++j){
			if(i<arr[j]) continue;
			for(int k=1;k<=i-arr[j]+1;++k){
				pos.insert((dp[k-1])^(dp[i-k-arr[j]+1]));
			}
		}
		for(int j=0;j<=3000;++j){
			if(pos.find(j)==pos.end()){
				dp[i]=j;
				break;
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		int x; cin>>x;
		cout<<(dp[x]>0?"1":"2")<<"\n";
	}
}
