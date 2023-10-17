//Task statement: szkopul.edu.pl/problemset/problem/v7LhQdIK3z6mWSVH4I7F266w/site/
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
const int MAXN=2e5+7;
int n,m,z,a,b,c;
vector<pair<int,pii>> G[MAXN];
int biciak[MAXN];
int preorder[MAXN],postorder[MAXN];
int idx=0;
int conv[MAXN];
void DFS(int x,int pre){
	preorder[x]=++idx;
	for(pair<int,pii> v:G[x]){
		if(v.first!=pre){
			biciak[v.first]=v.second.first;
			conv[v.second.second]=v.first;
			DFS(v.first,x);
		}
	}
	postorder[x]=++idx;
}
bool anc(int pre,int x){
	if(x==pre) return 1;
	return (preorder[x]>preorder[pre]&&postorder[x]<postorder[pre]);
}
int l=0,r=0;
int res[MAXN];
vector<int> to_ans[MAXN];
int curr=0;
int amount[MAXN];
struct ques{
	char type;
	int a,b;
};
ques qrs[MAXN];
void DFS2(int x,int pre){
	if(x!=1){
		++amount[biciak[x]];
		if(amount[biciak[x]]==1) ++curr;
	}
	while(!to_ans[x].empty()){
		idx=to_ans[x].back();
		to_ans[x].pop_back();
		vector<pair<int,pii>> to_edit;
		int extra=0;
		for(int i=l;i<idx;++i){
			if(qrs[i].type=='B'){
				if(anc(qrs[i].a,x)){
					to_edit.pb({i,{biciak[qrs[i].a],qrs[i].a}});
					--amount[biciak[qrs[i].a]];
					if(amount[biciak[qrs[i].a]]==0) --extra;
					biciak[qrs[i].a]=qrs[i].b;
					++amount[qrs[i].b];
					if(amount[qrs[i].b]==1) ++extra;
				}
			}
		}
		while(!to_edit.empty()){
			pair<int,pii> p=to_edit.back();
			to_edit.pop_back();
			--amount[qrs[p.first].b];
			++amount[p.second.first];
			biciak[p.second.second]=p.second.first;
		}
		res[idx]=curr+extra;
	}
	for(pair<int,pii> p:G[x]){
		if(p.first!=pre) DFS2(p.first,x);
	}
	if(x!=1){
		--amount[biciak[x]];
		if(amount[biciak[x]]==0) --curr;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>z;
	for(int i=1;i<n;++i){
		cin>>a>>b>>c;
		G[a].pb({b,{c,i}});
		G[b].pb({a,{c,i}});
	}
	DFS(1,1);
	for(int i=1;i<=z;++i){
		cin>>qrs[i].type;
		if(qrs[i].type=='Z') cin>>qrs[i].a;
		else{
			cin>>qrs[i].a>>qrs[i].b;
			qrs[i].a=conv[qrs[i].a];
		}
	}
	int sqr=400;
	for(int i=1;i<=z;i+=sqr){
		l=i; r=min(z,i+sqr-1);
		for(int j=l;j<=r;++j){
			if(qrs[j].type=='Z') to_ans[qrs[j].a].pb(j);
		}
		DFS2(1,1);
		for(int j=l;j<=r;++j){
			if(qrs[j].type=='B'){
				biciak[qrs[j].a]=qrs[j].b;
			}
		}
		for(int j=1;j<=m;++j) amount[j]=0;
	}
	for(int i=1;i<=z;++i){
		if(qrs[i].type=='Z') cout<<res[i]<<"\n";
	}
}
