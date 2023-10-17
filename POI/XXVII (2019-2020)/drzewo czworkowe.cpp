//Task statement: szkopul.edu.pl/problemset/problem/GcP-wwgKv1HiCzuFRKE6n7-U/site/
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
const int MAXN=1e6+7,MOD=1e9+7;
struct node{
	int type;
	int LG,PG,LD,PD;
	int val=0;
};
node vert[MAXN];
vector<int> G[MAXN];
int idx=0;
void make_edge(int &a,int &b){
	G[a].pb(b);
	G[b].pb(a);
}
void make_hor(int a,int b){
	if(vert[a].type==0||vert[b].type==0) return;
	if(vert[a].type==1&&vert[b].type==1){make_edge(a,b); return;}
	if(vert[a].type==1&&vert[b].type==4){make_hor(a,vert[b].LG); make_hor(a,vert[b].LD);}
	if(vert[a].type==4&&vert[b].type==1){make_hor(vert[a].PG,b); make_hor(vert[a].PD,b);}
	if(vert[a].type==4&&vert[b].type==4){make_hor(vert[a].PG,vert[b].LG); make_hor(vert[a].PD,vert[b].LD);}
}
void make_ver(int a,int b){
	if(vert[a].type==0||vert[b].type==0) return;
	if(vert[a].type==1&&vert[b].type==1){make_edge(a,b); return;}
	if(vert[a].type==1&&vert[b].type==4){make_ver(a,vert[b].LG); make_ver(a,vert[b].PG);}
	if(vert[a].type==4&&vert[b].type==1){make_ver(vert[a].LD,b); make_ver(vert[a].PD,b);}
	if(vert[a].type==4&&vert[b].type==4){make_ver(vert[a].LD,vert[b].LG); make_ver(vert[a].PD,vert[b].PG);}
}
void make_inner(int v){
	if(vert[v].type<2) return;
	make_inner(vert[v].LG);
	make_inner(vert[v].PG);
	make_inner(vert[v].LD);
	make_inner(vert[v].PD);
	make_hor(vert[v].LG,vert[v].PG);
	make_hor(vert[v].LD,vert[v].PD);
	make_ver(vert[v].LG,vert[v].LD);
	make_ver(vert[v].PG,vert[v].PD);
}
int get_node(int lvl){
	char c; cin>>c;
	int x=c-'0';
	if(x<2){
		vert[++idx]={x,-1,-1,-1,-1,lvl};
		return idx;
	}
	//lg,pg,ld,pd
	int Lg=get_node(lvl-1);
	int Pg=get_node(lvl-1);
	int Ld=get_node(lvl-1);
	int Pd=get_node(lvl-1);
	vert[++idx]={x,Lg,Pg,Ld,Pd,lvl};
	return idx;
}
bool visited[MAXN];
set<int> curr_best;
set<int> amount;
void DFS(int x){
	visited[x]=1;
	if(vert[x].type==1){
		int val=vert[x].val*2;
		while(amount.find(val)!=amount.end()){
			amount.erase(val);
			++val;
		}
		if(amount.find(val)==amount.end()) amount.insert(val);
	}
	for(int &v:G[x]) if(!visited[v]) DFS(v);
}
int mod_pow(int exp){
	ll curr=1,base=2;
	for(int i=0;i<31;++i){
		if((1<<i)&exp) (curr*=base)%=MOD;
		(base*=base)%=MOD;
	}
	return curr;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int m; cin>>m;
	make_inner(get_node(m));
	int ans=0;
	for(int i=1;i<=idx;++i){
		if(!visited[i]&&vert[i].type==1){
			amount.clear();
			DFS(i);
			vector<int> tmp1,tmp2;
			for(int v:amount) tmp1.pb(v);
			for(int v:curr_best) tmp2.pb(v);
			reverse(tmp1.begin(),tmp1.end());
			reverse(tmp2.begin(),tmp2.end());
			if(tmp1>tmp2) curr_best=amount;
			++ans;
		}
	}
	cout<<ans<<"\n";
	int total=0;
	for(int v:curr_best){
		total+=mod_pow(v);
		if(total>=MOD) total-=MOD;
	}
	cout<<total<<"\n";
}
