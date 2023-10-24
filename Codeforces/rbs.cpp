// Task statement: https://codeforces.com/problemset/problem/1598/F
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
const int MAXN=21,N=(1<<20),M=4e5+7;
string arr[MAXN];
vector<int> pos[MAXN][M*2];
int dp[N][2];
int bal[MAXN];
int maskBal[N];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=0;i<n;++i) cin>>arr[i];
	for(int i=0;i<n;++i){
		int curr=0;
		for(int j=0;j<(int)arr[i].size();++j){
			curr+=(arr[i][j]=='('?1:-1);
			pos[i][curr+M].pb(j+1);
		}
		bal[i]=curr;
	}
	int K=(1<<n);
	for(int mask=0;mask<K;++mask){
		for(int j=0;j<n;++j){
			if((1<<j)&mask) maskBal[mask]+=bal[j];
		}
	}
	for(int mask=0;mask<K;++mask) for(bool is_bad:{0,1}) dp[mask][is_bad]=-INF;
	dp[0][0]=0;
	for(int mask=0;mask<K;++mask){
		for(bool is_bad:{0,1}){
			for(int i=0;i<n;++i){
				if((mask|(1<<i))==mask) continue;
				if(is_bad) dp[mask|(1<<i)][1]=max(dp[mask|(1<<i)][1],dp[mask][1]);
				else{
					if(pos[i][-maskBal[mask]-1+M].empty()){
						dp[mask|(1<<i)][0]=max(dp[mask|(1<<i)][0],dp[mask][0]+(int)pos[i][-maskBal[mask]+M].size());
					}else{
						int stPos=pos[i][-maskBal[mask]-1+M][0];
						int val=0;
						if(!pos[i][-maskBal[mask]+M].empty()){
							vector<int>::iterator it=upper_bound(pos[i][-maskBal[mask]+M].begin(),pos[i][-maskBal[mask]+M].end(),stPos);
							val=it-pos[i][-maskBal[mask]+M].begin();
						}
						dp[mask|(1<<i)][1]=max(dp[mask|(1<<i)][1],dp[mask][0]+val);
					}
				}
			}
		}
	}
	int ans=max(dp[K-1][0],dp[K-1][1]);
	cout<<ans<<"\n";
}
