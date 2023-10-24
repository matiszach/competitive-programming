// Task statement: https://codeforces.com/problemset/problem/1527/E
// *Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INFLL=1e17+7;
const int NAX=35e3+7,KAX=107,nTree=(1<<16);
ll T[nTree<<1],lazy[nTree<<1];
void update(int v,int start,int end,int l,int r,ll val){
	if(lazy[v]!=0){
		T[v]+=lazy[v];
		if(start!=end){
			lazy[v*2]+=lazy[v];
			lazy[v*2+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(start>r||end<l||start>end) return;
	if(start>=l&&end<=r){
		T[v]+=val;
		if(start!=end){
			lazy[v*2]+=val;
			lazy[v*2+1]+=val;
		}
		return;
	}
	int mid=(start+end)>>1;
	update(v*2,start,mid,l,r,val);
	update(v*2+1,mid+1,end,l,r,val);
	T[v]=min(T[v*2],T[v*2+1]);
}
ll query(int v,int start,int end,int l,int r){
	if(start>r||end<l||start>end) return INFLL;
	if(lazy[v]!=0){
		T[v]+=lazy[v];
		if(start!=end){
			lazy[v*2]+=lazy[v];
			lazy[v*2+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(start>=l&&end<=r) return T[v];
	int mid=(start+end)>>1;
	ll q1=query(v*2,start,mid,l,r);
	ll q2=query(v*2+1,mid+1,end,l,r);
	return min(q1,q2);
}
ll dp[KAX][NAX];
void build(int v,int idx){
	T[v]=lazy[v]=0;
	if(v<nTree){
		build(v*2,idx);
		build(v*2+1,idx);
		T[v]=min(T[v*2],T[v*2+1]);
	}else T[v]=dp[idx][v-nTree];
}
int n,k;
int arr[NAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=0;i<=k;++i) for(int j=0;j<=n;++j) dp[i][j]=INFLL;
	dp[0][0]=0;
	build(1,0);
	for(int i=1;i<=k;++i){
		vector<int> last(n+1);
		for(int j=1;j<=n;++j){
			if(last[arr[j]]==0){
				last[arr[j]]=j;
			}else{
				update(1,0,nTree-1,0,last[arr[j]]-1,j-last[arr[j]]);
				last[arr[j]]=j;
			}
			dp[i][j]=query(1,0,nTree-1,0,j-1);
		}
		build(1,i);
	}
	cout<<dp[k][n]<<"\n";
}
