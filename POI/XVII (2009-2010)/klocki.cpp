//Task statement: szkopul.edu.pl/problemset/problem/0Zmxq4x0eoOFjuX1-BEK9-qA/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=1e6+7;
typedef long long ll;
int n,m;
int k;
int arr[SIZE];
ll tmp[SIZE],pref[SIZE];
vector<pair<ll,int> > mins,maxs;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>arr[i];
	while(m--){
		cin>>k;
		for(int i=1;i<=n;++i) tmp[i]=arr[i]-k;
		for(int i=1;i<=n;++i) pref[i]=pref[i-1]+tmp[i];
		for(int i=0;i<=n;++i){
			if(mins.empty()||(!mins.empty()&&mins.back().first>pref[i])) mins.push_back({pref[i],i});
		}
		for(int i=n;i>=1;--i){
			if(maxs.empty()||(!maxs.empty()&&maxs.back().first<pref[i])) maxs.push_back({pref[i],i});
		}
		int ans=0,j=maxs.size()-1;
		for(int i=0;i<mins.size();++i){
			while(j>=0&&maxs[j].first-mins[i].first>=0){
				ans=max(ans,maxs[j].second-mins[i].second);
				--j;
			}
		}
		mins.clear();
		maxs.clear();
		cout<<ans<<" ";
	}
}
