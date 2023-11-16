// Task statement: https://codeforces.com/problemset/problem/1837/F
// *Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=3e5+7;
int arr[MAXN];
int n,k;
int pref[MAXN];
bool check(ll x){
	priority_queue<int> st;
	ll curr=0;
	pref[0]=k;
	int req=k;
	for(int i=1;i<=n;++i){
		if((int)st.size()<k){
			if(!st.empty()&&curr+arr[i]>x){
				int val=st.top();
				if(val>arr[i]){
					curr-=val;
					curr+=arr[i];
					st.pop();
					st.push(arr[i]);
				}
			}else if(arr[i]<=x){
				curr+=arr[i];
				st.push(arr[i]);
				--req;
			}
		}
		pref[i]=req;
	}
	priority_queue<int> nd;
	ll total=0;
	for(int i=n;i>=1;--i){
		while((int)nd.size()>pref[i-1]){
			total-=nd.top();
			nd.pop();
		}
		if((int)nd.size()<pref[i-1]){
			if(!nd.empty()&&total+arr[i]>x){
				int val=nd.top();
				if(val>arr[i]){
					nd.pop();
					total-=val;
					nd.push(arr[i]);
					total+=arr[i];
				}
			}else if(arr[i]<=x){
				nd.push(arr[i]);
				total+=arr[i];
			}
		}
		if((int)nd.size()==pref[i-1]) return 1;
	}
	return 0;
}
void solve_case(){
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	ll l=1,r=3e14,mid=0;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--) solve_case();
}
