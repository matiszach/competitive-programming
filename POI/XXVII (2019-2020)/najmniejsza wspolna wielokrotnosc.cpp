//Task statement: szkopul.edu.pl/problemset/problem/nYCgpBEkq_hw9S-QaoEOOKCI/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=1e6+3e5;
const ll INF=1e18+7;
ll NWD(ll a,ll b){
	while(a>0){
		ll temp=a;
		a=b%a;
		b=temp;
	}
	return b;
}
int z;
ll m;
map<ll,pair<int,int> > computed;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>z;
	ll curr=0,x=0;
	int counter=0;
	for(ll i=1;i<SIZE;++i){
		x=NWD(i,i+1);
		curr=(i/x)*(i+1);
		ll j=i+1;
		while(1){
			++j;
			x=NWD(curr,j);
		    	if((j/x)>(INF/curr)) break;
		    	curr=(curr/x)*j;
			if(computed.find(curr)==computed.end()){
				computed[curr]={i,j};
			}
		}
	}
	while(z--){
		cin>>m;
		if(computed.find(m)!=computed.end()) cout<<computed[m].first<<" "<<computed[m].second<<"\n";
		else{
			ll val=sqrt(m);
			if(val*(val+1)==m) cout<<val<<" "<<val+1<<"\n";
			else if((val-1)*val==m) cout<<val-1<<" "<<val<<"\n";
			else cout<<"NIE\n";
		}
	}
}
