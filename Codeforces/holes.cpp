// Task statement: https://codeforces.com/problemset/problem/13/E
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
const int MAXN=1e5+7,SQR=300;
int arr[MAXN];
int nxt[MAXN],cnt[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;++i) cin>>arr[i];
	for(int i=0;i<n/SQR+(n%SQR?1:0);++i){
		int l=i*SQR,r=min(n,(i+1)*SQR)-1;
		for(int j=l;j<=r;++j){
			int pos=j,jumps=0,last=j;
			while(pos<=r){
				last=pos;
				pos+=arr[pos];
				++jumps;
			}
			nxt[j]=min(pos,n);
			if(nxt[j]==n){
				nxt[j]=last;
				--jumps;
			}
			cnt[j]=jumps;
		}
	}
	for(int i=1;i<=m;++i){
		bool type; cin>>type;
		if(type){
			int x; cin>>x;
			--x;
			int ans=0;
			while(x+arr[x]<n){
				ans+=cnt[x];
				x=nxt[x];
			}
			cout<<x+1<<" "<<ans+cnt[x]+1<<"\n";
		}else{
			int a,b; cin>>a>>b;
			--a;
			arr[a]=b;
			int l=(a/SQR)*SQR,r=min(n,(a/SQR+1)*SQR)-1;
			int pos=a,jumps=0,last=a;
			while(pos<=r){
				last=pos;
				pos+=arr[pos];
				++jumps;
			}
			nxt[a]=min(pos,n);
			if(nxt[a]==n){
				nxt[a]=last;
				--jumps;
			}
			cnt[a]=jumps;
			for(int j=a-1;j>=l;--j){
				if(j+arr[j]<=r){
					nxt[j]=nxt[j+arr[j]];
					cnt[j]=cnt[j+arr[j]]+1;
				}
			}
		}
	}
}
