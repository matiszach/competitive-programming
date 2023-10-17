//Task statement: szkopul.edu.pl/problemset/problem/7feyJYY7uz_g6iGLS_QPwJVG/site/
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
const int MAXN=1e5;
ll F[11][MAXN+1];
int m;
void add(int idx,int v,int val){
	for(;v<=MAXN;v+=(v&(-v))) F[idx][v]+=val;
}
ll get(int idx,int v){
	ll res=0;
	for(;v>0;v-=(v&(-v))) res+=F[idx][v];
	return res;
}
ll query(int idx,int l,int r){
	return get(idx,r)-get(idx,l-1);
}
int curr;
void inicjuj(int M){
	m=M;
}
void dodaj(int k){
	++curr;
	int tmp=curr/MAXN-(curr%MAXN==0?1:0);
	add(tmp,curr-tmp*MAXN,k);
	if(curr==m+MAXN){
		for(int i=0;i<10;++i){
			for(int j=0;j<=MAXN;++j) F[i][j]=F[i+1][j];
		}
		for(int j=0;j<=MAXN;++j) F[10][j]=0;
		curr-=MAXN;
	}
}
void koryguj(int i,int k){
	int tmp=curr-i+1;
	tmp=tmp/MAXN-(tmp%MAXN==0?1:0);
	add(tmp,(curr-i+1)-tmp*MAXN,k);
}
ll suma(int i){
	int l=max(1,curr-i+1),r=curr;
	ll res=0;
	for(int j=0;j<11;++j){
		int L=j*MAXN+1,R=MAXN*(j+1);
		L=max(L,l); R=min(R,r);
		if(L>R) continue;
		res+=query(j,L-j*MAXN,R-j*MAXN);
	}
	return res;
}
//~ int main()
//~ {
	//~ ios_base::sync_with_stdio(0);
	//~ inicjuj(3);
	//~ dodaj(-6);
	//~ cout<<suma(1)<<"\n";
	//~ dodaj(5);
	//~ koryguj(2,10);
	//~ cout<<suma(3)<<"\n";
	//~ cout<<suma(1)<<"\n";
//~ }
