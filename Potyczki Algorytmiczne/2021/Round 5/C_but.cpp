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
typedef pair<int,pii> pip;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int NAX=1e5+7;
map<pair<int,pii>,int> dp;
int limit[4],arr[4];
int res[NAX];
int main()
{
	ios_base::sync_with_stdio(0);
	for(int i=1;i<=3;++i) cin>>limit[i];
	for(int i=1;i<=3;++i) cin>>arr[i];
	for(int i=0;i<=limit[3];++i) res[i]=INF;
	res[arr[1]]=res[arr[2]]=res[arr[3]]=0;
	queue<pip> Q;
	dp[{arr[1],{arr[2],arr[3]}}]=0;
	Q.push({arr[1],{arr[2],arr[3]}});
	while(!Q.empty()){
		pip curr=Q.front(); Q.pop();
		int val=dp[curr];
		int tmp[]={0,curr.first,curr.second.first,curr.second.second};
		vector<pip> cands;
		for(int i=1;i<=3;++i){
			for(int j=1;j<=3;++j){
				if(i==j||limit[j]==tmp[j]) continue;
				int new_tri[]={0,0,0,0};
				if(limit[j]-tmp[j]<tmp[i]){
					new_tri[j]=limit[j];
					new_tri[i]=tmp[i]-(limit[j]-tmp[j]);
				}else{
					new_tri[j]=tmp[j]+tmp[i];
					new_tri[i]=0;
				}
				for(int k=1;k<=3;++k) if(k!=i&&k!=j) new_tri[k]=tmp[k];
				pip p={new_tri[1],{new_tri[2],new_tri[3]}};
				if(dp.find(p)==dp.end()){
					Q.push(p);
					dp[p]=val+1;
					for(int k=1;k<=3;++k) res[new_tri[k]]=min(res[new_tri[k]],val+1);
				}
			}
		}
	}
	for(int i=0;i<=limit[3];++i) cout<<(res[i]==INF?-1:res[i])<<" ";
}
