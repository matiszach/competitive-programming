//Task statement: szkopul.edu.pl/problemset/problem/cSnlafnvkbirhnQrS9CQ9MEw/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18+7;
const int SIZE=1e6+7;
ll b,q,x;
int arr[SIZE];
vector<pair<ll,int> > pref;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>b>>q;
	for(int i=0;i<b;++i) cin>>arr[i];
	ll total=0;
	for(int i=0;i<b;++i) total+=(ll)arr[i]*(ll)i;
	if(total%(b-1)!=0) --arr[total%(b-1)];
	ll curr=0;
	for(int i=0;i<b;++i){
		if(arr[i]>0)
		pref.push_back({curr+=arr[i],i});
	}
	pref.push_back({INF,-1});
	while(q--){
		cin>>x;
		pair<ll,int> p={x+1,0};
		vector<pair<ll,int> >::iterator it;
		it=lower_bound(pref.begin(),pref.end(),p);
		cout<<(*it).second<<"\n";
	}
}
