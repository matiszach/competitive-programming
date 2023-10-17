//Task statement: szkopul.edu.pl/problemset/problem/rr3lU0T8pNn2mAbL07wBTZT3/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=3e5+5;
int n;
typedef long long ll;
ll arr[3][SIZE];
ll cost[3][SIZE];
ll best[3][3];
pair<ll,int> a[SIZE],b[SIZE],c[SIZE];
ll val=0;
bool x,y,z;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
		if(arr[0][i]>0) x=1;
		if(arr[1][i]>0) y=1;
		if(arr[2][i]>0) z=1;
		ll biggest=0;
		for(int j=0;j<3;++j) biggest=max(biggest,arr[j][i]);
		for(int j=0;j<3;++j) cost[j][i]=biggest-arr[j][i];
		a[i]={cost[0][i],i};
		b[i]={cost[1][i],i};
		c[i]={cost[2][i],i};
		val+=(arr[0][i]+arr[1][i]+arr[2][i]-biggest);
	}
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	ll diff=1e18+1;
	if(x&&y&&z){
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				if(a[i].second==b[j].second) continue;
				for(int k=0;k<3;++k){
					if(a[i].second==c[k].second||b[j].second==c[k].second) continue;
					diff=min(diff,a[i].first+b[j].first+c[k].first);
				}
			}
		}
	}
	else if(x&&y&&!z){
		for(int j=0;j<2;++j){
			for(int k=0;k<2;++k){
				if(a[j].second==b[k].second) continue;
				diff=min(diff,a[j].first+b[k].first);
			}
		}
	}
	else if(x&&!y&&z){
		for(int j=0;j<2;++j){
			for(int k=0;k<2;++k){
				if(a[j].second==c[k].second) continue;
				diff=min(diff,a[j].first+c[k].first);
			}
		}
	}
	else if(!x&&y&&z){
		for(int j=0;j<2;++j){
			for(int k=0;k<2;++k){
				if(c[j].second==b[k].second) continue;
				diff=min(diff,c[j].first+b[k].first);
			}
		}
	}
	else diff=0;
	cout<<val+diff<<"\n";
}
