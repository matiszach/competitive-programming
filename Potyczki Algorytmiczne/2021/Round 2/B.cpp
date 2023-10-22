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
int n;
string s;
int dist[NAX][2];
bool vaccinated[NAX];
auto cmp=[](pii A,pii B){
	if(A.first<B.first) return true;
	if(A.first>B.first) return false;
	if(A.first==A.second) return false;
	if(B.first==B.second) return true;
	return A.second<B.second;
};
void solve_case(){
	cin>>n>>s;
	priority_queue<pii,vector<pii>,decltype(cmp)> inters(cmp);
	bool occur=0;
	int curr=0;
	for(int i=0;i<n;++i){
		if(s[i]=='1'){
			if(!occur){
				if(curr>0) inters.push({curr,curr});
			}else{
				if(curr>0) inters.push({curr/2+curr%2,curr});
			}
			occur=1;
			curr=0;
		}else ++curr;
	}	
	if(curr>0&&occur) inters.push({curr,curr});
	int ans=0;
	if(inters.empty()&&!occur) ans=n;
	if(curr<n){
		int ts=0;
		while(!inters.empty()){
			pii p=inters.top();
			int fi=p.first,se=p.second;
			inters.pop();
			if(fi<=ts) break;
			if(fi==se){
				ans+=fi-ts;
			}else{
				++ans;
				se-=(ts+1);
				if(se>0) inters.push({se,se});
			}
			++ts;
		}
	}
	cout<<n-ans<<"\n";
}
int t;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t;
	for(int i=1;i<=t;++i) solve_case();
}
