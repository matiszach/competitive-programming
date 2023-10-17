//Task statement: szkopul.edu.pl/problemset/problem/UUJOY-zNg3myEsDzzBmvdMKT/site/
//*Author Mateusz Kowalski*
#include<bits/stdc++.h>
#include "arc.h"
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
int x;
deque<int> Q;
int main()
{
	ios_base::sync_with_stdio(0);
	int k;
	k=inicjuj();
	queue<int> tmp;
	bool all=0;
	while(1){
		while((int)tmp.size()<k&&!all){
			x=wczytaj();
			if(x==0){
				all=1;
				break;
			}
			tmp.push(x);
		}
		if(tmp.empty()&&all) break;
		if(Q.empty()) Q.push_back(tmp.front());
		else{
			int val=tmp.front();
			while(!Q.empty()&&min(Q.front(),Q.back())<val&&k-Q.size()+1<=tmp.size()){
				if(Q.front()<Q.back()) Q.pop_front();
				else Q.pop_back();
			}
			if((int)Q.size()<k) Q.push_back(val);
		}
		tmp.pop();
	}
    for(int v:Q) wypisz(v);
}
