//Task statement: szkopul.edu.pl/problemset/problem/k4iPPyQbhkKRE3kLi6zjUbWz/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include "gralib.hpp"
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
typedef long double ld;
const int NAX=3e5+7;
ld ex[NAX];
ld optimal[NAX];
int dx[NAX];
int n,k,m;
bool calc[NAX];
ld getex(int x){
	if(calc[x]) return ex[x];
	vector<ld> pot;
	for(int i=x+1;i<=min(x+k,n);++i){
		if(x%(i-x)==0) pot.pb(getex(i));
	}
	sort(pot.begin(),pot.end());
	ld curr=k,best=INFLL;
	int cnt=0;
	for(ld v:pot){
		if((curr+v)/(ld)(cnt+1)>best){
			break;
		}
		curr+=v;
		++cnt;
		best=curr/(ld)cnt;
	}
	optimal[x]=best;
	calc[x]=1;
	ex[x]=best;
	return ex[x];
}
int main()
{
	ios_base::sync_with_stdio(0);
	n=dajN(); k=dajK(); m=dajM();
	calc[n]=1;
	ld xd=getex(0);
	for(int i=1;i<=100;++i){
		int curr=0,moves=0;
		while(curr<n){
			int x=nastepna();
			if(curr+x<=n&&curr%x==0&&ex[curr+x]<=optimal[curr]){
				zwieksz();
				curr+=x;
			}
		}
		koniec();
	}
}
