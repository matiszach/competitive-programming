//Task statement: szkopul.edu.pl/problemset/problem/O8s92dZUIyVOtzxC0mdMS-xf/site/
//*Author Mateusz Kowalski*
#include "zerlib.h"
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
int main()
{
	ios_base::sync_with_stdio(0);
	int n=daj_n();
	int st=0;
	int same=0;
	vector<int> res(n);
	for(int i=1;i<n;++i){
		int x=suma(0,i);
		if(x==0) break;
		if(x==2){
			res[i]=1;
			st=1;
			break;
		}
		if(x==1){
			++same;
		}
	}
	for(int i=same+2;i<n;++i){
		res[i]=suma(0,i)-st;
	}
	int x=0;
	if(same==n-1){
		x=suma(1,2);
		if(x==0){
			st=1;
			x=0;
		}else{
			st=0;
			x=1;
		}
	}else{
		x=suma(0,1)-st;
	}
	for(int i=1;i<=same;++i) res[i]=x;
	res[0]=st;
	odpowiedz(res);
}
