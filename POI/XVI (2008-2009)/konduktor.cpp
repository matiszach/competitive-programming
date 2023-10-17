//Task statement: szkopul.edu.pl/problemset/problem/lbADmW7d353d0F0iw4kXTjsl/site/
//*Author Mateusz Kowalski*
#include <bits/stdc++.h>
using namespace std;
const int SIZE=6e2+7,K=51;
int n,k;
int arr[SIZE][SIZE],pref[SIZE][SIZE];
int dp[SIZE][K],prev_val[SIZE][K];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+arr[i][j];
		}
	}
	for(int i=1;i<n;++i) dp[i][1]=pref[i][n]-pref[i][i];
	int ans=0,station=0;
	for(int j=2;j<=k;++j){
		for(int i=1;i<n;++i){
			int best=0;
			for(int l=1;l<i;++l){
				int val=dp[l][j-1]+pref[i][n]-pref[l-1+1][n]-pref[i][i]+pref[l-1+1][i];
				if(val>best){
					prev_val[i][j]=l;
					best=val;
				}
			}
			dp[i][j]=max(best,dp[i][j-1]);
		}
	}
	for(int i=k;i<n;++i){
		if(dp[i][k]>ans){
			ans=dp[i][k];
			station=i;
		}
	}
    set<int> stations;
	int needed=0;
	for(int i=1;i<=k;++i){
		stations.insert(station);
		station=prev_val[station][k-i+1];
		if(station==0){
			needed=k-i;
			break;
		}
	}
	int idx=1;
	while(needed>0){
		if(stations.find(idx)==stations.end()){
			stations.insert(idx);
			--needed;
		}
		++idx;
	}
	for(int v:stations) cout<<v<<" ";
	cout<<"\n";
}
