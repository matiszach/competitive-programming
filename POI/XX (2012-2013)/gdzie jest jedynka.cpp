//Task statement: szkopul.edu.pl/problemset/problem/2TMZ0x-MC86QBBwLrqDfUVVd/site/
//*Author Mateusz Kowalski*
#include "cgdzlib.h"
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
int n;
bool check(int x){
	for(int i=2;i<=n;++i){
		if(f(1,i,x)) return 1;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	n=inicjuj();
	if(n==1){
		odpowiedz(1);
		return 0;
	}
	int l=1,r=n-1,mid=0;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	int pos=0;
	for(int i=2;i<=n;++i){
		if(f(1,i,l)){
			pos=i;
			break;
		}
	}
	int pos2=0;
	for(int i=1;i<=n;++i){
		if(i==pos) continue;
		if(f(pos,i,n-1)){
			pos2=i;
			break;
		}
	}
	if(g(pos,pos2)) swap(pos,pos2);
	odpowiedz(pos);
}
