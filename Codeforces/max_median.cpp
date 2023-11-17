// Task statement: https://codeforces.com/problemset/problem/1486/D
// *Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
template<typename T>
ostream& operator << (ostream& os,vector<T> &v){
	for(auto &u:v){os<<u<<char(32);} return os;
}
template<typename P,typename L>
ostream& operator << (ostream& os,pair<P,L> &p){
	os<<char(40)<<p.first<<char(44)<<p.second<<char(41); return os;
}
const int MAXN=2e5+7;
int arr[MAXN];
int n,k;
int tmp[MAXN];
int pref[MAXN];
bool check(int val){
	for(int i=1;i<=n;++i) tmp[i]=(arr[i]<val?-1:1);
	for(int i=1;i<=n;++i) pref[i]=pref[i-1]+tmp[i];
	int mini=0;
	for(int i=k;i<=n;++i){
		if(pref[i]-mini>0) return 1;
		mini=min(mini,pref[i-k+1]);
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	int l=1,r=1e9,mid=0;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
}
