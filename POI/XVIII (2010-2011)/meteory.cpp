//Task statement: szkopul.edu.pl/problemset/problem/k6tz-HdwVKUeP7p9RMpRE6RO/site/
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
const int MAXN=3e5+7,nTree=(1<<19);
ll T[nTree<<1];
void update(int l,int r,int val){
	l+=nTree; r+=nTree;
	T[l]+=val;
	if(l<r) T[r]+=val;
	while(l<r-1){
		if(l%2==0) T[l+1]+=val;
		if(r%2==1) T[r-1]+=val;
		l>>=1; r>>=1;
	}
}
ll query(int pos){
	pos+=nTree;
	ll res=0;
	while(pos>0){
		res+=T[pos];
		pos>>=1;
	}
	return res;
}
int n,m,k;
int arr[MAXN];
struct ques{
	int a,b,c;
};
ques Q[MAXN];
int req[MAXN];
int l[MAXN],r[MAXN];
vector<int> pos[MAXN];
int ans[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i) cin>>arr[i];
	for(int i=1;i<=m;++i) pos[arr[i]].pb(i);
	for(int i=1;i<=n;++i) cin>>req[i];
	cin>>k;
	for(int i=1;i<=k;++i) cin>>Q[i].a>>Q[i].b>>Q[i].c;
	vector<pii> to_check;
	for(int i=1;i<=n;++i) to_check.pb({(1+k)>>1,i});
	for(int i=1;i<=n;++i){
		l[i]=1;
		r[i]=k;
	}
	while(!to_check.empty()){
		vector<pii> tmp;
		int curr=1;
		for(pii v:to_check){
			while(curr<=v.first){
				if(Q[curr].a<=Q[curr].b) update(Q[curr].a,Q[curr].b,Q[curr].c);
				else{
					update(1,Q[curr].b,Q[curr].c);
					update(Q[curr].a,m,Q[curr].c);
				}
				++curr;
			}
			ll amount=0;
			for(int w:pos[v.second]){
				amount+=query(w);
				if(amount>=req[v.second]) break;
			}
			if(amount<req[v.second]){
				if(v.first==k){
					ans[v.second]=-1;
				}
				else{
					l[v.second]=v.first+1;
					if(l[v.second]==r[v.second]) ans[v.second]=v.first+1;
					else tmp.pb({(l[v.second]+r[v.second])>>1,v.second});
				}
			}else{
				r[v.second]=v.first;
				if(l[v.second]==r[v.second]) ans[v.second]=v.first;
				else tmp.pb({(l[v.second]+r[v.second])>>1,v.second});
			}
		}
		to_check.clear();
		for(pii v:tmp) to_check.pb(v);
		sort(to_check.begin(),to_check.end());
		for(int i=1;i<nTree*2;++i) T[i]=0;
	}
	for(int i=1;i<=k;++i){
		if(Q[i].a<=Q[i].b) update(Q[i].a,Q[i].b,Q[i].c);
		else{
			update(1,Q[i].b,Q[i].c);
			update(Q[i].a,m,Q[i].c);
		}
	}
	for(int i=1;i<=n;++i){
		ll amount=0;
		for(int v:pos[i]){
			amount+=query(v);
			if(amount>=req[i]) break;
		}
		if(amount<req[i]) ans[i]=-1;
	}
	for(int i=1;i<=n;++i) cout<<(ans[i]==-1?"NIE":to_string(ans[i]))<<"\n";
}
