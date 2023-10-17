//Task statement: szkopul.edu.pl/problemset/problem/Hhip15j-8Ro2dOb_4oB98C-G/site/
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
int arr[MAXN];
int cnt[MAXN];
vector<int> nums[MAXN];
int idx[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,s; cin>>n>>s;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) arr[i]=(arr[i]+1)%s;
	for(int i=1;i<=n;++i) nums[arr[i]].pb(i);
	priority_queue<pii> Q;
	for(int i=1;i<=n;++i) ++cnt[arr[i]];
	for(int i=0;i<MAXN;++i){
		if(cnt[i]>0) Q.push({cnt[i],i});
	}
	vector<int> ans;
	int curr=0;
	int lines=0;
	while(!Q.empty()){
		pii p=Q.top(); Q.pop();
		if((curr+p.second)%s<s-1){
			if(p.first>1) Q.push({p.first-1,p.second});
			(curr+=p.second)%=s;
			ans.pb(p.second);
		}else{
			if(!Q.empty()){
				pii p2=Q.top(); Q.pop();
				if(p2.first>1) Q.push({p2.first-1,p2.second});
				Q.push(p);
				(curr+=p2.second)%=s;
				ans.pb(p2.second);
			}else{
				if((int)ans.size()<n-1) ++lines;
				curr=0;
				if(p.first>1) Q.push({p.first-1,p.second});
				ans.pb(p.second);
			}
		}
	}
	cout<<lines<<"\n";
	for(int v:ans) cout<<nums[v][idx[v]++]<<" ";
	cout<<"\n";
}
