//Task statement: szkopul.edu.pl/problemset/problem/07Q0fFk7fU2TmGr6wpPeDCZj/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=2e6+5;
typedef long long ll;
deque<pair<ll,int> > maxq;
void addmaxq(ll val,int index){
	while(!maxq.empty()&&maxq.back().first<=val) maxq.pop_back();
	maxq.push_back({val,index});
}
void removemaxq(int index){
	if(!maxq.empty()&&maxq.front().second<=index) maxq.pop_front();
}
ll getmaxq(){
	if(!maxq.empty()) return maxq.front().first;
	else return 0;
}
ll n,d,x;
ll p;
ll arr[SIZE],intervals[SIZE];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>p>>d;
	for(int i=1;i<=n;++i){
		cin>>x;
		arr[i]=arr[i-1]+x;
	}
	for(int i=1;i<=n-d+1;++i) intervals[i]=arr[i+d-1]-arr[i-1];
	addmaxq(intervals[1],1);
	int j=d;
	int best=d;
	for(int i=1;i<=n-d+1;++i){
		while(j+1<=n&&arr[j+1]-arr[i-1]-max(getmaxq(),intervals[j-d+2])<=p){
			addmaxq(intervals[j-d+2],j-d+2);
			++j;
		}
		removemaxq(i);
		best=max(best,j-i+1);
	}
	cout<<best<<"\n";
}
