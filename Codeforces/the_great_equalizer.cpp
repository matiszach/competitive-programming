// Task statement: https://codeforces.com/problemset/problem/1862/G
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
const int MAXN=2e5+7;
int arr[MAXN];
void solve_case(){
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	multiset<int> ms;
	for(int i=1;i<=n;++i) ms.insert(arr[i]);
	multiset<int> diff;
	auto it2=ms.begin();
	while(it2!=ms.end()){
		if(it2!=ms.begin()){
			auto l=it2;
			diff.insert(*it2-*(--l));
		}
		auto r=it2;
		++r;
		if(r!=ms.end()){
			diff.insert(*r-*it2);
		}
		++it2;
	}
	int q; cin>>q;
	for(int i=1;i<=q;++i){
		int a,b; cin>>a>>b;
		auto it=ms.lower_bound(arr[a]);
		auto l=ms.end();
		if(it!=ms.begin()){
			l=it;
			--l;
			int x=*l;
			diff.erase(diff.lower_bound(*it-x));
			diff.erase(diff.lower_bound(*it-x));
		}
		auto r=it;
		++r;
		if(r!=ms.end()){
			int x=*r;
			diff.erase(diff.lower_bound(x-*it));
			diff.erase(diff.lower_bound(x-*it));
		}
		if(l!=ms.end()&&r!=ms.end()){
			diff.insert(*r-*l);
			diff.insert(*r-*l);
		}
		ms.erase(ms.lower_bound(arr[a]));
		ms.insert(b);
		it=ms.lower_bound(b);
		l=ms.end();
		if(it!=ms.begin()){
			l=it;
			--l;
			int x=*l;
			diff.insert(*it-x);
			diff.insert(*it-x);
		}
		r=it;
		++r;
		if(r!=ms.end()){
			int x=*r;
			diff.insert(x-*it);
			diff.insert(x-*it);
		}
		if(l!=ms.end()&&r!=ms.end()){
			diff.erase(diff.lower_bound(*r-*l));
			diff.erase(diff.lower_bound(*r-*l));
		}
		arr[a]=b;
		auto maxVal=ms.end();
		auto maxDiff=diff.end();
		if(n==1) cout<<arr[1]<<" ";
		else cout<<(*(--maxVal)+*(--maxDiff))<<" ";
	}
	cout<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--) solve_case();
}
