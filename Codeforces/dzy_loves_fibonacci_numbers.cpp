// Task statement: https://codeforces.com/problemset/problem/446/C
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
const int MAXN=3e5+7,SQR=550;
const int MOD=1e9+9;
int arr[MAXN];
int pref[MAXN],prefF[MAXN];
int points[MAXN];
pair<int,pii> Q[MAXN];
int fib[MAXN],fibS[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) pref[i]=(pref[i-1]+arr[i])%MOD;
	fib[1]=fib[2]=1;
	for(int i=3;i<=n+2;++i) fib[i]=(fib[i-1]+fib[i-2])%MOD;
	for(int i=1;i<=n+2;++i) fibS[i]=(fibS[i-1]+fib[i])%MOD;
	for(int i=0;i<m;++i) cin>>Q[i].first>>Q[i].second.first>>Q[i].second.second;
	for(int i=0;i<(m/SQR+(m%SQR==0?0:1));++i){
		int start=i*SQR,last=min(m-1,(i+1)*SQR-1);
		for(int j=start;j<=last;++j){
			if(Q[j].first==2){
				int ans=(pref[Q[j].second.second]-pref[Q[j].second.first-1]+MOD)%MOD;
				for(int k=start;k<j;++k){
					if(Q[k].first==2||Q[k].second.first>Q[j].second.second||Q[k].second.second<Q[j].second.first) continue;
					int l=max(Q[j].second.first,Q[k].second.first);
					int r=min(Q[j].second.second,Q[k].second.second);
					int len=r-l+1;
					int shift=max(0,Q[j].second.first-Q[k].second.first);
					(ans+=(fibS[len+shift]-fibS[shift]+MOD)%MOD)%=MOD;
				}
				cout<<ans<<"\n";
			}else{
				int len=Q[j].second.second-Q[j].second.first+1;
				++points[Q[j].second.first];
				(points[Q[j].second.second+1]+=(MOD-fib[len+1]))%=MOD;
				(points[Q[j].second.second+2]+=(MOD-fib[len]))%=MOD;
			}
		}
		for(int j=1;j<=n;++j){
			int ext=(prefF[j-1]+prefF[max(0,j-2)])%MOD;
			(prefF[j]+=ext)%=MOD;
			(prefF[j]+=points[j])%=MOD;
			points[j]=0;
			pref[j]=0;
			(arr[j]+=prefF[j])%=MOD;
		}
		for(int j=1;j<=n;++j) prefF[j]=0;
		for(int j=1;j<=n;++j) pref[j]=(pref[j-1]+arr[j])%MOD;
	}
}
