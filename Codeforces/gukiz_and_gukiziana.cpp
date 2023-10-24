// Task statement: https://codeforces.com/problemset/problem/551/E
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
const int SQR=710,MAXN=5e5+7;
int n,q;
int cont[SQR+7];
map<int,int> m[SQR+7];
int arr[MAXN];
void update(int l,int r,int x){
	int beg=l/SQR-(l%SQR==0)+1,last=r/SQR-(r%SQR==0)-1;
	for(int i=beg;i<=last;++i){
		cont[i]+=x;
		if(cont[i]>INF) cont[i]=INF;
	}
	if(beg>last){
		for(int i=l;i<=r;++i){
			beg=i/SQR-(i%SQR==0)+1;
			--m[beg-1][arr[i]];
			if(m[beg-1][arr[i]]==0) m[beg-1].erase(arr[i]);
			arr[i]+=x;
			if(arr[i]>INF) arr[i]=INF;
			++m[beg-1][arr[i]];
		}
		return;
	}
	for(int i=l;i<=beg*SQR;++i){
		--m[beg-1][arr[i]];
		if(m[beg-1][arr[i]]==0) m[beg-1].erase(arr[i]);
		arr[i]+=x;
		if(arr[i]>INF) arr[i]=INF;
		++m[beg-1][arr[i]];
	}
	for(int i=(last+1)*SQR+1;i<=r;++i){
		--m[last+1][arr[i]];
		if(m[last+1][arr[i]]==0) m[last+1].erase(arr[i]);
		arr[i]+=x;
		if(arr[i]>INF) arr[i]=INF;
		++m[last+1][arr[i]];
	}
}
int query(int x){
	int beg=-1,last=-1;
	for(int i=0;i<SQR;++i){
		if(m[i].count(x-cont[i])>0){
			beg=i;
			break;
		}
	}
	for(int i=SQR-1;i>=0;--i){
		if(m[i].count(x-cont[i])>0){
			last=i;
			break;
		}
	}
	if(beg==-1||last==-1) return -1;
	for(int i=beg*SQR+1;i<=min((beg+1)*SQR,n);++i){
		if(arr[i]+cont[beg]==x){
			beg=i;
			break;
		}
	}
	for(int i=min((last+1)*SQR,n);i>=1;--i){
		if(arr[i]+cont[last]==x){
			last=i;
			break;
		}
	}
	return last-beg;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) ++m[i/SQR-(i%SQR==0)][arr[i]];
	for(int i=1;i<=q;++i){
		int type; cin>>type;
		if(type==1){
			int l,r,x;
			cin>>l>>r>>x;
			update(l,r,x);
		}else{
			int x; cin>>x;
			cout<<query(x)<<"\n";
		}
	}
}
