// Task statement: https://codeforces.com/problemset/problem/1427/C
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
const int SIZE=1e5+7,nTree=(1<<17);
int r,n,x,y,a;
int dp[SIZE];
pair<int,pii> arr[SIZE];
int dist(pii A,pii B){
	return abs(A.first-B.first)+abs(A.second-B.second);
}
int T[nTree<<1];
void update(int pos,int val){
	pos+=nTree;
	T[pos]=val;
	pos>>=1;
	while(pos>0){
		T[pos]=max(T[pos*2],T[pos*2+1]);
		pos>>=1;
	}
}
int query(int l,int p){
	l+=nTree; p+=nTree;
	int res=T[l];
	if(l<p) res=max(res,T[p]);
	while(l<p-1){
		if(l%2==0) res=max(res,T[l+1]);
		if(p%2==1) res=max(res,T[p-1]);
		l>>=1; p>>=1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>r>>n;
	for(int i=1;i<=n;++i){
		cin>>a>>x>>y;
		arr[i]={a,{x,y}};
	}
	arr[0]={0,{1,1}};
	for(int i=1;i<=n;++i){
		int res=0;
		for(int j=i-1;j>=max(0,i-(r<<1));--j){
			if(dist(arr[i].second,arr[j].second)<=arr[i].first-arr[j].first&&dist(arr[i].second,arr[0].second)<=arr[i].first){
				res=max(res,dp[j]+1);
			}
		}
		if(i>(r<<1)) res=max(res,query(0,i-(r<<1))+1);
		dp[i]=res;
		update(i,dp[i]);
	}
	cout<<query(1,n)<<"\n";
}
