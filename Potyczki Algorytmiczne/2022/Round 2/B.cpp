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
int arr[MAXN];
int pref[MAXN],suf[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	int cnt=0;
	for(int i=1;i<n;++i){
		if(arr[i]<arr[i+1]) ++cnt;
	}
	if(cnt==n-1){
		cout<<"NIE\n";
		return 0;
	}
	if(k>3){
		vector<int> res;
		pii used={0,0};
		int extra_used=0;
		for(int i=1;i<n;++i){
			if(arr[i]>=arr[i+1]){
				if(i>1){
					res.pb(i-1);
					extra_used=i-1;
					--k;
				}
				res.pb(i);
				used.first=i;
				if(i<n-1){
					res.pb(i+1);
					used.second=i+1;
					--k;
				}
				break;
			}
		}
		k-=2;
		for(int i=1;i<=n;++i){
			if(k==0) break;
			if(used.first==i||used.second==i||extra_used==i) continue;
			res.pb(i);
			--k;
		}
		sort(res.begin(),res.end());
		cout<<"TAK\n";
		for(int v:res) cout<<v<<" ";
		cout<<"\n";
		return 0;
	}
	pref[1]=arr[1];
	for(int i=2;i<=n;++i) pref[i]=min(pref[i-1],arr[i]);
	for(int i=n;i>=1;--i) suf[i]=max(suf[i+1],arr[i]);
	if(k==3){
		for(int i=1;i<=n-2;++i){
			if(pref[i]>=arr[i+1]){
				cout<<"TAK\n";
				cout<<i<<" "<<i+1<<"\n";
				return 0;
			}
		}
		for(int i=n;i>=3;--i){
			if(suf[i]<=arr[i-1]){
				cout<<"TAK\n";
				cout<<i-2<<" "<<i-1<<"\n";
				return 0;
			}
		}
		cout<<"NIE\n";
		return 0;
	}
	for(int i=1;i<n;++i){
		if(pref[i]>=suf[i+1]){
			cout<<"TAK\n";
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<"NIE\n";
}
