// Task statement: https://codeforces.com/problemset/problem/522/D
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
const int MAXN=5e5+7,nTree=(1<<19);
struct per_tree{
	int T[nTree<<1];
	per_tree(){
		for(int i=0;i<(nTree<<1);++i) T[i]=INF;
	}
	void update(int pos,int val){
		pos+=nTree;
		T[pos]=min(T[pos],val);
		pos>>=1;
		while(pos>0){
			T[pos]=min(T[pos*2],T[pos*2+1]);
			pos>>=1;
		}
	}
	int query(int l,int r){
		if(l>r) return INF;
		l+=nTree; r+=nTree;
		int res=T[l];
		if(l<r) res=min(res,T[r]);
		while(l<r-1){
			if(l%2==0) res=min(res,T[l+1]);
			if(r%2==1) res=min(res,T[r-1]);
			l>>=1; r>>=1;
		}
		return res;
	}
};
int arr[MAXN];
map<int,vector<int>> occurs;
int nxt[MAXN];
vector<pii> quers[MAXN];
int ans[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i) occurs[arr[i]].pb(i);
	for(auto &V:occurs){
		vector<int> tmp=V.second;
		for(int j=0;j<(int)tmp.size()-1;++j) nxt[tmp[j]]=tmp[j+1];
		nxt[tmp.back()]=n+1;
	}
	for(int i=1;i<=m;++i){
		int l,r; cin>>l>>r;
		quers[l].pb({r,i});
	}
	per_tree t;
	for(int i=n;i>=1;--i){
		t.update(nxt[i],nxt[i]-i);
		for(pii &p:quers[i]){
			ans[p.second]=t.query(i,p.first);
		}
	}
	for(int i=1;i<=m;++i) cout<<(ans[i]==INF?-1:ans[i])<<"\n";
}
