// Task statement: https://codeforces.com/problemset/problem/660/F
// *Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __int128 ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e36+7;
const long long INF=1e18+7;
#define pb push_back
const int MAXN=2e5+7;
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
long long arr[MAXN];
ll pref[MAXN],total[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	for(int i=1;i<=n;++i){
		pref[i]=pref[i-1]+(ll)arr[i]*i;
		total[i]=total[i-1]+arr[i];
	}
	ll ans=0;
	li_tree t;
	t.update({0,0});
	for(int i=1;i<=n;++i){
		ll val=t.query(total[i]);
		t.update({-i,(ll)total[i]*i-pref[i]});
		ans=max(ans,pref[i]+val);
	}
	vector<int> res;
	while(ans>0){
		res.pb(ans%10);
		ans/=10;
	}
	reverse(res.begin(),res.end());
	if(res.empty()) cout<<'0';
	for(int v:res) cout<<v;
	cout<<'\n';
}
