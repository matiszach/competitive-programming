// Task statement: https://codeforces.com/problemset/problem/631/E
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
struct line{
	ll a,b;
	ll operator()(ll x){return a*x+b;}
};
struct li_tree{
	struct node{
		node *left_node=nullptr,*right_node=nullptr;
		line l;
		node(line x){l=x;}
	};
	node *root=new node({0,-INFLL*5});
	void update(node *v,ll start,ll end,line x){
		if(v->l(start)>x(start)&&v->l(end)>x(end)) return;
		if(v->l(start)<x(start)&&v->l(end)<x(end)){v->l=x; return;}
		ll mid=(start+end)>>1;
		if(v->l(mid)<x(mid)) swap(v->l,x);
		if(start==end) return;
		if(v->l(start)<x(start)){
			if(v->left_node==nullptr){v->left_node=new node(x); return;}
			update(v->left_node,start,mid,x);
		}else{
			if(v->right_node==nullptr){v->right_node=new node(x); return;}
			update(v->right_node,mid+1,end,x);
		}
	}
	ll query(node *v,ll start,ll end,ll x){
		if(v==nullptr) return -INFLL*5;
		if(start==end) return v->l(x);
		ll mid=(start+end)>>1;
		if(x<=mid) return max(v->l(x),query(v->left_node,start,mid,x));
		else return max(v->l(x),query(v->right_node,mid+1,end,x));
	}
	void update(line x){update(root,-INF,INF,x);}
	ll query(ll x){return query(root,-INF,INF,x);}
};
const int MAXN=2e5+7;
ll a[MAXN],pref[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) pref[i]=pref[i-1]+a[i];
	ll total=0;
	for(int i=1;i<=n;++i) total+=a[i]*i;
	ll ans=total;
	li_tree t;
	t.update({1,0});
	for(int i=2;i<=n;++i){
		ans=max(ans,total+t.query(a[i])+pref[i-1]-a[i]*i);
		t.update({i,-pref[i-1]});
	}
	li_tree t2;
	t2.update({n,-pref[n]});
	for(int i=n-1;i>=1;--i){
		ans=max(ans,total+t2.query(a[i])+pref[i]-a[i]*i);
		t2.update({i,-pref[i]});
	}
	cout<<ans<<"\n";
}
