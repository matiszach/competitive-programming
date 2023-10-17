//Task statement: szkopul.edu.pl/problemset/problem/A3QYXKEiRLgKerciOwA_lbCD/site/
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
int n,q;
int arr[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	cin>>q;
	for(int z=1;z<=q;++z){
		int k; cin>>k;
		deque<pii> p[2];
		int c0=0,c1=1;
		for(int i=2;i<=k;++i){
			if(arr[i]>=arr[1]){
				while(!p[1].empty()&&p[1].front().first<=arr[i]) p[1].pop_front();
				p[1].push_front({arr[i],i});
			}else{
				while(!p[0].empty()&&p[0].front().first<=arr[i]) p[0].pop_front();
				p[0].push_front({arr[i],i});
			}
		}
		p[0].push_back({arr[1],1});
		int curr=1;
		int last=0;
		bool was_empty=p[1].empty();
		for(int i=k+1;i<=n;++i){
			if(!p[c0].empty()&&arr[i]<p[c0].back().first){
				while(!p[c0].empty()&&p[c0].front().first<=arr[i]) p[c0].pop_front();
				p[c0].push_front({arr[i],i});
				last=1;
			}else if((!p[c0].empty()&&arr[i]>=p[c0].back().first)||(!p[c1].empty()&&arr[i]<p[c1].back().first)||was_empty){
				while(!p[c1].empty()&&p[c1].front().first<=arr[i]) p[c1].pop_front();
				p[c1].push_front({arr[i],i});
				last=0;
				was_empty=0;
			}else{
				last=0;
				swap(c0,c1);
				++curr;
				while(!p[c1].empty()&&p[c1].front().first<=arr[i]) p[c1].pop_front();
				p[c1].push_front({arr[i],i});
			}
			if(!p[c0].empty()&&p[c0].back().second==i-k) p[c0].pop_back();
			if(!p[c1].empty()&&p[c1].back().second==i-k) p[c1].pop_back();
		}
		cout<<curr-last<<"\n";
	}
}
