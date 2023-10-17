//Task statement: szkopul.edu.pl/problemset/problem/E0BY-XMtZxZOgcAcQL1_eIab/site/
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
const int MAXN=1e4+7;
typedef long double ld;
typedef pair<ld,ld> pdd;
pair<int,pdd> arr[MAXN];
bool cmp(pair<int,pdd> &A,pair<int,pdd> &B){
	ld t1=A.second.second+B.second.first*A.second.second+B.second.second;
	ld t2=B.second.second+A.second.first*B.second.second+A.second.second;
	return t1<t2;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i].second.first>>arr[i].second.second;
	for(int i=1;i<=n;++i) arr[i].first=i;
	sort(arr+1,arr+n+1,cmp);
	for(int i=1;i<=n;++i) cout<<arr[i].first<<"\n";
}

