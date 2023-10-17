//Task statement: szkopul.edu.pl/problemset/problem/kQ5ExYNkFhx3K2FvVuXAAbn4/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+7,A=25e5+7;
int cnt[A*2];
int arr[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	int total=0;
	for(int i=1;i<=n;++i) total+=arr[i];
	int pos=0;
	for(int i=1;i<=n;++i) if(arr[pos]<arr[i]) pos=i;
	for(int i=1;i<=n;++i) if(i!=pos) ++cnt[arr[i]];
	bitset<A> dp;
	dp[0]=1;
	for(int i=1;i<A;++i){
		int x=cnt[i];
		for(int j=0;(1<<j)<=x;++j){
			dp|=(dp<<(i*(1<<j)));
			x-=(1<<j);
		}
		if(x) dp|=(dp<<(i*x));
	}
	int d=arr[pos];
	int ans=0;
	for(int j=0;j<=(total-d)/2;++j){
		if(dp[j]){
			if(j+d<total-d-j) continue;
			ans=max(ans,j+d);
		}
	}
	cout<<ans<<"\n";
}
