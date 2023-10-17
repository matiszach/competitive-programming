//Task statement: szkopul.edu.pl/problemset/problem/mSKiDD4jrokeNO__pazg6BaF/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=1e6+7;
ll n,k,z;
ll x_pos;
struct interval{
	ll d,x,c;
};
bool cmp(interval a,interval b){
	if(a.d<b.d) return 1;
	else if(a.d>b.d) return 0;
	else return a.x>b.x;
}
vector<interval> inters;
pair<ll,ll> arr[SIZE];
ll ans[SIZE];
ll NWD(ll a,ll b){
	while(a>0){
		ll temp=a;
		a=b%a;
		b=temp;
	}
	return b;
}
queue<interval> q;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>z;
	ll X=1073741824;
	ll prev_pos=0;
	cin>>prev_pos;
	for(int i=1;i<n;++i){
		cin>>x_pos;
		inters.push_back({(x_pos-prev_pos)*X,prev_pos*X,1});
		prev_pos=x_pos;
	}
	sort(inters.begin(),inters.end(),cmp);
	for(int i=1;i<=z;++i){
		cin>>k;
		arr[i]={k,i};
	}
	arr[z+1]={INT_MAX,-1};
	sort(arr+1,arr+1+z);
	ll curr=0,idx=1;
	while(idx<=z){
		interval segm;
		if(!inters.empty()&&!q.empty()){
			if(inters.back().d>q.front().d){
				segm=inters.back();
				inters.pop_back();
			}else if(inters.back().d<q.front().d){
				segm=q.front();
				q.pop();
			}else{
				if(inters.back().x<q.front().x){
					segm=inters.back();
				    inters.pop_back();
				}else{
					segm=q.front();
					q.pop();
				}
			}
		}else if(inters.empty()){
			segm=q.front();
			q.pop();
		}else{
			segm=inters.back();
			inters.pop_back();
		}
		while(curr+segm.c>=arr[idx].first&&idx<=z){
			ans[arr[idx].second]=segm.x+segm.d*(arr[idx].first-curr)-segm.d/2;
			++idx;
		}
		curr+=segm.c;
		q.push({segm.d/2,segm.x,segm.c*2});
	}
	for(int i=1;i<=z;++i){
		ll div=NWD(ans[i],X);
		ans[i]/=div;
		ll den=X/div;
		cout<<ans[i]<<"/"<<den<<"\n";
	}
}
