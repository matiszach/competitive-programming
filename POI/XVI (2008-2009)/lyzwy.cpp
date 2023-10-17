//Task statement: szkopul.edu.pl/problemset/problem/kadKFW3YScAMW8o20u0BctQh/site/
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
const int nTree=(1<<18);
int n,m,k,d,x,y;
ll psom[nTree<<1],pref[nTree<<1],suf[nTree<<1],sums[nTree<<1];
void init(int v){
	if(v>=nTree){
		sums[v]=-k;
		return;
	}
	init(v*2);
	init(v*2+1);
	sums[v]=sums[v*2]+sums[v*2+1];
	psom[v]=max(suf[v*2]+pref[v*2+1],max(psom[v*2],psom[v*2+1]));
}
void update(int pos,int val){
	pos+=nTree;
	sums[pos]+=val;
	psom[pos]=max(0LL,sums[pos]);
	pos>>=1;
	while(pos>0){
		sums[pos]=sums[pos*2]+sums[pos*2+1];
		pref[pos]=max(pref[pos*2],sums[pos*2]+pref[pos*2+1]);
		suf[pos]=max(suf[pos*2+1],sums[pos*2+1]+suf[pos*2]);
		psom[pos]=max(pref[pos*2+1]+suf[pos*2],max(psom[pos*2],psom[pos*2+1]));
		pos>>=1;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k>>d;
	init(1);
	for(int i=1;i<=m;++i){
		cin>>x>>y;
		update(x,y);
		cout<<(psom[1]<=(ll)k*d?"TAK":"NIE")<<"\n";
	}
}
