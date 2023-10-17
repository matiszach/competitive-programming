//Task statement: szkopul.edu.pl/problemset/problem/TcOKBp0vma5YnJ8bU9J4xRt-/site/
//*Author Mateusz Kowalski*
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
const int MAXN=5e5+7,nTree=(1<<20);
int T[nTree<<1],ps[nTree<<1];
void update(int l,int r,int val,int p){
	l+=nTree; r+=nTree;
	if(l>r) return;
	if(T[l]<val){
		T[l]=val;
		ps[l]=p;
	}
	if(l<r){
		if(T[r]<val){
			T[r]=val;
			ps[r]=p;
		}
	}
	while(l<r-1){
		if(l%2==0){
			if(T[l+1]<val){
				T[l+1]=val;
				ps[l+1]=p;
			}
		}
		if(r%2==1){
			if(T[r-1]<val){
				T[r-1]=val;
				ps[r-1]=p;
			}
		}
		l>>=1; r>>=1;
	}
}
pii query(int pos){
	pos+=nTree;
	int res=T[pos],res2=ps[pos];
	while(pos>0){
		if(T[pos]>res){
			res=T[pos];
			res2=ps[pos];
		}
		pos>>=1;
	}
	return {res,res2};
}
int arr[MAXN];
int pre[MAXN];
char b[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=k;++i) cin>>b[i];
	for(int i=k+1;i<n;++i) b[i]=b[i-k];
	int ans=0;
	int st=0;
	for(int i=1;i<=n;++i){
		pii tmp=query(arr[i]);
		int x=tmp.first+1;
		pre[i]=tmp.second;
		if(ans<x){
			ans=x;
			st=i;
		}
		if(b[x]=='<') update(arr[i]+1,nTree-1,x,i);
		if(b[x]=='>') update(1,arr[i]-1,x,i);
		if(b[x]=='=') update(arr[i],arr[i],x,i);
	}
	vector<int> res;
	while(st!=0){
		res.pb(arr[st]);
		st=pre[st];
	}
	reverse(res.begin(),res.end());
	cout<<ans<<"\n";
	cout<<res<<"\n";
}
