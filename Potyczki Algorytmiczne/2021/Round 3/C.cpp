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
const int NAX=5e5+7;
int n,x;
pii arr[NAX];
ll pref[NAX];
bool sum_krol_wod[NAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x;
		arr[i]={x,i};
	}
	sort(arr+1,arr+1+n);
	int last=1;
	ll curr=0;
	arr[n+1]={INF,0};
	bool occur=0;
	for(int i=1;i<=n;++i){
		curr+=arr[i].first;
		if(arr[i].first<arr[i+1].first){
			for(int j=i;j>=last;--j){
				if(occur) pref[j]=curr;
				else pref[j]=arr[j].first;
			}
			occur=1;
			last=i+1;
		}
	}
	arr[n+1].first=arr[n].first;
	for(int i=n;i>=1;--i){
		if(pref[i]>arr[i+1].first) sum_krol_wod[arr[i].second]=1;
		else break;
	}
	for(int i=1;i<=n;++i) cout<<(sum_krol_wod[i]?"T":"N");
	cout<<"\n";
}
