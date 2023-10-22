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
const int MAXN=5e4+7;
int arr[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	//case 1
	int curr=0;
	int last=arr[1];
	for(int i=2;i<=n;++i){
		if(i%2){
			if(last<=arr[i]){
				++curr;
				last=-INF;
			}else last=arr[i];
		}else{
			if(last>=arr[i]){
				++curr;
				last=INF;
			}else last=arr[i];
		}
	}
	int ans=curr;
	curr=0;
	//case 2
	last=arr[1];
	for(int i=2;i<=n;++i){
		if(i%2==0){
			if(last<=arr[i]){
				++curr;
				last=-INF;
			}else last=arr[i];
		}else{
			if(last>=arr[i]){
				++curr;
				last=INF;
			}else last=arr[i];
		}
	}
	ans=min(ans,curr);
	cout<<ans<<"\n";
}
