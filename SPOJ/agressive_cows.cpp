// Task statement: https://www.spoj.com/problems/AGGRCOW/
// *Author Mateusz Kowalski*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const int INF=1e9+7;
#define pb push_back
const int SIZE=1e5+7;
int n,c;
int arr[SIZE];
bool check(int x){
	int cows=c;
	int last=-INF;
	for(int i=1;i<=n;++i){
		if(arr[i]-last>=x){
			last=arr[i];
			--cows;
		}
	}
	return (cows<=0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	while(t--){
		cin>>n>>c;
		for(int i=1;i<=n;++i) cin>>arr[i];
		sort(arr+1,arr+n+1);
		int l=0,r=1e9,mid=(l+r)>>1;
		while(l<=r){
			if(check(mid)) l=mid+1;
			else r=mid-1;
			mid=(l+r)>>1;
		}
		cout<<l-1<<"\n";
	}	
}
