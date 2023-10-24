// Task statement: https://codeforces.com/problemset/problem/1239/C
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
const int MAXN=1e5+7;
map<ll,vector<pii>> m;
ll res[MAXN];
int arr[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; ll p;
	cin>>n>>p;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		m[arr[i]].pb({i,1});
	}
	set<int> in_queue;
	ll curr_time=0;
	for(auto it=m.begin();it!=m.end();++it){
		for(pii v:m[it->first]){
			if(v.second==1){
				pq.push(v.first);
			}else{
				in_queue.erase(v.first);
				res[v.first]=it->first;
			}
		}
		if(!pq.empty()&&(in_queue.size()==0||pq.top()<(*in_queue.begin()))){
			int curr=pq.top(); pq.pop();
			curr_time=max(it->first,curr_time)+p;
			m[curr_time].pb({curr,2});
			in_queue.insert(curr);
		}
	}
	for(int i=1;i<=n;++i) cout<<res[i]<<" ";
}
