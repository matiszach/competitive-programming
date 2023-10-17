//Task statement: szkopul.edu.pl/problemset/problem/hogW-qBD1uDPGDS4jTohYMwc/site/
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
int arr[MAXN*2];
int nxt[MAXN];
int total,max_diff;
void solve_case(){
	int x; cin>>x;
	if(x>=total){
		cout<<"1\n";
		return;
	}
	if(x<max_diff){
		cout<<"NIE\n";
		return;
	}
	int j=0;
	int curr=0;
	for(int i=1;i<=n;++i){
		while(curr+arr[j+1]<=x){
			++j;
			curr+=arr[j];
		}
		nxt[i-1]=j%n;
		curr-=arr[i];
	}
	int idx=0;
	for(int i=1;i<=n;++i) idx=nxt[idx];
	int curr_dist=0;
	int ans=0;
	while(curr_dist<n){
		int tmp=nxt[idx];
		if(tmp>idx) curr_dist+=(tmp-idx);
		else curr_dist+=(n-idx+tmp);
		idx=tmp;
		++ans;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	int s; cin>>n>>s;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) arr[i+n]=arr[i];
	for(int i=1;i<=n;++i){
		total+=arr[i];
		max_diff=max(max_diff,arr[i]);
	}
	for(int i=1;i<=s;++i) solve_case();
}
