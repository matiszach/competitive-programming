//Task statement: szkopul.edu.pl/problemset/problem/U9UaVfIMEFZCU5M6RpvcylQT/site/
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
const int NAX=1e5+7;
const ll MOD=1e9+7;
int n;
int arr[NAX],res[NAX];
int last[NAX];
int cnt[NAX];
bitset<NAX> done;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	//n==1
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	//n==2
	if(n==2){
		if(arr[1]==arr[2]) cout<<"0\n";
		else cout<<"1\n";
		return 0;
	}
	//n==3
	if(n==3){
		if(arr[1]!=arr[3]||(arr[1]==arr[2]&&arr[2]==arr[3])) cout<<"0\n";
		else cout<<"2\n";
		return 0;
	}
	//n>3
	bool ok=1;
	for(int i=1;i<=n;++i){
		++cnt[arr[i]];
		if(cnt[arr[i]]>2) ok=0;
		if(last[arr[i]]==0) last[arr[i]]=i;
		else{
			if(i-last[arr[i]]!=2) ok=0;
			else{
				res[i-1]=arr[i];
				done[arr[i]]=1;
			}
		}
	}
	//contradiction
	if(!ok){
		cout<<"0\n";
		return 0;
	}
	//main code
	res[2]=arr[1]; res[n-1]=arr[n];
	done[arr[1]]=1; done[arr[n]]=1;
	for(int i=2;i<=n-1;++i){
		if(res[i-1]!=arr[i]&&res[i+1]!=arr[i]){
			if(res[i-1]>0&&res[i+1]>0){
				cout<<"0\n";
				return 0;
			}
			if(res[i-1]>0){
				res[i+1]=arr[i];
				done[arr[i]]=1;
			}
			else if(res[i+1]>0){
				res[i-1]=arr[i];
				done[arr[i]]=1;
			}
		}
		int x=n-i+1;
		if(res[x-1]!=arr[x]&&res[x+1]!=arr[x]){
			if(res[x-1]>0&&res[x+1]>0){
				cout<<"0\n";
				return 0;
			}
			if(res[x-1]>0){
				res[x+1]=arr[x];
				done[arr[x]]=1;
			}
			else if(res[x+1]>0){
				res[x-1]=arr[x];
				done[arr[x]]=1;
			}
		}
	}
	res[0]=INF; res[n+1]=INF; res[n+2]=INF; res[n+3]=INF;
	vector<int> segs;
	int curr=0;
	for(int i=2;i<=n+1;i+=2){
		if(res[i-1]==0&&res[i+1]==0) ++curr;
		else{
			if(curr>0) segs.pb(curr+1);
			curr=0;
		}
	}
	for(int i=3;i<=n+1;i+=2){
		if(res[i-1]==0&&res[i+1]==0) ++curr;
		else{
			if(curr>0) segs.pb(curr+1);
			curr=0;
		}
	}
	int rest=0,zeros=0;
	for(int i=1;i<=n;++i) if(cnt[i]==0) ++rest;
	for(int i=1;i<=n;++i) if(res[i]==0) ++zeros;
	for(int v:segs) zeros-=(v-1);
	//Newton(zeros/rest)
	ll ans=1;
	for(int v:segs){
		ans*=(ll)v;
		ans%=MOD;
	}
	for(ll i=rest;i>=rest-zeros+1;--i){
		ans*=i;
		ans%=MOD;
	}
	cout<<ans<<"\n";
}
