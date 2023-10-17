//Task statement: szkopul.edu.pl/problemset/problem/_4AAMIim7XilS6G_v6zD-Vsh/site/
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
const int NAX=207;
ll n;
ll fib[NAX];
int ans=INF;
int counter=0;
void factor(ll x,int last_idx,int curr_sum,int curr){
	++counter;
	if(x==1){
		ans=min(ans,curr_sum+curr-1);
		return;
	}
	bool ok=0;
	for(int i=last_idx;i>=2;--i){
		if(x%fib[i]==0){
			ok=1;
			factor(x/fib[i],i,curr_sum+i,curr+1);
		}
	}
	if(!ok) return;
}
ll NWD(ll a,ll b){
	ll buf;
	while(a!=0){
		buf=a;
		a=b%a;
		b=buf;
	}
	return b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	fib[0]=1;
	fib[1]=1;
	int idx=0;
	for(int i=2;i<NAX;++i){
		if(fib[i-1]>n){
			idx=i-2;
			break;
		}
		fib[i]=fib[i-1]+fib[i-2];
	}
	factor(n,idx,0,0);
	if(ans==INF) cout<<"NIE\n";
	else cout<<ans<<"\n";
}
