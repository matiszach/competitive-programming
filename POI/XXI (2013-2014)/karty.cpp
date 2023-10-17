//Task statement: szkopul.edu.pl/problemset/problem/EHW4BOJee7VD-R9MaDAokZ6O/site/
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
const int MAXN=2e5+7,nTree=(1<<18);
pii arr[nTree<<1];
struct node{
	bool LL,LR,RL,RR;
	pii L,R;
	node(){
		return;
	}
	node(bool _LL,bool _LR,bool _RL,bool _RR,pii _L,pii _R){
		LL=_LL; LR=_LR; RL=_RL; RR=_RR;
		L=_L; R=_R;
	}
};
node T[nTree<<1];
void merge(int v){
	//LL
	bool LL=(T[v*2].LL&&T[v*2].R.first<=T[v*2+1].L.first&&T[v*2+1].LL);
	LL|=(T[v*2].LL&&T[v*2].R.first<=T[v*2+1].L.second&&T[v*2+1].RL);
	LL|=(T[v*2].LR&&T[v*2].R.second<=T[v*2+1].L.first&&T[v*2+1].LL);
	LL|=(T[v*2].LR&&T[v*2].R.second<=T[v*2+1].L.second&&T[v*2+1].RL);
	//LR
	bool LR=(T[v*2].LL&&T[v*2].R.first<=T[v*2+1].L.first&&T[v*2+1].LR);
	LR|=(T[v*2].LL&&T[v*2].R.first<=T[v*2+1].L.second&&T[v*2+1].RR);
	LR|=(T[v*2].LR&&T[v*2].R.second<=T[v*2+1].L.first&&T[v*2+1].LR);
	LR|=(T[v*2].LR&&T[v*2].R.second<=T[v*2+1].L.second&&T[v*2+1].RR);
	//RL
	bool RL=(T[v*2].RL&&T[v*2].R.first<=T[v*2+1].L.first&&T[v*2+1].LL);
	RL|=(T[v*2].RL&&T[v*2].R.first<=T[v*2+1].L.second&&T[v*2+1].RL);
	RL|=(T[v*2].RR&&T[v*2].R.second<=T[v*2+1].L.first&&T[v*2+1].LL);
	RL|=(T[v*2].RR&&T[v*2].R.second<=T[v*2+1].L.second&&T[v*2+1].RL);
	//RR
	bool RR=(T[v*2].RL&&T[v*2].R.first<=T[v*2+1].L.first&&T[v*2+1].LR);
	RR|=(T[v*2].RL&&T[v*2].R.first<=T[v*2+1].L.second&&T[v*2+1].RR);
	RR|=(T[v*2].RR&&T[v*2].R.second<=T[v*2+1].L.first&&T[v*2+1].LR);
	RR|=(T[v*2].RR&&T[v*2].R.second<=T[v*2+1].L.second&&T[v*2+1].RR);
	T[v]={LL,LR,RL,RR,T[v*2].L,T[v*2+1].R};
}
int n;
void build(int v){
	if(v>=nTree){
		if(v-nTree>n){
			T[v]={1,1,1,1,{INF,INF},{INF,INF}};
			return;
		}
		if(v-nTree==0){
			T[v]={1,1,1,1,{-INF,-INF},{-INF,-INF}};
			return;
		}
		T[v]=node(1,1,arr[v-nTree].first==arr[v-nTree].second,1,arr[v-nTree],arr[v-nTree]);
		return;
	}
	build(v*2); build(v*2+1);
	merge(v);
}
void update(int pos,pii val){
	pos+=nTree;
	T[pos]={1,1,val.first==val.second,1,val,val};
	pos>>=1;
	while(pos>0){
		merge(pos);
		pos>>=1;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int a,b; cin>>a>>b;
		if(a>b) swap(a,b);
		arr[i]={a,b};
	}
	build(1);
	int q; cin>>q;
	for(int i=1;i<=q;++i){
		int a,b; cin>>a>>b;
		update(a,arr[b]);
		update(b,arr[a]);
		swap(arr[a],arr[b]);
		if(T[1].LR) cout<<"TAK\n";
		else cout<<"NIE\n";
	}
}
