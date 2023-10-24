// Task statement: https://codeforces.com/problemset/problem/1620/D
// *Author Mateusz Kowalski*
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
const int MAXN=107;
int arr[MAXN];
void solve_case(){
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	int maxi=0;
	for(int i=1;i<=n;++i) maxi=max(maxi,arr[i]);
	int ans=maxi;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			int m3=max(0,(maxi-i-j*2+2)/3);
			bool ok=1;
			for(int k=1;k<=n;++k){
				bool found=0;
				for(int a=0;a<=i;++a){
					for(int b=0;b<=j;++b){
						if(a+b*2>arr[k]) continue;
						if((arr[k]-a-b*2)%3!=0) continue;
						if((arr[k]-a-b*2)/3<=m3) found=1;
					}
				}
				ok=found;
				if(!ok) break;
			}
			if(ok) ans=min(ans,i+j+m3);
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for(int i=1;i<=t;++i) solve_case();
}
