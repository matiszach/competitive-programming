//Task statement: szkopul.edu.pl/problemset/problem/oyn0rTJ97w-M1zXYEWD-ScnN/site/
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
const int NAX=5e5+7;
int n;
pair<pii,int> arr[NAX];
bool cmp(pair<pii,int> &A,pair<pii,int> &B){
	return A.first.second<B.first.second;
}
bool cmp2(int &A,int &B){
	return arr[A].first.second<arr[B].first.second;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i].first.first>>arr[i].first.second;
	for(int i=1;i<=n;++i) arr[i].second=i;
	sort(arr+1,arr+1+n,cmp);
	priority_queue<pii> Q;
	int curr=0;
	for(int i=1;i<=n;++i){
		if(arr[i].first.first>arr[i].first.second) continue;
		if(curr+arr[i].first.first<=arr[i].first.second){
			curr+=arr[i].first.first;
			Q.push({arr[i].first.first,i});
		}else{
			if(Q.top().first>arr[i].first.first){
				curr-=Q.top().first;
				curr+=arr[i].first.first;
				Q.pop();
				Q.push({arr[i].first.first,i});
			}else continue;
		}
	}
	cout<<Q.size()<<"\n";
	vector<int> vids;
	while(!Q.empty()){
		vids.pb(Q.top().second);
		Q.pop();
	}
	sort(vids.begin(),vids.end(),cmp2);
	curr=0;
	for(int v:vids){
		cout<<arr[v].second<<" "<<curr+1<<"\n";
		curr+=arr[v].first.first;
	}
}
